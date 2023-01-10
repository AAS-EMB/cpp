#include <gtest/gtest.h>
#include "binary_search.h"

TEST(binary_search_test, search_char_val) {
    char arr[] = {'0', '1', '5', '6', 'A'};
    std::span<char> s{arr};
    auto res{algorithm::binary_search(s, '0')};
    ASSERT_TRUE(res);
    ASSERT_EQ(res.value(), 0);
    res = algorithm::binary_search(s, 'A');
    ASSERT_TRUE(res);
    ASSERT_EQ(res.value(), 4);
    res = algorithm::binary_search(s, '5');
    ASSERT_TRUE(res);
    ASSERT_EQ(res.value(), 2);
    res = algorithm::binary_search(s, 'd');
    ASSERT_FALSE(res);
}

TEST(binary_search_test, search_unsignint_val) {
    unsigned int arr[] = {0, 1, 2, 5, 8, 10, 25, 33, 47, 100, 234};
    std::span<unsigned int> s{arr};
    auto res{algorithm::binary_search(s, (unsigned int)0)};
    ASSERT_TRUE(res);
    ASSERT_EQ(res.value(), 0);
    res = algorithm::binary_search(s, (unsigned int)234);
    ASSERT_TRUE(res);
    ASSERT_EQ(res.value(), 10);
    res = algorithm::binary_search(s, (unsigned int)25);
    ASSERT_TRUE(res);
    ASSERT_EQ(res.value(), 6);
    res = algorithm::binary_search(s, (unsigned int)1000);
    ASSERT_FALSE(res);
}

TEST(binary_search_test, search_int_val) {
    int arr[] = {-100, -55, -32, -2, 0, 10, 33, 44, 234, 512};
    std::span<int> s{arr};
    auto res{algorithm::binary_search(s, -100)};
    ASSERT_TRUE(res);
    ASSERT_EQ(res.value(), 0);
    res = algorithm::binary_search(s, 512);
    ASSERT_TRUE(res);
    ASSERT_EQ(res.value(), 9);
    res = algorithm::binary_search(s, 0);
    ASSERT_TRUE(res);
    ASSERT_EQ(res.value(), 4);
    res = algorithm::binary_search(s, 1000);
    ASSERT_FALSE(res);
}

TEST(binary_search_test, search_float_val) {
    float arr[] = {-100.0f, -55.0f, -32.0f, -2.0f, 0.0f, 10.0f, 33.0f, 44.0f, 234.0f, 512.0f};
    std::span<float> s{arr};
    auto res{algorithm::binary_search(s, -100.0f)};
    ASSERT_TRUE(res);
    ASSERT_EQ(res.value(), 0);
    res = algorithm::binary_search(s, 512.0f);
    ASSERT_TRUE(res);
    ASSERT_EQ(res.value(), 9);
    res = algorithm::binary_search(s, 0.0f);
    ASSERT_TRUE(res);
    ASSERT_EQ(res.value(), 4);
    res = algorithm::binary_search(s, 1000.0f);
    ASSERT_FALSE(res);
}