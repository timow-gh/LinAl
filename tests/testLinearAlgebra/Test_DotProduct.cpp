#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "gtest/gtest.h"
#include <iostream>

#include "LinAl/LinearAlgebra.hpp"

using namespace LinAl;

class DotProductFixture : public ::testing::Test {
protected:
  Vec3d m_vec3d{LinAl::X_VEC3D};
};

TEST_F(DotProductFixture, collinear) {
  auto dotP = dot(LinAl::X_VEC3D, m_vec3d);
  EXPECT_DOUBLE_EQ(dotP, 1.0);
}

TEST_F(DotProductFixture, orthogonal) {
  auto dotP = dot(LinAl::Y_VEC3D, m_vec3d);
  EXPECT_DOUBLE_EQ(dotP, 0.0);
}

TEST_F(DotProductFixture, collinearOppositeDir) {
  auto dotP = dot(-LinAl::X_VEC3D, m_vec3d);
  EXPECT_DOUBLE_EQ(dotP, -1.0);
}

#pragma clang diagnostic pop