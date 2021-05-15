#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "gtest/gtest.h"

#include "Core/Math/Constants.hpp"

#include "LinAl/LinearAlgebra.hpp"

using namespace LinAl;

TEST(HMatrixOperations, createIdentity) {
  auto result = createIdentityHMatrix<float_t>();
  EXPECT_TRUE(result.isAligned());
  EXPECT_EQ(result.capacity(), 16);
  for (std::size_t i{0}; i < 4; ++i) {
    for (std::size_t j{0}; j < 4; ++j) {
      if (i == j)
        EXPECT_FLOAT_EQ(result(i, j), 1.0f);
      else
        EXPECT_FLOAT_EQ(result(i, j), 0.0f);
    }
  }
}

TEST(HMatrixOperations, xTranslation) {
  HMatrix<float_t> result = createTranslation(HVec<float_t>{3, 0, 0});
  HMatrix<float_t> expected{
      {1, 0, 0, 3}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  EXPECT_EQ(result, expected);
}

TEST(HMatrixOperations, xRotation) {
  HMatrix<float_t> hMatrix = hMatXRot(Core::PI_HALF);
  HVec<float_t> start{0, 1, 0, 1};
  HVec<float_t> result = hMatrix * start;
  HVec<float_t> expected{0, 0, 1, 1};
  EXPECT_EQ(result, expected);
}

TEST(HMatrixOperations, yRotation) {
  HMatrix<float_t> hMatrix = hMatYRot(Core::PI_HALF);
  HVec<float_t> start{0, 0, 1, 1};
  HVec<float_t> result = hMatrix * start;
  HVec<float_t> expected{1, 0, 0, 1};
  EXPECT_EQ(result, expected);
}

TEST(HMatrixOperations, zRotation) {
  HMatrix<float_t> hMatrix = hMatZRot(Core::PI_HALF);
  HVec<float_t> start{1, 0, 0, 1};
  HVec<float_t> result = hMatrix * start;
  HVec<float_t> expected{0, 1, 0, 1};
  EXPECT_EQ(result, expected);
}

TEST(HMatrixOperations, inverseXTranslation) {
  HMatrix<float_t> xTranslation = createTranslation(HVec<float_t>{3, 0, 0});
  HMatrix<float_t> invXTranslation = LinAl::inverse(xTranslation);

  HMatrix<float_t> expected{
      {1, 0, 0, -3}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  EXPECT_EQ(invXTranslation, expected);
}

#pragma clang diagnostic pop