#pragma once
#include <span>
#include <cstddef>

namespace sort {

template<typename T, std::size_t N>
void selection(std::span<T, N>& s) {
    for(auto i = s.begin(); i != s.end(); ++i) {
        for(auto j = i; j != s.end(); ++j) {
            if(*i > *j) {
                std::swap(*j, *i);
            }
        }
    }
}

}