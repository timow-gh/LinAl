#include <gtest/gtest.h>
#include <linal/Mat.hpp>
#include <linal/MatOperations.hpp>
#include <linal/Vec3.hpp>
#include <linal/VecOperations.hpp>
#include <linal/utils/Constants.hpp>

using namespace linal;

Vec3dArray<3> create90DegRotatedLcs()
{
  return {Vec3d{0, 1, 0}, Vec3d{-1, 0, 0}, Vec3d{0, 0, 1}};
}

static void testZRotation(const Vec3d& a, const Matrix3d& rotationMatrix)
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
  Matrix3d rotationMatrix = linal::createLcsTransformation(rotatedLcs[0], rotatedLcs[1], rotatedLcs[2]);

  testZRotation(a, rotationMatrix);
}

TEST(Matrix3dOperations, xRotation)
{
  Matrix3d rotMat = mat3XRot(linal::PI_HALF<double>);
  Vec3d start{0, 1, 0};
  Vec3d result = rotMat * start;
  Vec3d expected{0, 0, 1};
  EXPECT_EQ(result, expected);
}

TEST(Matrix3dOperations, yRotation)
{
  Matrix3d rotMat = mat3YRot(linal::PI_HALF<double>);
  Vec3d start{0, 0, 1};
  Vec3d result = rotMat * start;
  Vec3d expected{1, 0, 0};
  EXPECT_EQ(result, expected);
}

TEST(Matrix3dOperations, zRotation)
{
  Matrix3d rotMat = mat3ZRot(linal::PI_HALF<double>);
  Vec3d start{1, 0, 0};
  Vec3d result = rotMat * start;
  Vec3d expected{0, 1, 0};
  EXPECT_EQ(result, expected);
}

TEST(createLcsToGlobalRotationMatrix_array, Matrix)
{
  Vec3d a{1, 0, 1};
  Vec3dArray<3> lcs = create90DegRotatedLcs();
  Matrix3d rotationMatrix = linal::createLcsTransformation(lcs[0], lcs[1], lcs[2]);

  testZRotation(a, rotationMatrix);
}

TEST(Matrix3Operations, rotationAlign_xToy)
{
  Vec3d xDir = X_VEC3D;
  Matrix3d rotMat = rotationAlign(xDir, Y_VEC3D);
  Vec3d result = rotMat * xDir;
  EXPECT_EQ(Y_VEC3D, result);
}

TEST(Matrix3Operations, rotationAlign_xToz)
{
  Vec3d xDir = X_VEC3D;
  Matrix3d rotMat = rotationAlign(xDir, Z_VEC3D);
  Vec3d result = rotMat * xDir;
  EXPECT_EQ(Z_VEC3D, result);
}

TEST(Matrix3Operations, rotationAlign_xTox)
{
  Vec3d xDir = X_VEC3D;
  Matrix3d rotMat = rotationAlign(xDir, X_VEC3D);
  Vec3d result = rotMat * xDir;
  EXPECT_EQ(X_VEC3D, result);
}

TEST(Matrix3Operations, rotationAlign_xToNormalizedOnes)
{
  Vec3d xDir = X_VEC3D;
  Vec3d targetVec{1, 1, 1};
  targetVec /= linal::norm2(targetVec);
  Matrix3d rotMat = rotationAlign(xDir, targetVec);
  Vec3d result = rotMat * xDir;
  constexpr double_t eps = 1E-7;
  for (std::size_t i{0}; i < 3; ++i)
    EXPECT_TRUE(linal::isEq(result[i], targetVec[i], eps));
}

TEST(Matrix3Operations, rotationAlign_xToOnes)
{
  Vec3d xDir = {1, 0, 0};
  Vec3d targetVec{1, 1, 1};
  Matrix3d rotMat = rotationAlign(xDir, targetVec);
  Vec3d result = rotMat * xDir;
  EXPECT_EQ(result, targetVec);
}
