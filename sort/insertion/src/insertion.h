#pragma once
#include <span>
#include <cstddef>

namespace sort {

template<typename T, std::size_t N>
void insertion(std::span<T, N>& s) {
    for(auto i = 1; i < s.size(); ++i) {
        auto tmp{s[i]};
        int j{i - 1};
        while(j >= 0 && tmp <= s[j]) {
            std::swap(s[j + 1], s[j]);
            --j;
        }
    }
}

}