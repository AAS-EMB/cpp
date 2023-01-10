#pragma once
#include <span>
#include <optional>

namespace algorithm {

template<typename T, std::size_t N>
std::optional<std::size_t> binary_search(std::span<T, N> s, T val) {
    auto begin{0}, end{s.size()};
    while(begin <= end) {
        auto mid{(begin + end) / 2};
        if(s[mid] == val) { return mid; }
        s[mid] > val ? (end = mid - 1) : (begin = mid + 1);
    }
    return std::nullopt;
}

}