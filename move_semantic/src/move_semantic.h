#pragma once

namespace algorithm {

template<typename T> struct remove_reference      { typedef T type; };
template<typename T> struct remove_reference<T&>  { typedef T type; };
template<typename T> struct remove_reference<T&&> { typedef T type; };

template <typename, typename> struct is_same { static constexpr bool value = false; };
template <typename T> struct is_same<T, T>   { static constexpr bool value = true;  };


template <typename T> struct is_rvalue_reference      { static constexpr bool value = false; };
template <typename T> struct is_rvalue_reference<T&&> { static constexpr bool value = true;  };

template <typename T> struct is_lvalue_reference      { static constexpr bool value = false; };
template <typename T> struct is_lvalue_reference<T&>  { static constexpr bool value = true;  };

template<typename T>
constexpr typename remove_reference<T>::type&& move(T&& t) noexcept {
    using RvalRef = typename remove_reference<T>::type&&;
    return static_cast<RvalRef>(t);
}

template<typename T>
constexpr T&& forward(typename remove_reference<T>::type& t) noexcept {
    return static_cast<T&&>(t);
}

}