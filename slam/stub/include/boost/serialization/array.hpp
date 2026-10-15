#pragma once
#include <cstddef>
namespace boost {
namespace serialization {

template <class T>
class array_wrapper {
 public:
  array_wrapper(T *t, std::size_t s) : m_t(t), m_size(s) {}
  T *m_t;
  std::size_t m_size;
};

template <class T>
inline const array_wrapper<T> make_array(T *t, std::size_t s) {
  return array_wrapper<T>(t, s);
}

}
}