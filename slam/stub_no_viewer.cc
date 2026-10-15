// No-op replacements for ORB-SLAM3's desktop viewer pieces.
// ORB-SLAM3's System still constructs and references them, so the symbols must
// exist, but the Android app draws the map itself instead of using Pangolin.
#include "Viewer.h"
#include "MapDrawer.h"

#include <mutex>
#include <string>

namespace ORB_SLAM3 {

MapDrawer::MapDrawer(Atlas *pAtlas, const std::string &strSettingPath, Settings *settings)
    : mpAtlas(pAtlas) {
  (void)strSettingPath;
  (void)settings;
}

void MapDrawer::newParameterLoader(Settings *settings) { (void)settings; }

void MapDrawer::DrawMapPoints() {}

void MapDrawer::DrawKeyFrames(const bool bDrawKF, const bool bDrawGraph,
                             const bool bDrawInertialGraph, const bool bDrawOptLba) {
  (void)bDrawKF;
  (void)bDrawGraph;
  (void)bDrawInertialGraph;
  (void)bDrawOptLba;
}

void MapDrawer::DrawCurrentCamera(pangolin::OpenGlMatrix &Twc) { (void)Twc; }

void MapDrawer::SetCurrentCameraPose(const Sophus::SE3f &Tcw) {
  std::unique_lock<std::mutex> lock(mMutexCamera);
  mCameraPose = Tcw.inverse();
}

void MapDrawer::SetReferenceKeyFrame(KeyFrame *pKF) { (void)pKF; }

void MapDrawer::GetCurrentOpenGLCameraMatrix(pangolin::OpenGlMatrix &M, pangolin::OpenGlMatrix &MOw) {
  (void)M;
  (void)MOw;
}

Viewer::Viewer(System *pSystem, FrameDrawer *pFrameDrawer, MapDrawer *pMapDrawer,
               Tracking *pTracking, const std::string &strSettingPath, Settings *settings)
    : both(false),
      mT(1e3 / 30.0),
      mImageWidth(640),
      mImageHeight(480),
      mImageViewerScale(1.0f),
      mViewpointX(0),
      mViewpointY(-0.7),
      mViewpointZ(-1.8),
      mViewpointF(500),
      mbFinishRequested(false),
      mbFinished(true),
      mbStopped(false),
      mbStopRequested(false),
      mbStopTrack(false),
      mpSystem(pSystem),
      mpFrameDrawer(pFrameDrawer),
      mpMapDrawer(pMapDrawer),
      mpTracker(pTracking) {
  (void)strSettingPath;
  (void)settings;
}

void Viewer::newParameterLoader(Settings *settings) { (void)settings; }

void Viewer::Run() {}

void Viewer::RequestFinish() {
  std::unique_lock<std::mutex> lock(mMutexFinish);
  mbFinishRequested = true;
}

void Viewer::RequestStop() {
  std::unique_lock<std::mutex> lock(mMutexStop);
  mbStopRequested = true;
}

bool Viewer::isFinished() {
  std::unique_lock<std::mutex> lock(mMutexFinish);
  return mbFinished;
}

bool Viewer::isStopped() {
  std::unique_lock<std::mutex> lock(mMutexStop);
  return mbStopped;
}

bool Viewer::isStepByStep() { return false; }

void Viewer::Release() {}

}  // namespace ORB_SLAM3
