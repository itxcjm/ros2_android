#pragma once
#include <cstddef>
namespace boost {
namespace serialization {
template <class T> class array_wrapper;
template <class T> const array_wrapper<T> make_array(T *t, std::size_t s);
}
}
