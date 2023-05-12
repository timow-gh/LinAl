#include <LinAl/BlazeWrapper/BlazeVec.hpp>
#include <LinAl/BlazeWrapper/BlazeVec2.hpp>
#include <gtest/gtest.h>

using namespace LinAl;

TEST(Vec, constructor)
{
  Vec<float_t, 2> vec{1, 1};
}

TEST(Vec, construct_from_vec2)
{
  Vec2<float_t> vec2{1, 2};
  Vec<float_t, 2> vec{vec2};
  EXPECT_TRUE(vec2 == vec);
}
