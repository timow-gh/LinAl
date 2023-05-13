#include <linal/Vec3.hpp>
#include <linal/VecOperations.hpp>
#include <gtest/gtest.h>

using namespace linal;

TEST(Vec_dot, dot_same_dir)
{
  double dotP = dot(Z_VEC3D, Z_VEC3D);
  EXPECT_DOUBLE_EQ(dotP, 1.0);
}

TEST(Vec_dot, dot_orthogonal)
{
  double dotP = dot(X_VEC3D, Z_VEC3D);
  EXPECT_DOUBLE_EQ(dotP, 0.0);
}

TEST(Vec_dot, dot_opposite_dir)
{
  double dotP = dot(-Z_VEC3D, Z_VEC3D);
  EXPECT_DOUBLE_EQ(dotP, -1.0);
}

TEST(Vec_cross, cross_same_dir)
{
  Vec3d crossP = cross(Z_VEC3D, Z_VEC3D);
  EXPECT_DOUBLE_EQ(crossP[0], 0.0);
  EXPECT_DOUBLE_EQ(crossP[1], 0.0);
  EXPECT_DOUBLE_EQ(crossP[2], 0.0);
}

TEST(Vec_cross, cross)
{
  Vec3d crossP = cross(X_VEC3D, Y_VEC3D);
  EXPECT_DOUBLE_EQ(crossP[0], 0.0);
  EXPECT_DOUBLE_EQ(crossP[1], 0.0);
  EXPECT_DOUBLE_EQ(crossP[2], 1.0);
}

TEST(Vec_cross, cross_opposite_dir)
{
  Vec3d crossP = cross(-Z_VEC3D, Z_VEC3D);
  EXPECT_DOUBLE_EQ(crossP[0], 0.0);
  EXPECT_DOUBLE_EQ(crossP[1], 0.0);
  EXPECT_DOUBLE_EQ(crossP[2], 0.0);
}

TEST(Vec_norm2Squared, norm2Squared)
{
  double norm2Squared = linal::norm2Squared(Vec3d{3 * Z_VEC3D});
  EXPECT_DOUBLE_EQ(norm2Squared, 9.0);
}

TEST(Vec_norm2, norm2)
{
  double norm2 = linal::norm2(Vec3d{3 * Z_VEC3D});
  EXPECT_DOUBLE_EQ(norm2, 3);
}

TEST(Vec_normalize, normalize)
{
  Vec3d norm = linal::normalize(Vec3d{3 * Z_VEC3D});
  EXPECT_DOUBLE_EQ(norm[0], 0.0);
  EXPECT_DOUBLE_EQ(norm[1], 0.0);
  EXPECT_DOUBLE_EQ(norm[2], 1.0);
}

TEST(Vec_projection, projection)
{
  Vec3d const source{1, 1, 0};
  Vec3d const proj = linal::projection(source, Vec3d{10 * X_VEC3D});
  EXPECT_DOUBLE_EQ(proj[0], 1.0);
  EXPECT_DOUBLE_EQ(proj[1], 0.0);
  EXPECT_DOUBLE_EQ(proj[2], 0.0);
}

TEST(Vec_rejection, rejection)
{
  Vec3d const source{2, 2, 0};
  Vec3d const proj = linal::rejection(source, Vec3d{10 * X_VEC3D});
  EXPECT_DOUBLE_EQ(proj[0], 0.0);
  EXPECT_DOUBLE_EQ(proj[1], 2.0);
  EXPECT_DOUBLE_EQ(proj[2], 0.0);
}

TEST(Vec_collinear, sameDir)
{
  bool isCollinear = collinear(Z_VEC3D, Z_VEC3D, linal::eps_f64);
  EXPECT_TRUE(isCollinear);
}

TEST(Vec_collinear, oppositeDir)
{
  bool isCollinear = collinear(Z_VEC3D, Vec3d{-1 * Z_VEC3D});
  EXPECT_TRUE(isCollinear);
}

TEST(Vec_collinear, orthogonal)
{
  bool isCollinear = collinear(Z_VEC3D, X_VEC3D);
  EXPECT_FALSE(isCollinear);
}

TEST(Vec_collinear, isNormalized)
{
  bool isCollinear = collinear(Z_VEC3D, Vec3d{-Z_VEC3D});
  EXPECT_TRUE(isCollinear);

  isCollinear = collinear(Z_VEC3D, X_VEC3D);
  EXPECT_FALSE(isCollinear);
}
