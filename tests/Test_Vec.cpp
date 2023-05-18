#include <gtest/gtest.h>
#include <linal/vec.hpp>
#include <linal/vec2.hpp>

using namespace linal;

TEST(vec, constructor)
{
  [[maybe_unused]] vec<float_t, 2> vec{1, 1};
}

TEST(vec, construct_from_vec2)
{
  vec2<float_t> vec2{1, 2};
  vec<float_t, 2> vec{vec2};
  EXPECT_TRUE(vec2 == vec);
}
