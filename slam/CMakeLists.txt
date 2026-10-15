cmake_minimum_required(VERSION 3.22)
project(k40_slam LANGUAGES CXX C)

# ORB-SLAM3 is cross-compiled here instead of using its own CMakeLists so that
# the desktop Pangolin viewer and the Boost.Serialization archives can be left out.
set(ORB_ROOT "" CACHE PATH "ORB-SLAM3 source root")
set(EIGEN_INCLUDE "" CACHE PATH "Eigen3 include directory")
set(OPENCV_SDK "" CACHE PATH "OpenCV Android SDK root")

if(NOT ORB_ROOT OR NOT EIGEN_INCLUDE OR NOT OPENCV_SDK)
  message(FATAL_ERROR "Pass -DORB_ROOT, -DEIGEN_INCLUDE and -DOPENCV_SDK")
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# stub/include comes first: it carries no-op pangolin and boost headers.
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/stub/include
  ${ORB_ROOT}
  ${ORB_ROOT}/include
  ${ORB_ROOT}/include/CameraModels
  ${ORB_ROOT}/Thirdparty/Sophus
  ${ORB_ROOT}/Thirdparty/DBoW2
  ${ORB_ROOT}/Thirdparty/g2o
  ${EIGEN_INCLUDE}
  ${OPENCV_SDK}/sdk/native/jni/include
)

add_compile_options(-O3 -fPIC -fexceptions -frtti -w)
# ORB-SLAM3 headers use boost::serialization without including it themselves.
add_compile_options(-include ${CMAKE_CURRENT_SOURCE_DIR}/stub/prelude.h)
add_definitions(-DCOMPILEDWITHC11)

# g2o expects a generated config.h; the ORB-SLAM3 build only needs the guards.
file(WRITE ${ORB_ROOT}/Thirdparty/g2o/config.h
"#ifndef G2O_CONFIG_H\n#define G2O_CONFIG_H\n#endif\n")

file(GLOB_RECURSE G2O_SOURCES ${ORB_ROOT}/Thirdparty/g2o/g2o/*.cpp)
file(GLOB_RECURSE DBOW2_SOURCES ${ORB_ROOT}/Thirdparty/DBoW2/DBoW2/*.cpp)
file(GLOB ORB_SOURCES ${ORB_ROOT}/src/*.cc ${ORB_ROOT}/src/CameraModels/*.cpp)

# Real Viewer.cc and MapDrawer.cc need desktop OpenGL; stub_no_viewer.cc replaces them.
list(REMOVE_ITEM ORB_SOURCES
  ${ORB_ROOT}/src/Viewer.cc
  ${ORB_ROOT}/src/MapDrawer.cc)

add_library(k40_slam SHARED
  ${ORB_SOURCES}
  ${G2O_SOURCES}
  ${DBOW2_SOURCES}
  ${CMAKE_CURRENT_SOURCE_DIR}/stub_no_viewer.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/k40_slam_jni.cc
)

file(GLOB OPENCV_STATIC_LIBS ${OPENCV_SDK}/sdk/native/staticlibs/${ANDROID_ABI}/*.a)
file(GLOB OPENCV_3RD_LIBS ${OPENCV_SDK}/sdk/native/3rdparty/libs/${ANDROID_ABI}/*.a)

# Static OpenCV is listed twice to satisfy archive link order.
target_link_libraries(k40_slam
  ${OPENCV_STATIC_LIBS}
  ${OPENCV_3RD_LIBS}
  ${OPENCV_STATIC_LIBS}
  ${OPENCV_3RD_LIBS}
  log android m z dl atomic jnigraphics
)
