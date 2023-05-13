#include <linal/Vec3.hpp>
#include <gtest/gtest.h>

using namespace linal;

class DotProductFixture : public ::testing::Test {
protected:
  Vec3d m_vec3d{linal::X_VEC3D};
};

TEST_F(DotProductFixture, collinear)
{
  auto dotP = dot(linal::X_VEC3D, m_vec3d);
  EXPECT_DOUBLE_EQ(dotP, 1.0);
}

TEST_F(DotProductFixture, orthogonal)
{
  auto dotP = dot(linal::Y_VEC3D, m_vec3d);
  EXPECT_DOUBLE_EQ(dotP, 0.0);
}

TEST_F(DotProductFixture, collinearOppositeDir)
{
  auto dotP = dot(-linal::X_VEC3D, m_vec3d);
  EXPECT_DOUBLE_EQ(dotP, -1.0);
}
