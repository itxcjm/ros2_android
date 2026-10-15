#pragma once
#include <istream>
namespace boost {
namespace archive {
class text_iarchive {
 public:
  explicit text_iarchive(std::istream &) {}
  template <class T> text_iarchive &operator>>(T &) { return *this; }
  template <class T> text_iarchive &operator&(T &) { return *this; }
};
}
}
