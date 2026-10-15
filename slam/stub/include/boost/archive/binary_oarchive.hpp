#pragma once
#include <ostream>
namespace boost {
namespace archive {
class binary_oarchive {
 public:
  explicit binary_oarchive(std::ostream &) {}
  template <class T> binary_oarchive &operator<<(const T &) { return *this; }
  template <class T> binary_oarchive &operator&(const T &) { return *this; }
};
}
}
