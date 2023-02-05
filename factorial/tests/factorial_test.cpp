#include <gtest/gtest.h>
#include "factorial.h"

TEST(factorial_test, calculate) {
    using namespace algorithm;
    ASSERT_EQ(factorial(static_cast<unsigned long int>(0)), 1);
    ASSERT_EQ(factorial(static_cast<unsigned long int>(1)), 1);
    ASSERT_EQ(factorial(static_cast<unsigned long int>(5)), 120);
    ASSERT_EQ(factorial(static_cast<unsigned long int>(15)), 1307674368000);
}