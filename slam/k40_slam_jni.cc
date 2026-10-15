// JNI bridge between the K40 sensor app and ORB-SLAM3.
// Frames and IMU samples are fed straight into the SLAM system in-process;
// nothing is routed through DDS. All timestamps are elapsed realtime seconds.
#include <jni.h>
#include <android/log.h>

#include <algorithm>
#include <cstdio>
#include <mutex>
#include <string>
#include <vector>

#include <opencv2/core/core.hpp>
#include <sophus/se3.hpp>

#include "System.h"
#include "ImuTypes.h"

#define LOG_TAG "k40_slam"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

namespace {

std::mutex g_mutex;
ORB_SLAM3::System *g_slam = nullptr;
std::vector<ORB_SLAM3::IMU::Point> g_imu;
Sophus::SE3f g_pose;
int g_state = -1;
bool g_poseValid = false;
double g_lastImageTime = 0.0;

const char *StateText(int state) {
  switch (state) {
    case -1: return "SYSTEM_NOT_READY";
    case 0: return "NO_IMAGES_YET";
    case 1: return "NOT_INITIALIZED";
    case 2: return "OK";
    case 3: return "RECENTLY_LOST";
    case 4: return "LOST";
    case 5: return "OK_KLT";
    default: return "UNKNOWN";
  }
}

}  // namespace

