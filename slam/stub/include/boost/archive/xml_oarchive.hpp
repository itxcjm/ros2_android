#pragma once
#include <ostream>
namespace boost {
namespace archive {
class xml_oarchive {
 public:
  explicit xml_oarchive(std::ostream &) {}
  template <class T> xml_oarchive &operator<<(const T &) { return *this; }
  template <class T> xml_oarchive &operator&(const T &) { return *this; }
};
}
}
