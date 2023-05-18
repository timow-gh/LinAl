#include <gtest/gtest.h>
#include <linal/mat.hpp>
#include <linal/mat_rot.hpp>
#include <linal/utils/constants.hpp>
#include <linal/vec3.hpp>
#include <linal/vec_operations.hpp>

using namespace linal;

vec3dArray<3> create90DegRotatedLcs()
{
  return {vec3d{0, 1, 0}, vec3d{-1, 0, 0}, vec3d{0, 0, 1}};
}

static void testZRotation(const vec3d& a, const mat3d& rotationMatrix)
{
  vec3d b = rotationMatrix * a;
  vec3d bExpected{0, 1, 1};
  EXPECT_EQ(b, bExpected);

  vec3d c = rotationMatrix * b;
  vec3d cExpected{-1, 0, 1};
  EXPECT_EQ(c, cExpected);

  vec3d d = rotationMatrix * c;
  vec3d dExpected{0, -1, 1};
  EXPECT_EQ(d, dExpected);

  vec3d e = rotationMatrix * d;
  vec3d eExpected{1, 0, 1};
  EXPECT_EQ(e, eExpected);
}

TEST(createLcsToGlobalRotationMatrix_vectors, Matrix)
{
  vec3d a{1, 0, 1};
  vec3dArray<3> rotatedLcs = create90DegRotatedLcs();
  mat3d rotationMatrix = linal::createLcsTransformation(rotatedLcs[0], rotatedLcs[1], rotatedLcs[2]);

  testZRotation(a, rotationMatrix);
}

TEST(Matrix3dOperations, xRotation)
{
  mat3d rotMat = rot_x(linal::PI_HALF<double>);
  vec3d start{0, 1, 0};
  vec3d result = rotMat * start;
  vec3d expected{0, 0, 1};
  EXPECT_EQ(result, expected);
}

TEST(Matrix3dOperations, yRotation)
{
  mat3d rotMat = rot_y(linal::PI_HALF<double>);
  vec3d start{0, 0, 1};
  vec3d result = rotMat * start;
  vec3d expected{1, 0, 0};
  EXPECT_EQ(result, expected);
}

TEST(Matrix3dOperations, zRotation)
{
  mat3d rotMat = rot_z(linal::PI_HALF<double>);
  vec3d start{1, 0, 0};
  vec3d result = rotMat * start;
  vec3d expected{0, 1, 0};
  EXPECT_EQ(result, expected);
}

TEST(createLcsToGlobalRotationMatrix_array, Matrix)
{
  vec3d a{1, 0, 1};
  vec3dArray<3> lcs = create90DegRotatedLcs();
  mat3d rotationMatrix = linal::createLcsTransformation(lcs[0], lcs[1], lcs[2]);

  testZRotation(a, rotationMatrix);
}

TEST(Matrix3Operations, rot_align_xToy)
{
  vec3d xDir = X_VEC3D;
  mat3d rotMat = rot_align(xDir, Y_VEC3D);
  vec3d result = rotMat * xDir;
  EXPECT_EQ(Y_VEC3D, result);
}

TEST(Matrix3Operations, rot_align_xToz)
{
  vec3d xDir = X_VEC3D;
  mat3d rotMat = rot_align(xDir, Z_VEC3D);
  vec3d result = rotMat * xDir;
  EXPECT_EQ(Z_VEC3D, result);
}

TEST(Matrix3Operations, rot_align_xTox)
{
  vec3d xDir = X_VEC3D;
  mat3d rotMat = rot_align(xDir, X_VEC3D);
  vec3d result = rotMat * xDir;
  EXPECT_EQ(X_VEC3D, result);
}

TEST(Matrix3Operations, rot_align_xToNormalizedOnes)
{
  vec3d xDir = X_VEC3D;
  vec3d targetvec{1, 1, 1};
  targetvec /= linal::norm2(targetvec);
  mat3d rotMat = rot_align(xDir, targetvec);
  vec3d result = rotMat * xDir;
  constexpr double_t eps = 1E-7;
  for (std::size_t i{0}; i < 3; ++i)
    EXPECT_TRUE(linal::isEq(result[i], targetvec[i], eps));
}

TEST(Matrix3Operations, rot_align_xToOnes)
{
  vec3d xDir = {1, 0, 0};
  vec3d targetvec{1, 1, 1};
  mat3d rotMat = rot_align(xDir, targetvec);
  vec3d result = rotMat * xDir;
  EXPECT_EQ(result, targetvec);
}
