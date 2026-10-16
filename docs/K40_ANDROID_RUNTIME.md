# K40 Android SLAM runtime

This branch provides the native build inputs for the separate Kotlin/Compose K40 capture app. It does not contain that app's source tree.

## Branches

- `main`: upstream ROS 2 Android fork; keep it independent of experiments.
- `codex/minimal-ros2-runtime`: ROS 2 Humble JNI sensor publishers.
- `codex/orbslam3-android`: current native integration branch; includes the ROS 2 runtime changes and the ORB-SLAM3 JNI bridge.
- `codex/android-ci`: earlier generic Android build experiment; not required by the K40 app.
- `ci-orbslam3-log`: historical build diagnostics; not the source of release binaries.

The two K40 workflows are manual-dispatchable. The ORB-SLAM3 workflow also runs on changes to its branch. Native `.so` files are uploaded as short-lived Actions artifacts; the workflows do not commit binaries or logs back to Git.

## Building and consuming the artifact

Run **Build ORB-SLAM3 Android runtime** on `codex/orbslam3-android`. Download `orbslam3-k40-arm64` from the successful run and copy `lib/libk40_slam.so` to the app's `app/src/main/jniLibs/arm64-v8a/`. Run **Build minimal ROS 2 Android runtime** on `codex/minimal-ros2-runtime` for the ROS 2 JNI and dependency libraries. Build the Kotlin app separately with Gradle.

The workflow caches Android SDK packages, OpenCV/Eigen/ORB-SLAM3 dependencies, compiler objects, and native build output. Cache entries accelerate builds but are not release artifacts. The ORB-SLAM3 vocabulary is packaged by the app separately.

## Current runtime behavior

The app feeds grayscale CameraX frames in-process to ORB-SLAM3 in monocular mode. The map, relative-scale trajectory and pose are read from the JNI bridge. ROS 2 publishes IMU and GPS telemetry. Raw camera frames are currently not sent through DDS because image transport was unstable on the K40; SLAM does not depend on DDS image delivery.

Camera intrinsics are estimated from Android camera metadata and lens distortion is currently assumed zero. Camera/IMU extrinsics and noise are not calibrated, so IMU is captured but not fused into ORB-SLAM3. Monocular translation has arbitrary scale; coordinates must not be labeled as meters. Tracking quality needs a calibrated K40 main camera and controlled trajectory tests before accuracy claims.

## Open-source preparation

ORB-SLAM3 is GPL-3.0. Preserve its license, notices, source and dependency attribution when distributing the app or native library. The upstream ROS 2 Android repository does not declare a repository-level license in GitHub metadata; review its source and dependency licenses before publishing a combined release. This document is a technical checklist, not a license grant.
