#include <LinAl/LinearAlgebra.hpp>
#include <gtest/gtest.h>
#include <iostream>

using namespace LinAl;

class DotProductFixture : public ::testing::Test {
  protected:
    Vec3d m_vec3d{LinAl::X_VEC3D};
};

TEST_F(DotProductFixture, collinear)
{
    auto dotP = dot(LinAl::X_VEC3D, m_vec3d);
    EXPECT_DOUBLE_EQ(dotP, 1.0);
}

TEST_F(DotProductFixture, orthogonal)
{
    auto dotP = dot(LinAl::Y_VEC3D, m_vec3d);
    EXPECT_DOUBLE_EQ(dotP, 0.0);
}

TEST_F(DotProductFixture, collinearOppositeDir)
{
    auto dotP = dot(-LinAl::X_VEC3D, m_vec3d);
    EXPECT_DOUBLE_EQ(dotP, -1.0);
}
