#include <gtest/gtest.h>
#include <linal/HMat.hpp>
#include <linal/HMatRotation.hpp>
#include <linal/HMatTranslation.hpp>
#include <linal/HVec.hpp>
#include <linal/utils/Constants.hpp>
#include <linal/utils/Util.hpp>

using namespace linal;

TEST(hmatOperations, createIdentity)
{
  auto result = hcoord::identity<float_t>();
  EXPECT_TRUE(result.isAligned());
  EXPECT_EQ(result.capacity(), 16);
  for (std::size_t i{0}; i < 4; ++i)
  {
    for (std::size_t j{0}; j < 4; ++j)
    {
      if (i == j)
        EXPECT_FLOAT_EQ(result(i, j), 1.0f);
      else
        EXPECT_FLOAT_EQ(result(i, j), 0.0f);
    }
  }
}

TEST(hmatOperations, xTranslation)
{
  hcoord::hmat<float_t> result = hcoord::create_translation(hcoord::hvec<float_t>{3, 0, 0});
  hcoord::hmat<float_t> expected{{1, 0, 0, 3}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, xRotation)
{
  hcoord::hmat<float_t> hmat = hcoord::rot_x(linal::PI_HALF<float>);
  hcoord::hvec<float_t> start{0, 1, 0, 1};
  hcoord::hvec<float_t> result = hmat * start;
  hcoord::hvec<float_t> expected{0, 0, 1, 1};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, yRotation)
{
  hcoord::hmat<float_t> hmat = hcoord::rot_y(linal::PI_HALF<float>);
  hcoord::hvec<float_t> start{0, 0, 1, 1};
  hcoord::hvec<float_t> result = hmat * start;
  hcoord::hvec<float_t> expected{1, 0, 0, 1};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, zRotation)
{
  hcoord::hmat<float_t> hmat = hcoord::rot_z(linal::PI_HALF<float>);
  hcoord::hvec<float_t> start{1, 0, 0, 1};
  hcoord::hvec<float_t> result = hmat * start;
  hcoord::hvec<float_t> expected{0, 1, 0, 1};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, axisRotation_Y)
{
  hcoord::hmat<float_t> hmat = hcoord::rot_axis(hcoord::hvecf{0, 1, 0, 1}, static_cast<float_t>(linal::PI_HALF<float>));
  hcoord::hvec<float_t> start{0, 0, 1, 1};
  hcoord::hvec<float_t> result = hmat * start;
  hcoord::hvec<float_t> expected{1, 0, 0, 1};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, axisRotation)
{
  Vec3d rotAxis = linal::cross(Vec3d{1, 0, 0}, Vec3d{0, 1, 1});
  hcoord::hmat<double_t> hmat = hcoord::rot_axis(hcoord::vec_to_hvec(rotAxis), linal::PI_HALF<double>);
  Vec3d startVec{0, 1, 1};
  startVec = linal::normalize(startVec);
  hcoord::hvec<double_t> start{startVec[0], startVec[1], startVec[2], 1};
  hcoord::hvec<double_t> result = hmat * start;
  hcoord::hvec<double_t> expected{-1, 0, 0, 1};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, inverseXTranslation)
{
  hcoord::hmat<float_t> xTranslation = hcoord::create_translation(hcoord::hvec<float_t>{3, 0, 0});
  hcoord::hmat<float_t> invXTranslation = hcoord::hMatInverse(xTranslation);

  hcoord::hmat<float_t> expected{{1, 0, 0, -3}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  EXPECT_EQ(invXTranslation, expected);
}

TEST(hmatOperations, rot_align_xTox)
{
  hcoord::hvecd xDir = hcoord::X_HVECD;
  hcoord::hmatd rotMat = hcoord::rot_align(xDir, hcoord::X_HVECD);
  hcoord::hvecd result = rotMat * xDir;
  EXPECT_EQ(hcoord::X_HVECD, result);
}

TEST(hmatOperations, rot_align_xToNormalizedOnes)
{
  hcoord::hvecd xDir = hcoord::X_HVECD;
  hcoord::hvecd targetVec{1, 1, 1, 1};
  double_t vec3Len = hcoord::vec3_norm(targetVec);
  targetVec[0] /= vec3Len;
  targetVec[1] /= vec3Len;
  targetVec[2] /= vec3Len;
  hcoord::hmatd rotMat = hcoord::rot_align(xDir, targetVec);
  hcoord::hvecd result = rotMat * xDir;
  constexpr double_t eps = 1E-7;
  for (std::size_t i{0}; i < 4; ++i)
    EXPECT_TRUE(linal::isEq(result[i], targetVec[i], eps));
}

TEST(hmatOperations, rot_align_xToOnes)
{
  hcoord::hvecd xDir = {1, 0, 0, 1};
  hcoord::hvecd targetVec{1, 1, 1, 1};
  hcoord::hmatd rotMat = hcoord::rot_align(xDir, targetVec);
  hcoord::hvecd result = rotMat * xDir;
  EXPECT_EQ(result, targetVec);
}

TEST(hmatOperations, set_translation)
{
  Vec3d targetVec{0, 0, 1};
  hcoord::hmatd mat = hcoord::identity<double_t>();
  hcoord::set_translation(mat, targetVec);
  hcoord::hvecd start = {0, 0, 0, 1};
  hcoord::hvecd result = mat * start;
  hcoord::hvecd expected{0, 0, 1, 1};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, get_translation)
{
  Vec3d targetVec{0, 0, 1};
  hcoord::hmatd mat = hcoord::identity<double_t>();
  hcoord::set_translation(mat, targetVec);

  Vec3d translation{};
  hcoord::get_translation(mat, translation);

  Vec3d expected{0, 0, 1};
  EXPECT_EQ(translation, expected);
}
