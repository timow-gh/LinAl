#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "gtest/gtest.h"
#include <iostream>

#include "Core/Math/Constants.hpp"

#include "LinAl/LinearAlgebra.hpp"

using namespace LinAl;

Vec3dArray<3> create90DegRotatedLcs() {
  return Vec3dArray<3>{Vec3d{0, 1, 0}, Vec3d{-1, 0, 0}, Vec3d{0, 0, 1}};
}

void testZRotation(const Vec3d &a, const Matrix3d &rotationMatrix) {
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

TEST(createLcsToGlobalRotationMatrix_vectors, Matrix) {
  Vec3d a{1, 0, 1};
  auto rotatedLcs = create90DegRotatedLcs();
  Matrix3d rotationMatrix = LinAl::createLcsTransformation(
      rotatedLcs[0], rotatedLcs[1], rotatedLcs[2]);

  testZRotation(a, rotationMatrix);
}

TEST(Matrix3dOperations, xRotation) {
  Matrix3d rotMat = hMatXRot(Core::PI_HALF);
  Vec3d start{0, 1, 0};
  Vec3d result = rotMat * start;
  Vec3d expected{0, 0, 1};
  EXPECT_EQ(result, expected);
}

TEST(Matrix3dOperations, yRotation) {
  Matrix3d rotMat = hMatYRot(Core::PI_HALF);
  Vec3d start{0, 0, 1};
  Vec3d result = rotMat * start;
  Vec3d expected{1, 0, 0};
  EXPECT_EQ(result, expected);
}

TEST(Matrix3dOperations, zRotation) {
  Matrix3d rotMat = hMatZRot(Core::PI_HALF);
  Vec3d start{1, 0, 0};
  Vec3d result = rotMat * start;
  Vec3d expected{0, 1, 0};
  EXPECT_EQ(result, expected);
}

TEST(createLcsToGlobalRotationMatrix_array, Matrix) {
  Vec3d a{1, 0, 1};
  Matrix3d rotationMatrix =
      LinAl::createLcsTransformation(create90DegRotatedLcs());

  testZRotation(a, rotationMatrix);
}

#pragma clang diagnostic pop