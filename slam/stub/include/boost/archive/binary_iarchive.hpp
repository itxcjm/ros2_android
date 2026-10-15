#pragma once
#include <istream>
namespace boost {
namespace archive {
class binary_iarchive {
 public:
  explicit binary_iarchive(std::istream &) {}
  template <class T> binary_iarchive &operator>>(T &) { return *this; }
  template <class T> binary_iarchive &operator&(T &) { return *this; }
};
}
}
