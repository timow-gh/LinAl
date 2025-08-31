#include <gtest/gtest.h>
#include <linal/linal.hpp>

TEST(RadiansTest, DegreesToRadians) {
    EXPECT_DOUBLE_EQ(linal::degrees_to_radians(0.0), 0.0);
    EXPECT_DOUBLE_EQ(linal::degrees_to_radians(180.0), linal::PI_D);
    EXPECT_DOUBLE_EQ(linal::degrees_to_radians(90.0), linal::PI_D / 2);
}

TEST(RadiansTest, RadiansToDegrees) {
    EXPECT_DOUBLE_EQ(linal::radians_to_degrees(0.0), 0.0);
    EXPECT_DOUBLE_EQ(linal::radians_to_degrees(linal::PI_D), 180.0);
    EXPECT_DOUBLE_EQ(linal::radians_to_degrees(linal::PI_D / 2), 90.0);
}
