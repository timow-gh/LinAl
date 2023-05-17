#include <gtest/gtest.h>
#include <linal/Mat.hpp>
#include <linal/MatRotation.hpp>
#include <linal/Vec3.hpp>
#include <linal/VecOperations.hpp>
#include <linal/utils/Constants.hpp>

using namespace linal;

Vec3dArray<3> create90DegRotatedLcs()
{
  return {Vec3d{0, 1, 0}, Vec3d{-1, 0, 0}, Vec3d{0, 0, 1}};
}

static void testZRotation(const Vec3d& a, const mat3d& rotationMatrix)
{
  Vec3d b = rotationMatrix * a;
  Vec3d bExpected{0, 1, 1};
  EXPECT_EQ(b, bExpected);

  Vec3d c = rotationMatrix * b;
  Vec3d cExpected{-1, 0, 1};
  EXPECT_EQ(c, cExpected);

  Vec3d d = rotationMatrix * c;
  Vec3d dExpected{0, -1, 1};
  EXPECT_EQ(d, dExpected);

  Vec3d e = rotationMatrix * d;
  Vec3d eExpected{1, 0, 1};
  EXPECT_EQ(e, eExpected);
}

TEST(createLcsToGlobalRotationMatrix_vectors, Matrix)
{
  Vec3d a{1, 0, 1};
  Vec3dArray<3> rotatedLcs = create90DegRotatedLcs();
  mat3d rotationMatrix = linal::createLcsTransformation(rotatedLcs[0], rotatedLcs[1], rotatedLcs[2]);

  testZRotation(a, rotationMatrix);
}

TEST(Matrix3dOperations, xRotation)
{
  mat3d rotMat = rot_x(linal::PI_HALF<double>);
  Vec3d start{0, 1, 0};
  Vec3d result = rotMat * start;
  Vec3d expected{0, 0, 1};
  EXPECT_EQ(result, expected);
}

TEST(Matrix3dOperations, yRotation)
{
  mat3d rotMat = rot_y(linal::PI_HALF<double>);
  Vec3d start{0, 0, 1};
  Vec3d result = rotMat * start;
  Vec3d expected{1, 0, 0};
  EXPECT_EQ(result, expected);
}

TEST(Matrix3dOperations, zRotation)
{
  mat3d rotMat = rot_z(linal::PI_HALF<double>);
  Vec3d start{1, 0, 0};
  Vec3d result = rotMat * start;
  Vec3d expected{0, 1, 0};
  EXPECT_EQ(result, expected);
}

TEST(createLcsToGlobalRotationMatrix_array, Matrix)
{
  Vec3d a{1, 0, 1};
  Vec3dArray<3> lcs = create90DegRotatedLcs();
  mat3d rotationMatrix = linal::createLcsTransformation(lcs[0], lcs[1], lcs[2]);

  testZRotation(a, rotationMatrix);
}

TEST(Matrix3Operations, rot_align_xToy)
{
  Vec3d xDir = X_VEC3D;
  mat3d rotMat = rot_align(xDir, Y_VEC3D);
  Vec3d result = rotMat * xDir;
  EXPECT_EQ(Y_VEC3D, result);
}

TEST(Matrix3Operations, rot_align_xToz)
{
  Vec3d xDir = X_VEC3D;
  mat3d rotMat = rot_align(xDir, Z_VEC3D);
  Vec3d result = rotMat * xDir;
  EXPECT_EQ(Z_VEC3D, result);
}

TEST(Matrix3Operations, rot_align_xTox)
{
  Vec3d xDir = X_VEC3D;
  mat3d rotMat = rot_align(xDir, X_VEC3D);
  Vec3d result = rotMat * xDir;
  EXPECT_EQ(X_VEC3D, result);
}

TEST(Matrix3Operations, rot_align_xToNormalizedOnes)
{
  Vec3d xDir = X_VEC3D;
  Vec3d targetVec{1, 1, 1};
  targetVec /= linal::norm2(targetVec);
  mat3d rotMat = rot_align(xDir, targetVec);
  Vec3d result = rotMat * xDir;
  constexpr double_t eps = 1E-7;
  for (std::size_t i{0}; i < 3; ++i)
    EXPECT_TRUE(linal::isEq(result[i], targetVec[i], eps));
}

TEST(Matrix3Operations, rot_align_xToOnes)
{
  Vec3d xDir = {1, 0, 0};
  Vec3d targetVec{1, 1, 1};
  mat3d rotMat = rot_align(xDir, targetVec);
  Vec3d result = rotMat * xDir;
  EXPECT_EQ(result, targetVec);
}
