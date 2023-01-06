#include <gtest/gtest.h>
#include "selection.h"

TEST(selection_test, sort_char) {
    char arr[] = {'1', '0', '6', '5'};
    std::span<char> s{arr};
    sort::selection(s);
    ASSERT_EQ(s[0], '0');
    ASSERT_EQ(s[1], '1');
    ASSERT_EQ(s[2], '5');
    ASSERT_EQ(s[3], '6');
}

TEST(selection_test, sort_unsignint) {
    unsigned int arr[] = {1, 0, 6, 5};
    std::span<unsigned int> s{arr};
    sort::selection(s);
    ASSERT_EQ(s[0], 0);
    ASSERT_EQ(s[1], 1);
    ASSERT_EQ(s[2], 5);
    ASSERT_EQ(s[3], 6);
}

TEST(selection_test, sort_int) {
    int arr[] = {1, 0, 6, -5, -1};
    std::span<int> s{arr};
    sort::selection(s);
    ASSERT_EQ(s[0], -5);
    ASSERT_EQ(s[1], -1);
    ASSERT_EQ(s[2], 0);
    ASSERT_EQ(s[3], 1);
    ASSERT_EQ(s[4], 6);
}

TEST(selection_test, sort_float) {
    float arr[] = {0.1f, 0.0f, 1.0f, 0.5f, 1.1f};
    std::span<float> s{arr};
    sort::selection(s);
    ASSERT_EQ(s[0], 0.0f);
    ASSERT_EQ(s[1], 0.1f);
    ASSERT_EQ(s[2], 0.5f);
    ASSERT_EQ(s[3], 1.0f);
    ASSERT_EQ(s[4], 1.1f);
}
