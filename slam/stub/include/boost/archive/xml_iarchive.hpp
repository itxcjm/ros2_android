#pragma once
#include <istream>
namespace boost {
namespace archive {
class xml_iarchive {
 public:
  explicit xml_iarchive(std::istream &) {}
  template <class T> xml_iarchive &operator>>(T &) { return *this; }
  template <class T> xml_iarchive &operator&(T &) { return *this; }
};
}
}
