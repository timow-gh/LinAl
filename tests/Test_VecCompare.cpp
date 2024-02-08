#include <gtest/gtest.h>
#include <linal/vec_compare.hpp>

using namespace linal;

TEST(vec_compare, is_zero_default_eps)
{
  double3 vec{0.0, 0.0, 0.0};
  EXPECT_TRUE(is_zero(vec));
}

TEST(vec_compare, is_zero_custom_eps)
{
  double3 vec{1e-10, 1e-10, 1e-10};
  EXPECT_FALSE(is_zero(vec, 1e-11));
}

TEST(vec_compare, is_zero_custom_eps_failure)
{
  double3 vec{1e-10, 1e-10, 1e-10};
  EXPECT_TRUE(is_zero(vec, 1e-9));
}

TEST(vec_compare, is_equal_default_eps)
{
  double3 vecA{1.0, 2.0, 3.0};
  double3 vecB{1.0, 2.0, 3.0};
  EXPECT_TRUE(is_equal(vecA, vecB));
}

TEST(vec_compare, is_equal_custom_eps)
{
  double3 vecA{1.0, 2.0, 3.0};
  double3 vecB{1.0, 2.0, 3.0 + 1e-10};
  EXPECT_FALSE(is_equal(vecA, vecB, 1e-11));
}

TEST(vec_compare, is_equal_custom_eps_failure)
{
  double3 vecA{1.0, 2.0, 3.0};
  double3 vecB{1.0, 2.0, 3.0 + 1e-10};
  EXPECT_TRUE(is_equal(vecA, vecB, 1e-9));
}