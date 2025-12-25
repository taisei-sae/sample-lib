#include <gtest/gtest.h>
#include "sample-lib/calc.h"

TEST(CalcTest, AddPositiveNumbers) {
    EXPECT_EQ(add(1, 2), 3);
}

TEST(CalcTest, AddNegativeNumbers) {
    EXPECT_EQ(add(-1, -1), -2);
}