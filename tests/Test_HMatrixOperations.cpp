#include <gtest/gtest.h>
#include <linal/hmat.hpp>
#include <linal/hmat_rotation.hpp>
#include <linal/hmat_translation.hpp>
#include <linal/hvec.hpp>
#include <linal/utils/constants.hpp>
#include <linal/utils/util.hpp>

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
  vec3d rotAxis = linal::cross(vec3d{1, 0, 0}, vec3d{0, 1, 1});
  hcoord::hmat<double_t> hmat = hcoord::rot_axis(hcoord::vec_to_hvec(rotAxis), linal::PI_HALF<double>);
  vec3d startvec{0, 1, 1};
  startvec = linal::normalize(startvec);
  hcoord::hvec<double_t> start{startvec[0], startvec[1], startvec[2], 1};
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
  hcoord::hvecd targetvec{1, 1, 1, 1};
  double_t vec3Len = hcoord::vec3_norm(targetvec);
  targetvec[0] /= vec3Len;
  targetvec[1] /= vec3Len;
  targetvec[2] /= vec3Len;
  hcoord::hmatd rotMat = hcoord::rot_align(xDir, targetvec);
  hcoord::hvecd result = rotMat * xDir;
  constexpr double_t eps = 1E-7;
  for (std::size_t i{0}; i < 4; ++i)
    EXPECT_TRUE(linal::isEq(result[i], targetvec[i], eps));
}

TEST(hmatOperations, rot_align_xToOnes)
{
  hcoord::hvecd xDir = {1, 0, 0, 1};
  hcoord::hvecd targetvec{1, 1, 1, 1};
  hcoord::hmatd rotMat = hcoord::rot_align(xDir, targetvec);
  hcoord::hvecd result = rotMat * xDir;
  EXPECT_EQ(result, targetvec);
}

TEST(hmatOperations, set_translation)
{
  vec3d targetvec{0, 0, 1};
  hcoord::hmatd mat = hcoord::identity<double_t>();
  hcoord::set_translation(mat, targetvec);
  hcoord::hvecd start = {0, 0, 0, 1};
  hcoord::hvecd result = mat * start;
  hcoord::hvecd expected{0, 0, 1, 1};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, get_translation)
{
  vec3d targetvec{0, 0, 1};
  hcoord::hmatd mat = hcoord::identity<double_t>();
  hcoord::set_translation(mat, targetvec);

  vec3d translation{};
  hcoord::get_translation(mat, translation);

  vec3d expected{0, 0, 1};
  EXPECT_EQ(translation, expected);
}
