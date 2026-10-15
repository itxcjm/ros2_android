#include <jni.h>
#include <android/log.h>
#include <cstdint>
#include <memory>
#include <mutex>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>

namespace {
std::mutex bridge_mutex;
bool started = false;
int64_t wall_base_ns = 0;
int64_t elapsed_base_ns = 0;
std::string status = "ROS 2 not started";
rclcpp::Node::SharedPtr node;
rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_pub;
rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr gyro_pub;
rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr accel_pub;
rclcpp::Publisher<sensor_msgs::msg::NavSatFix>::SharedPtr gps_pub;

builtin_interfaces::msg::Time stamp_from_elapsed(int64_t timestamp_ns) {
  const int64_t ns = wall_base_ns + (timestamp_ns - elapsed_base_ns);
  builtin_interfaces::msg::Time stamp;
  stamp.sec = static_cast<int32_t>(ns / 1000000000LL);
  stamp.nanosec = static_cast<uint32_t>(ns % 1000000000LL);
  return stamp;
}
}  // namespace

extern "C" {

JNIEXPORT jboolean JNICALL
Java_net_moefire_slam_monitor_Ros2NativeBridge_nativeStart(
    JNIEnv *, jobject, jlong wall_ns, jlong elapsed_ns) {
  std::lock_guard<std::mutex> lock(bridge_mutex);
  if (started) return JNI_TRUE;
  try {
    rclcpp::init(0, nullptr);
    node = std::make_shared<rclcpp::Node>("k40_capture");
    auto qos = rclcpp::SensorDataQoS();
    image_pub = node->create_publisher<sensor_msgs::msg::Image>(
        "/slam/camera/image_mono", qos);
    gyro_pub = node->create_publisher<sensor_msgs::msg::Imu>(
        "/slam/imu/gyro_raw", qos);
    accel_pub = node->create_publisher<sensor_msgs::msg::Imu>(
        "/slam/imu/accel_raw", qos);
    gps_pub = node->create_publisher<sensor_msgs::msg::NavSatFix>(
        "/slam/gps/fix", qos);
    wall_base_ns = static_cast<int64_t>(wall_ns);
    elapsed_base_ns = static_cast<int64_t>(elapsed_ns);
    status = "ROS 2 publishers active";
    started = true;
    return JNI_TRUE;
  } catch (const std::exception &e) {
    status = e.what();
    __android_log_print(ANDROID_LOG_ERROR, "K40Ros2", "start failed: %s", e.what());
    image_pub.reset();
    gyro_pub.reset();
    accel_pub.reset();
    gps_pub.reset();
    node.reset();
    if (rclcpp::ok()) rclcpp::shutdown();
    return JNI_FALSE;
  }
}

JNIEXPORT void JNICALL
Java_net_moefire_slam_monitor_Ros2NativeBridge_nativeStop(JNIEnv *, jobject) {
  std::lock_guard<std::mutex> lock(bridge_mutex);
  if (!started) return;
  started = false;
  image_pub.reset();
  gyro_pub.reset();
  accel_pub.reset();
  gps_pub.reset();
  node.reset();
  if (rclcpp::ok()) rclcpp::shutdown();
  status = "ROS 2 stopped";
}

JNIEXPORT jstring JNICALL
Java_net_moefire_slam_monitor_Ros2NativeBridge_nativeStatus(JNIEnv *env, jobject) {
  std::lock_guard<std::mutex> lock(bridge_mutex);
  return env->NewStringUTF(status.c_str());
}

JNIEXPORT void JNICALL
Java_net_moefire_slam_monitor_Ros2NativeBridge_nativePublishGray(
    JNIEnv *env, jobject, jlong timestamp_ns, jint width, jint height,
    jbyteArray pixels) {
  std::lock_guard<std::mutex> lock(bridge_mutex);
  if (!started || !image_pub || !pixels || width <= 0 || height <= 0) return;
  const jsize size = env->GetArrayLength(pixels);
  if (static_cast<int64_t>(size) !=
      static_cast<int64_t>(width) * static_cast<int64_t>(height)) return;
  sensor_msgs::msg::Image message;
  message.header.stamp = stamp_from_elapsed(timestamp_ns);
  message.header.frame_id = "camera_optical_frame";
  message.height = static_cast<uint32_t>(height);
  message.width = static_cast<uint32_t>(width);
  message.encoding = "mono8";
  message.is_bigendian = 0;
  message.step = static_cast<uint32_t>(width);
  message.data.resize(size);
  env->GetByteArrayRegion(
      pixels, 0, size, reinterpret_cast<jbyte *>(message.data.data()));
  if (!env->ExceptionCheck()) image_pub->publish(message);
}

JNIEXPORT void JNICALL
Java_net_moefire_slam_monitor_Ros2NativeBridge_nativePublishGyro(
    JNIEnv *, jobject, jlong timestamp_ns, jfloat x, jfloat y, jfloat z) {
  std::lock_guard<std::mutex> lock(bridge_mutex);
  if (!started || !gyro_pub) return;
  sensor_msgs::msg::Imu message;
  message.header.stamp = stamp_from_elapsed(timestamp_ns);
  message.header.frame_id = "imu_link";
  message.orientation_covariance[0] = -1.0;
  message.linear_acceleration_covariance[0] = -1.0;
  message.angular_velocity.x = x;
  message.angular_velocity.y = y;
  message.angular_velocity.z = z;
  gyro_pub->publish(message);
}

JNIEXPORT void JNICALL
Java_net_moefire_slam_monitor_Ros2NativeBridge_nativePublishAccel(
    JNIEnv *, jobject, jlong timestamp_ns, jfloat x, jfloat y, jfloat z) {
  std::lock_guard<std::mutex> lock(bridge_mutex);
  if (!started || !accel_pub) return;
  sensor_msgs::msg::Imu message;
  message.header.stamp = stamp_from_elapsed(timestamp_ns);
  message.header.frame_id = "imu_link";
  message.orientation_covariance[0] = -1.0;
  message.angular_velocity_covariance[0] = -1.0;
  message.linear_acceleration.x = x;
  message.linear_acceleration.y = y;
  message.linear_acceleration.z = z;
  accel_pub->publish(message);
}

JNIEXPORT void JNICALL
Java_net_moefire_slam_monitor_Ros2NativeBridge_nativePublishGps(
    JNIEnv *, jobject, jlong timestamp_ns, jdouble latitude,
    jdouble longitude, jdouble altitude, jfloat accuracy_m) {
  std::lock_guard<std::mutex> lock(bridge_mutex);
  if (!started || !gps_pub || timestamp_ns <= 0) return;
  sensor_msgs::msg::NavSatFix message;
  message.header.stamp = stamp_from_elapsed(timestamp_ns);
  message.header.frame_id = "gps_link";
  message.status.status = sensor_msgs::msg::NavSatStatus::STATUS_FIX;
  message.status.service = sensor_msgs::msg::NavSatStatus::SERVICE_GPS;
  message.latitude = latitude;
  message.longitude = longitude;
  message.altitude = altitude;
  if (accuracy_m > 0) {
    const double variance = static_cast<double>(accuracy_m) * accuracy_m;
    message.position_covariance[0] = variance;
    message.position_covariance[4] = variance;
    message.position_covariance_type =
        sensor_msgs::msg::NavSatFix::COVARIANCE_TYPE_APPROXIMATED;
  }
  gps_pub->publish(message);
}

}  // extern "C"
