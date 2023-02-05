#include <gtest/gtest.h>
#include "quick.h"

TEST(quick_test, sort_char) {
    char arr[] = {'1', '0', '6', '5'};
    auto len{sizeof(arr) / sizeof(arr[0])};
    sort::quick(arr, arr + len);
    ASSERT_EQ(arr[0], '0');
    ASSERT_EQ(arr[1], '1');
    ASSERT_EQ(arr[2], '5');
    ASSERT_EQ(arr[3], '6');
}

TEST(quick_test, sort_unsignint) {
    unsigned int arr[] = {1, 0, 6, 5};
    auto len{sizeof(arr) / sizeof(arr[0])};
    sort::quick(arr, arr + len);
    ASSERT_EQ(arr[0], 0);
    ASSERT_EQ(arr[1], 1);
    ASSERT_EQ(arr[2], 5);
    ASSERT_EQ(arr[3], 6);
}

TEST(quick_test, sort_int) {
    int arr[] = {1, 0, 6, -5, -1};
    auto len{sizeof(arr) / sizeof(arr[0])};
    sort::quick(arr, arr + len);
    ASSERT_EQ(arr[0], -5);
    ASSERT_EQ(arr[1], -1);
    ASSERT_EQ(arr[2], 0);
    ASSERT_EQ(arr[3], 1);
    ASSERT_EQ(arr[4], 6);
}

TEST(quick_test, sort_float) {
    float arr[] = {0.1f, 0.0f, 1.0f, 0.5f, 1.1f};
    auto len{sizeof(arr) / sizeof(arr[0])};
    sort::quick(arr, arr + len);
    ASSERT_EQ(arr[0], 0.0f);
    ASSERT_EQ(arr[1], 0.1f);
    ASSERT_EQ(arr[2], 0.5f);
    ASSERT_EQ(arr[3], 1.0f);
    ASSERT_EQ(arr[4], 1.1f);
}
