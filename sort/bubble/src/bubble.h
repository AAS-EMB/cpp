#pragma once
#include <span>
#include <cstddef>

namespace sort {

template<typename T, std::size_t N>
void bubble(std::span<T, N>& s) {
    auto is_sorted{false};
    while(!is_sorted) {
        is_sorted = true;
        for(auto it = s.begin(); it != (s.end() - 1); ++it) {
            if(*it > *(it + 1)) {
                std::swap(*it, *(it + 1));
                is_sorted = false;
            }
        }
    }
}

}