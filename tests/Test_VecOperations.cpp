#include <gtest/gtest.h>
#include <linal/linal.hpp>

using namespace linal;

TEST(vec, dot_same_dir)
{
  double dotP = dot(double3Z, double3Z);
  EXPECT_DOUBLE_EQ(dotP, 1.0);
}

TEST(vec, dot_orthogonal)
{
  double dotP = dot(double3X, double3Z);
  EXPECT_DOUBLE_EQ(dotP, 0.0);
}

TEST(vec, dot_opposite_dir)
{
  double dotP = dot(-double3Z, double3Z);
  EXPECT_DOUBLE_EQ(dotP, -1.0);
}

TEST(vec, cross_same_dir)
{
  double3 crossP = cross(double3Z, double3Z);
  EXPECT_DOUBLE_EQ(crossP[0], 0.0);
  EXPECT_DOUBLE_EQ(crossP[1], 0.0);
  EXPECT_DOUBLE_EQ(crossP[2], 0.0);
}

TEST(vec, cross)
{
  double3 crossP = cross(double3X, double3Y);
  EXPECT_DOUBLE_EQ(crossP[0], 0.0);
  EXPECT_DOUBLE_EQ(crossP[1], 0.0);
  EXPECT_DOUBLE_EQ(crossP[2], 1.0);
}

TEST(vec, cross_opposite_dir)
{
  double3 crossP = cross(-double3Z, double3Z);
  EXPECT_DOUBLE_EQ(crossP[0], 0.0);
  EXPECT_DOUBLE_EQ(crossP[1], 0.0);
  EXPECT_DOUBLE_EQ(crossP[2], 0.0);
}

TEST(vec, norm2Squared)
{
  double norm2Squared = length_squared(double3{3 * double3Z});
  EXPECT_DOUBLE_EQ(norm2Squared, 9.0);
}

TEST(vec, length)
{
  double norm2 = length(double3{3 * double3Z});
  EXPECT_DOUBLE_EQ(norm2, 3);
}

TEST(vec, normalize)
{
  double3 norm = normalize(double3{3 * double3Z});
  EXPECT_DOUBLE_EQ(norm[0], 0.0);
  EXPECT_DOUBLE_EQ(norm[1], 0.0);
  EXPECT_DOUBLE_EQ(norm[2], 1.0);
}

TEST(vec, projection)
{
  double3 const source{1.0, 1.0, 0.0};
  double3 const proj = projection(source, double3{10 * double3X});
  EXPECT_DOUBLE_EQ(proj[0], 1.0);
  EXPECT_DOUBLE_EQ(proj[1], 0.0);
  EXPECT_DOUBLE_EQ(proj[2], 0.0);
}

TEST(vec, rejection)
{
  double3 const source{2.0, 2.0, 0.0};
  double3 const proj = linal::rejection(source, double3{10 * double3X});
  EXPECT_DOUBLE_EQ(proj[0], 0.0);
  EXPECT_DOUBLE_EQ(proj[1], 2.0);
  EXPECT_DOUBLE_EQ(proj[2], 0.0);
}

TEST(vec_collinear, sameDir)
{
  bool isCollinear = collinear(double3Z, double3Z, linal::eps_f64);
  EXPECT_TRUE(isCollinear);
}

TEST(vec_collinear, oppositeDir)
{
  bool isCollinear = collinear(double3Z, double3{-1 * double3Z});
  EXPECT_TRUE(isCollinear);
}

TEST(vec_collinear, orthogonal)
{
  bool isCollinear = collinear(double3Z, double3X);
  EXPECT_FALSE(isCollinear);
}

TEST(vec_collinear, isNormalized)
{
  bool isCollinear = collinear(double3Z, double3{-double3Z});
  EXPECT_TRUE(isCollinear);

  isCollinear = collinear(double3Z, double3X);
  EXPECT_FALSE(isCollinear);
}
