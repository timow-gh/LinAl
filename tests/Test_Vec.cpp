#include <gtest/gtest.h>
#include <linal/Vec.hpp>
#include <linal/Vec2.hpp>

using namespace linal;

TEST(Vec, constructor)
{
  [[maybe_unused]] Vec<float_t, 2> vec{1, 1};
}

TEST(Vec, construct_from_vec2)
{
  Vec2<float_t> vec2{1, 2};
  Vec<float_t, 2> vec{vec2};
  EXPECT_TRUE(vec2 == vec);
}
