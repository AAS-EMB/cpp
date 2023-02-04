#include <gtest/gtest.h>
#include "move_semantic.h"

TEST(move_semantic_test, is_same) {
    using namespace algorithm;
    {
        auto r = is_same<char, char>::value;
        ASSERT_TRUE(r);
    }
    {
        auto r = is_same<char, int>::value;
        ASSERT_FALSE(r);
    }
}

TEST(move_semantic_test, is_rvalue_reference) {
    using namespace algorithm;
    {
        auto r = is_rvalue_reference<char&&>::value;
        ASSERT_TRUE(r);
    }
    {
        auto r = is_rvalue_reference<char>::value;
        ASSERT_FALSE(r);
    }
}

TEST(move_semantic_test, is_lvalue_reference) {
    using namespace algorithm;
    {
        auto r = is_lvalue_reference<char&>::value;
        ASSERT_TRUE(r);
    }
    {
        auto r = is_lvalue_reference<char>::value;
        ASSERT_FALSE(r);
    }
}

TEST(move_semantic_test, remove_reference) {
    using namespace algorithm;
    {
        auto r = is_same<int, remove_reference<int>::type>::value;
        ASSERT_TRUE(r);
    }
    {
        auto r = is_same<int, remove_reference<int&>::type>::value;
        ASSERT_TRUE(r);
    }
    {
        auto r = is_same<int, remove_reference<int&&>::type>::value;
        ASSERT_TRUE(r);
    }
}

TEST(move_semantic_test, move) {
    using namespace algorithm;
    {
        auto r = is_rvalue_reference<decltype(move(0))>::value;
        ASSERT_TRUE(r);
    }
    {
        auto t{0};
        auto r = is_rvalue_reference<decltype(move(t))>::value;
        ASSERT_TRUE(r);
    }
    {
        auto t{0};
        auto& lvalue{t};
        auto r = is_rvalue_reference<decltype(move(lvalue))>::value;
        ASSERT_TRUE(r);
    }
}

TEST(move_semantic_test, forward) {
    using namespace algorithm;
    {
        int t{0};
        auto r = is_rvalue_reference<decltype(forward<decltype(t)>(t))>::value;
        ASSERT_TRUE(r);
    }
    {
        auto t{0};
        auto& lvalue{t};
        auto r = is_lvalue_reference<decltype(forward<decltype(lvalue)>(lvalue))>::value;
        ASSERT_TRUE(r);
    }
}