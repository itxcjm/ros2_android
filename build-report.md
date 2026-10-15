# ORB-SLAM3 build report

## configure
```
-- ORB sources: 26, g2o sources: 32, DBoW2 sources: 6
-- g2o: cache.cpp
-- g2o: estimate_propagator.cpp
-- g2o: factory.cpp
-- g2o: hyper_dijkstra.cpp
-- g2o: hyper_graph.cpp
-- g2o: hyper_graph_action.cpp
-- g2o: jacobian_workspace.cpp
-- g2o: marginal_covariance_cholesky.cpp
-- g2o: matrix_structure.cpp
-- g2o: optimizable_graph.cpp
-- g2o: optimization_algorithm.cpp
-- g2o: optimization_algorithm_dogleg.cpp
-- g2o: optimization_algorithm_factory.cpp
-- g2o: optimization_algorithm_gauss_newton.cpp
-- g2o: optimization_algorithm_levenberg.cpp
-- g2o: optimization_algorithm_with_hessian.cpp
-- g2o: parameter.cpp
-- g2o: parameter_container.cpp
-- g2o: robust_kernel.cpp
-- g2o: robust_kernel_factory.cpp
-- g2o: robust_kernel_impl.cpp
-- g2o: solver.cpp
-- g2o: sparse_block_matrix_test.cpp
-- g2o: sparse_optimizer.cpp
-- g2o: property.cpp
-- g2o: string_tools.cpp
-- g2o: timeutil.cpp
-- g2o: se3mat.cpp
-- g2o: types_sba.cpp
-- g2o: types_seven_dof_expmap.cpp
-- g2o: types_six_dof_expmap.cpp
-- dbow2: BowVector.cpp
-- dbow2: FORB.cpp
-- dbow2: FeatureVector.cpp
-- dbow2: ScoringObject.cpp
-- dbow2: Random.cpp
-- dbow2: Timestamp.cpp
-- Configuring done (0.6s)
-- Generating done (0.0s)
-- Build files have been written to: /home/runner/work/ros2_android/ros2_android/slam/build
```

## compiled objects
```
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/DBoW2/DBoW2/BowVector.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/DBoW2/DBoW2/FORB.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/DBoW2/DBoW2/FeatureVector.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/DBoW2/DBoW2/ScoringObject.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/DBoW2/DUtils/Random.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/DBoW2/DUtils/Timestamp.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/batch_stats.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/cache.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/estimate_propagator.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/factory.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/hyper_dijkstra.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/hyper_graph.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/hyper_graph_action.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/jacobian_workspace.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/marginal_covariance_cholesky.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/matrix_structure.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/optimizable_graph.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/optimization_algorithm.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/optimization_algorithm_dogleg.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/optimization_algorithm_factory.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/optimization_algorithm_gauss_newton.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/optimization_algorithm_levenberg.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/optimization_algorithm_with_hessian.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/parameter.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/parameter_container.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/robust_kernel.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/robust_kernel_factory.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/robust_kernel_impl.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/solver.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/sparse_block_matrix_test.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/core/sparse_optimizer.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/stuff/property.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/stuff/string_tools.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/stuff/timeutil.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/types/se3mat.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/types/types_sba.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/types/types_seven_dof_expmap.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/Thirdparty/g2o/g2o/types/types_six_dof_expmap.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Atlas.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/CameraModels/KannalaBrandt8.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/CameraModels/Pinhole.cpp.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Config.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Converter.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Frame.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/FrameDrawer.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/G2oTypes.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/GeometricTools.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/ImuTypes.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/KeyFrame.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/KeyFrameDatabase.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/LocalMapping.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/LoopClosing.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Map.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/MapPoint.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/ORBextractor.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/ORBmatcher.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Optimizer.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Settings.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Sim3Solver.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/System.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Tracking.cc.o
CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/TwoViewReconstruction.cc.o
CMakeFiles/k40_slam.dir/k40_slam_jni.cc.o
CMakeFiles/k40_slam.dir/stub_no_viewer.cc.o
```

## errors
```
66:ld: error: undefined symbol: ORB_SLAM3::EdgeSE3ProjectXYZ::EdgeSE3ProjectXYZ()
74:ld: error: undefined symbol: ORB_SLAM3::EdgeSE3ProjectXYZToBody::EdgeSE3ProjectXYZToBody()
80:ld: error: undefined symbol: vtable for ORB_SLAM3::EdgeSE3ProjectXYZOnlyPose
90:ld: error: undefined symbol: vtable for ORB_SLAM3::EdgeSE3ProjectXYZOnlyPoseToBody
97:ld: error: undefined symbol: ORB_SLAM3::VertexSim3Expmap::VertexSim3Expmap()
101:ld: error: undefined symbol: ORB_SLAM3::EdgeSim3ProjectXYZ::EdgeSim3ProjectXYZ()
105:ld: error: undefined symbol: ORB_SLAM3::EdgeInverseSim3ProjectXYZ::EdgeInverseSim3ProjectXYZ()
109:ld: error: undefined symbol: ORB_SLAM3::MLPnPsolver::MLPnPsolver(ORB_SLAM3::Frame const&, std::__ndk1::vector<ORB_SLAM3::MapPoint*, std::__ndk1::allocator<ORB_SLAM3::MapPoint*> > const&)
113:ld: error: undefined symbol: ORB_SLAM3::MLPnPsolver::SetRansacParameters(double, int, int, int, float, float)
117:ld: error: undefined symbol: ORB_SLAM3::MLPnPsolver::iterate(int, bool&, std::__ndk1::vector<bool, std::__ndk1::allocator<bool> >&, int&, Eigen::Matrix<float, 4, 4, 0, 4, 4>&)
120:clang++: error: linker command failed with exit code 1 (use -v to see invocation)
121:gmake[2]: *** [CMakeFiles/k40_slam.dir/build.make:1165: lib/libk40_slam.so] Error 1
122:gmake[1]: *** [CMakeFiles/Makefile2:87: CMakeFiles/k40_slam.dir/all] Error 2
123:gmake: *** [Makefile:91: all] Error 2
```

