// 预包含：ORB-SLAM3 的部分头文件直接使用 boost::serialization 但不自己 include，
// 官方构建靠其它头间接引入。这里统一提前引入空壳实现。
#pragma once
#include <boost/serialization/access.hpp>
#include <boost/serialization/array.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <pangolin/pangolin.h>