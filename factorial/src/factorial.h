#pragma once
#include <concepts>
#include <type_traits>

namespace algorithm {

template<typename T>
concept Types = std::is_same<unsigned long int, T>::value;

template<Types T>
T factorial(const T& value) {
    if(value == static_cast<T>(1) or value == static_cast<T>(0)) { return static_cast<T>(1); }
    return value * factorial(value - 1);
}

}