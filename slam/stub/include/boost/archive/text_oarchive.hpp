#pragma once
#include <ostream>
namespace boost {
namespace archive {
class text_oarchive {
 public:
  explicit text_oarchive(std::ostream &) {}
  template <class T> text_oarchive &operator<<(const T &) { return *this; }
  template <class T> text_oarchive &operator&(const T &) { return *this; }
};
}
}