extern "C" {

JNIEXPORT jboolean JNICALL
Java_net_moefire_slam_monitor_SlamNativeBridge_nativeInit(JNIEnv *env, jclass,
    jstring vocabPath, jstring settingsPath, jboolean useImu) {
  const char *vocab = env->GetStringUTFChars(vocabPath, nullptr);
  const char *settings = env->GetStringUTFChars(settingsPath, nullptr);
  if (!vocab || !settings) {
    if (vocab) env->ReleaseStringUTFChars(vocabPath, vocab);
    if (settings) env->ReleaseStringUTFChars(settingsPath, settings);
    return JNI_FALSE;
  }

  std::lock_guard<std::mutex> lock(g_mutex);
  if (g_slam) {
    g_slam->Shutdown();
    delete g_slam;
    g_slam = nullptr;
  }
  g_imu.clear();
  g_poseValid = false;
  g_state = -1;
  g_lastImageTime = 0.0;

  const ORB_SLAM3::System::eSensor sensor =
      useImu == JNI_TRUE ? ORB_SLAM3::System::IMU_MONOCULAR : ORB_SLAM3::System::MONOCULAR;

  try {
    g_slam = new ORB_SLAM3::System(std::string(vocab), std::string(settings), sensor, false);
  } catch (const std::exception &e) {
    LOGE("init failed: %s", e.what());
    g_slam = nullptr;
  } catch (...) {
    LOGE("init failed with unknown error");
    g_slam = nullptr;
  }

  env->ReleaseStringUTFChars(vocabPath, vocab);
  env->ReleaseStringUTFChars(settingsPath, settings);
  if (g_slam) LOGI("ORB-SLAM3 started, sensor=%s", useImu == JNI_TRUE ? "IMU_MONOCULAR" : "MONOCULAR");
  return g_slam ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT void JNICALL
Java_net_moefire_slam_monitor_SlamNativeBridge_nativeShutdown(JNIEnv *, jclass) {
  std::lock_guard<std::mutex> lock(g_mutex);
  if (!g_slam) return;
  g_slam->Shutdown();
  delete g_slam;
  g_slam = nullptr;
  g_imu.clear();
  g_poseValid = false;
  g_state = -1;
  LOGI("ORB-SLAM3 stopped");
}

JNIEXPORT void JNICALL
Java_net_moefire_slam_monitor_SlamNativeBridge_nativeReset(JNIEnv *, jclass) {
  std::lock_guard<std::mutex> lock(g_mutex);
  if (!g_slam) return;
  g_slam->Reset();
  g_imu.clear();
  g_poseValid = false;
}

JNIEXPORT void JNICALL
Java_net_moefire_slam_monitor_SlamNativeBridge_nativePushImu(JNIEnv *, jclass,
    jlong timestampNs, jfloat ax, jfloat ay, jfloat az,
    jfloat gx, jfloat gy, jfloat gz) {
  std::lock_guard<std::mutex> lock(g_mutex);
  if (!g_slam) return;
  const double t = static_cast<double>(timestampNs) * 1e-9;
  if (t < g_lastImageTime) return;  // Sample belongs to an interval already consumed.
  g_imu.emplace_back(cv::Point3f(ax, ay, az), cv::Point3f(gx, gy, gz), t);
  if (g_imu.size() > 2000) g_imu.erase(g_imu.begin(), g_imu.begin() + 1000);
}

JNIEXPORT jboolean JNICALL
Java_net_moefire_slam_monitor_SlamNativeBridge_nativeTrackGray(JNIEnv *env, jclass,
    jlong timestampNs, jint width, jint height, jbyteArray pixels) {
  ORB_SLAM3::System *slam = nullptr;
  {
    std::lock_guard<std::mutex> lock(g_mutex);
    slam = g_slam;
  }
  if (!slam || !pixels) return JNI_FALSE;

  const double t = static_cast<double>(timestampNs) * 1e-9;
  const jsize count = env->GetArrayLength(pixels);
  if (count < width * height) return JNI_FALSE;

  std::vector<uchar> buffer(static_cast<size_t>(width) * static_cast<size_t>(height));
  env->GetByteArrayRegion(pixels, 0, buffer.size(), reinterpret_cast<jbyte *>(buffer.data()));
  if (env->ExceptionCheck()) return JNI_FALSE;

  cv::Mat gray(height, width, CV_8UC1, buffer.data());

  std::vector<ORB_SLAM3::IMU::Point> measurements;
  {
    std::lock_guard<std::mutex> lock(g_mutex);
    for (auto it = g_imu.begin(); it != g_imu.end();) {
      if (it->t <= t) {
        measurements.push_back(*it);
        it = g_imu.erase(it);
      } else {
        ++it;
      }
    }
  }

  Sophus::SE3f pose;
  int state = -1;
  try {
    pose = slam->TrackMonocular(gray, t, measurements);
    state = slam->GetTrackingState();
  } catch (const std::exception &e) {
    LOGE("track failed: %s", e.what());
    return JNI_FALSE;
  } catch (...) {
    LOGE("track failed with unknown error");
    return JNI_FALSE;
  }

  std::lock_guard<std::mutex> lock(g_mutex);
  g_pose = pose;
  g_poseValid = true;
  g_state = state;
  g_lastImageTime = t;
  return JNI_TRUE;
}

// out receives Tcw as a row-major 4x4 matrix; returns the tracking state.
JNIEXPORT jint JNICALL
Java_net_moefire_slam_monitor_SlamNativeBridge_nativeGetPose(JNIEnv *env, jclass, jfloatArray out) {
  std::lock_guard<std::mutex> lock(g_mutex);
  if (!g_slam || !g_poseValid) return -1;
  if (out) {
    const jsize len = env->GetArrayLength(out);
    if (len >= 16) {
      const Eigen::Matrix4f m = g_pose.matrix();
      jfloat values[16];
      for (int r = 0; r < 4; ++r)
        for (int c = 0; c < 4; ++c)
          values[r * 4 + c] = m(r, c);
      env->SetFloatArrayRegion(out, 0, 16, values);
    }
  }
  return g_state;
}

// out receives xyz triples of the map points tracked in the current frame.
JNIEXPORT jint JNICALL
Java_net_moefire_slam_monitor_SlamNativeBridge_nativeGetMapPoints(JNIEnv *env, jclass,
    jfloatArray out) {
  ORB_SLAM3::System *slam = nullptr;
  {
    std::lock_guard<std::mutex> lock(g_mutex);
    slam = g_slam;
  }
  if (!slam || !out) return 0;

  std::vector<ORB_SLAM3::MapPoint *> points = slam->GetTrackedMapPoints();
  const jsize capacity = env->GetArrayLength(out) / 3;
  const size_t n = std::min(static_cast<size_t>(capacity), points.size());

  std::vector<jfloat> values;
  values.reserve(n * 3);
  for (size_t i = 0; i < n; ++i) {
    ORB_SLAM3::MapPoint *p = points[i];
    if (!p || p->isBad()) continue;
    const Eigen::Vector3f w = p->GetWorldPos();
    values.push_back(w.x());
    values.push_back(w.y());
    values.push_back(w.z());
  }
  if (!values.empty()) env->SetFloatArrayRegion(out, 0, values.size(), values.data());
  return static_cast<jint>(values.size() / 3);
}

JNIEXPORT jstring JNICALL
Java_net_moefire_slam_monitor_SlamNativeBridge_nativeGetStatusText(JNIEnv *env, jclass) {
  std::lock_guard<std::mutex> lock(g_mutex);
  if (!g_slam) return env->NewStringUTF("SLAM OFF");
  char text[128];
  snprintf(text, sizeof(text), "%s imu=%zu", StateText(g_state), g_imu.size());
  return env->NewStringUTF(text);
}

}  // extern "C"
