#pragma once
#include <span>
#include <cstddef>

namespace sort {

template<typename T>
void quick(T* low, T* high) {
    auto size{std::distance(low, high)};
    if(size > 1) {
        auto prev{std::prev(high)};
        std::swap(*std::next(low, size / 2), *prev);
        auto pivot = std::partition(low, prev, [prev](decltype(*prev) val) { return val < *prev; });
        std::swap(*pivot, *prev);
        quick(low, pivot);
        quick(std::next(pivot), high);
    }
}

}