## build tail
```
>>>               CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Optimizer.cc.o:(ORB_SLAM3::Optimizer::PoseOptimization(ORB_SLAM3::Frame*))
>>> referenced by OptimizableTypes.h:35 (/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/include/OptimizableTypes.h:35)
>>>               CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Optimizer.cc.o:(ORB_SLAM3::Optimizer::PoseOptimization(ORB_SLAM3::Frame*))
>>> referenced 1 more times
>>> the vtable symbol may be undefined because the class is missing its key function (see https://lld.llvm.org/missingkeyfunction)

ld: error: undefined symbol: vtable for ORB_SLAM3::EdgeSE3ProjectXYZOnlyPoseToBody
>>> referenced by Optimizer.cc:0 (/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Optimizer.cc:0)
>>>               CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Optimizer.cc.o:(ORB_SLAM3::Optimizer::PoseOptimization(ORB_SLAM3::Frame*))
>>> referenced by Optimizer.cc:0 (/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Optimizer.cc:0)
>>>               CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Optimizer.cc.o:(ORB_SLAM3::Optimizer::PoseOptimization(ORB_SLAM3::Frame*))
>>> the vtable symbol may be undefined because the class is missing its key function (see https://lld.llvm.org/missingkeyfunction)

ld: error: undefined symbol: ORB_SLAM3::VertexSim3Expmap::VertexSim3Expmap()
>>> referenced by Optimizer.cc:2135 (/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Optimizer.cc:2135)
>>>               CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Optimizer.cc.o:(ORB_SLAM3::Optimizer::OptimizeSim3(ORB_SLAM3::KeyFrame*, ORB_SLAM3::KeyFrame*, std::__ndk1::vector<ORB_SLAM3::MapPoint*, std::__ndk1::allocator<ORB_SLAM3::MapPoint*> >&, g2o::Sim3&, float, bool, Eigen::Matrix<double, 7, 7, 0, 7, 7>&, bool))

ld: error: undefined symbol: ORB_SLAM3::EdgeSim3ProjectXYZ::EdgeSim3ProjectXYZ()
>>> referenced by Optimizer.cc:2248 (/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Optimizer.cc:2248)
>>>               CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Optimizer.cc.o:(ORB_SLAM3::Optimizer::OptimizeSim3(ORB_SLAM3::KeyFrame*, ORB_SLAM3::KeyFrame*, std::__ndk1::vector<ORB_SLAM3::MapPoint*, std::__ndk1::allocator<ORB_SLAM3::MapPoint*> >&, g2o::Sim3&, float, bool, Eigen::Matrix<double, 7, 7, 0, 7, 7>&, bool))

ld: error: undefined symbol: ORB_SLAM3::EdgeInverseSim3ProjectXYZ::EdgeInverseSim3ProjectXYZ()
>>> referenced by Optimizer.cc:2286 (/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Optimizer.cc:2286)
>>>               CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Optimizer.cc.o:(ORB_SLAM3::Optimizer::OptimizeSim3(ORB_SLAM3::KeyFrame*, ORB_SLAM3::KeyFrame*, std::__ndk1::vector<ORB_SLAM3::MapPoint*, std::__ndk1::allocator<ORB_SLAM3::MapPoint*> >&, g2o::Sim3&, float, bool, Eigen::Matrix<double, 7, 7, 0, 7, 7>&, bool))

ld: error: undefined symbol: ORB_SLAM3::MLPnPsolver::MLPnPsolver(ORB_SLAM3::Frame const&, std::__ndk1::vector<ORB_SLAM3::MapPoint*, std::__ndk1::allocator<ORB_SLAM3::MapPoint*> > const&)
>>> referenced by Tracking.cc:3656 (/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Tracking.cc:3656)
>>>               CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Tracking.cc.o:(ORB_SLAM3::Tracking::Relocalization())

ld: error: undefined symbol: ORB_SLAM3::MLPnPsolver::SetRansacParameters(double, int, int, int, float, float)
>>> referenced by Tracking.cc:3657 (/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Tracking.cc:3657)
>>>               CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Tracking.cc.o:(ORB_SLAM3::Tracking::Relocalization())

ld: error: undefined symbol: ORB_SLAM3::MLPnPsolver::iterate(int, bool&, std::__ndk1::vector<bool, std::__ndk1::allocator<bool> >&, int&, Eigen::Matrix<float, 4, 4, 0, 4, 4>&)
>>> referenced by Tracking.cc:3683 (/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Tracking.cc:3683)
>>>               CMakeFiles/k40_slam.dir/home/runner/work/ros2_android/ros2_android/deps/ORB_SLAM3/src/Tracking.cc.o:(ORB_SLAM3::Tracking::Relocalization())
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
gmake[2]: *** [CMakeFiles/k40_slam.dir/build.make:1165: lib/libk40_slam.so] Error 1
gmake[1]: *** [CMakeFiles/Makefile2:87: CMakeFiles/k40_slam.dir/all] Error 2
gmake: *** [Makefile:91: all] Error 2
```

## shared objects
```
```
