#include <gtest/gtest.h>
#include <linal/linal.hpp>

using namespace linal;

TEST(vec, construct_default)
{
  float2 vec;
  EXPECT_EQ(vec[0], 0.0F);
  EXPECT_EQ(vec[1], 0.0F);
}

TEST(vec, construct_from_value)
{
  [[maybe_unused]] float2 vec{1.0F};
}

TEST(vec, construct_size)
{
  float2 vec;
  EXPECT_EQ(vec.dim, 2);
}

TEST(vec, access_data)
{
  float2 vec{1.0F};
  EXPECT_EQ(vec.data()[0], 1.0F);
  EXPECT_EQ(vec.data()[1], 1.0F);

  const float2 cVec{2.0F};
  EXPECT_EQ(cVec.data()[0], 2.0F);
  EXPECT_EQ(cVec.data()[1], 2.0F);
}

TEST(vec, construct_random_access_operator)
{
  float2 vec{1.0F};
  EXPECT_EQ(vec[0], 1.0F);
  EXPECT_EQ(vec[1], 1.0F);

  const float2 cVec{2.0F};
  EXPECT_EQ(cVec[0], 2.0F);
  EXPECT_EQ(cVec[0], 2.0F);
}

TEST(vec, comparison_policy)
{
  float2 vec1{1.0F};
  float2 vec2{1.0F};
  float2 vec3{2.0F};

  EXPECT_TRUE(vec1 == vec2);
  EXPECT_FALSE(vec1 == vec3);
  EXPECT_FALSE(vec1 != vec2);
  EXPECT_TRUE(vec1 != vec3);
}

TEST(vec, addition_operators)
{
  float2 vec1{1.0F};
  float2 vec2{2.0F};
  float2 vec3 = vec1 + vec2;
  EXPECT_EQ(vec3[0], 3.0F);
  EXPECT_EQ(vec3[1], 3.0F);

  vec3 = vec1 + 2.0F;
  EXPECT_EQ(vec3[0], 3.0F);
  EXPECT_EQ(vec3[1], 3.0F);

  vec3 = 2.0F + vec1;
  EXPECT_EQ(vec3[0], 3.0F);
  EXPECT_EQ(vec3[1], 3.0F);

  vec3 += vec2;
  EXPECT_EQ(vec3[0], 5.0F);
  EXPECT_EQ(vec3[1], 5.0F);

  vec3 += 2.0F;
  EXPECT_EQ(vec3[0], 7.0F);
  EXPECT_EQ(vec3[1], 7.0F);
}

TEST(vec, subtraction_operators)
{
  float2 vec1{1.0F};
  float2 vec2{2.0F};
  float2 vec3 = vec1 - vec2;
  EXPECT_EQ(vec3[0], -1.0F);
  EXPECT_EQ(vec3[1], -1.0F);

  vec3 = vec1 - 2.0F;
  EXPECT_EQ(vec3[0], -1.0F);
  EXPECT_EQ(vec3[1], -1.0F);

  vec3 = 2.0F - vec1;
  EXPECT_EQ(vec3[0], 1.0F);
  EXPECT_EQ(vec3[1], 1.0F);

  vec3 -= vec2;
  EXPECT_EQ(vec3[0], -1.0F);
  EXPECT_EQ(vec3[1], -1.0F);

  vec3 -= 2.0F;
  EXPECT_EQ(vec3[0], -3.0F);
  EXPECT_EQ(vec3[1], -3.0F);
}

TEST(vec, multiplication_operators)
{
  float2 vec1{1.0F};

  float2 vec3 = vec1 * 2.0F;
  EXPECT_EQ(vec3[0], 2.0F);
  EXPECT_EQ(vec3[1], 2.0F);

  vec3 = 2.0F * vec1;
  EXPECT_EQ(vec3[0], 2.0F);
  EXPECT_EQ(vec3[1], 2.0F);

  vec3 *= 2.0F;
  EXPECT_EQ(vec3[0], 4.0F);
  EXPECT_EQ(vec3[1], 4.0F);
}

