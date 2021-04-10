#include "gtest/gtest.h"

TEST(basicGTest, testEqual) { EXPECT_EQ(1, 1); }
TEST(basicGTest, testTrue) { EXPECT_TRUE(true); }

TEST(basicGTest, testFalse) { EXPECT_FALSE(false); }
