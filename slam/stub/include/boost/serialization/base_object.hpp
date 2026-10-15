#pragma once
namespace boost {
namespace serialization {
template <class Base, class Derived> Base &base_object(Derived &d);
}
}