TEST(vec, division_operators)
{
  float2 vec1{1.0F};

  float2 vec3 = vec1 / 2.0F;
  EXPECT_EQ(vec3[0], 0.5F);
  EXPECT_EQ(vec3[1], 0.5F);

  vec3 /= 2.0F;
  EXPECT_EQ(vec3[0], 0.25F);
  EXPECT_EQ(vec3[1], 0.25F);
}

TEST(vec, unary_operators)
{
  float2 vec1{1.0F};
  float2 vec2 = -vec1;
  EXPECT_EQ(vec2[0], -1.0F);
  EXPECT_EQ(vec2[1], -1.0F);
}

TEST(vec, use_all_types)
{
  [[maybe_unused]] int2 vec1{1};
  [[maybe_unused]] int3 vec2{1};
  [[maybe_unused]] uint2 vec3{1U};
  [[maybe_unused]] uint3 vec4{1U};
  [[maybe_unused]] long2 vec5{1L};
  [[maybe_unused]] long3 vec6{1L};
  [[maybe_unused]] ulong2 vec7{1UL};
  [[maybe_unused]] ulong3 vec8{1UL};
  [[maybe_unused]] float2 vec9{1.0F};
  [[maybe_unused]] float3 vec10{1.0F};
  [[maybe_unused]] double2 vec11{1.0};
  [[maybe_unused]] double3 vec12{1.0};
}

TEST(vec, length)
{
  float2 vec{3.0F, 4.0F};
  float length = vec.length();
  EXPECT_FLOAT_EQ(length, 5.0F);
}

TEST(vec, length_squared)
{
  float2 vec{3.0F, 4.0F};
  float lengthSquared = vec.length_squared();
  EXPECT_FLOAT_EQ(lengthSquared, 25.0F);
}

TEST(vec, normalize)
{
  float2 vec{3.0F, 4.0F};
  float2 normalized = vec.normalize();
  EXPECT_FLOAT_EQ(normalized[0], 0.6F);
  EXPECT_FLOAT_EQ(normalized[1], 0.8F);

  vec = float2{2.0F, 0.0F};
  normalized = normalize(vec);
  EXPECT_FLOAT_EQ(normalized[0], 1.0F);
  EXPECT_FLOAT_EQ(normalized[1], 0.0F);
}

TEST(vec, cross)
{
  float3 vec1{1.0F, 0.0F, 0.0F};
  float3 vec2{0.0F, 1.0F, 0.0F};
  float3 vec3 = cross(vec1, vec2);
  EXPECT_EQ(vec3[0], 0.0F);
  EXPECT_EQ(vec3[1], 0.0F);
  EXPECT_EQ(vec3[2], 1.0F);
}

TEST(vec, dot)
{
  float3 vec1{1.0F, 0.0F, 0.0F};
  float3 vec2{0.0F, 1.0F, 0.0F};
  float dotP = dot(vec1, vec2);
  EXPECT_FLOAT_EQ(dotP, 0.0F);

  vec1 = float3{1.0F, 0.0F, 0.0F};
  vec2 = float3{1.0F, 0.0F, 0.0F};
  dotP = dot(vec1, vec2);
  EXPECT_FLOAT_EQ(dotP, 1.0F);

  vec1 = float3{1.0F, 0.0F, 0.0F};
  vec2 = float3{-1.0F, 0.0F, 0.0F};
  dotP = dot(vec1, vec2);
  EXPECT_FLOAT_EQ(dotP, -1.0F);
}

TEST(vec, vec_from_vec_with_different_value_type)
{
  float2 vec1{1.0F};
  double2 vec2 = vec1;
  EXPECT_DOUBLE_EQ(vec2[0], 1.0);
  EXPECT_DOUBLE_EQ(vec2[1], 1.0);
}