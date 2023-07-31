#include <gtest/gtest.h>
#include <linal/hmat.hpp>
#include <linal/hmat_rotation.hpp>
#include <linal/hmat_transformations.hpp>
#include <linal/hmat_translation.hpp>
#include <linal/hvec.hpp>
#include <linal/utils/constants.hpp>
#include <linal/utils/util.hpp>

TEST(hmatOperations, createIdentity)
{
  auto result = linal::hcoord::identity<float_t>();
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
  linal::hcoord::hmat<float_t> result = linal::hcoord::hmat_translation(linal::hcoord::hvec<float_t>{3, 0, 0});
  linal::hcoord::hmat<float_t> expected{{1, 0, 0, 3}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, xRotation)
{
  linal::hcoord::hmat<float_t> hmat = linal::hcoord::rot_x(linal::PI_HALF<float>);
  linal::hcoord::hvec<float_t> start{0, 1, 0, 1};
  linal::hcoord::hvec<float_t> result = hmat * start;
  linal::hcoord::hvec<float_t> expected{0, 0, 1, 1};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, yRotation)
{
  linal::hcoord::hmat<float_t> hmat = linal::hcoord::rot_y(linal::PI_HALF<float>);
  linal::hcoord::hvec<float_t> start{0, 0, 1, 1};
  linal::hcoord::hvec<float_t> result = hmat * start;
  linal::hcoord::hvec<float_t> expected{1, 0, 0, 1};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, zRotation)
{
  linal::hcoord::hmat<float_t> hmat = linal::hcoord::rot_z(linal::PI_HALF<float>);
  linal::hcoord::hvec<float_t> start{1, 0, 0, 1};
  linal::hcoord::hvec<float_t> result = hmat * start;
  linal::hcoord::hvec<float_t> expected{0, 1, 0, 1};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, axisRotation_Y)
{
  linal::hcoord::hmat<float_t> hmat =
      linal::hcoord::rot_axis(linal::hcoord::hvecf{0, 1, 0, 1}, static_cast<float_t>(linal::PI_HALF<float>));
  linal::hcoord::hvec<float_t> start{0, 0, 1, 1};
  linal::hcoord::hvec<float_t> result = hmat * start;
  linal::hcoord::hvec<float_t> expected{1, 0, 0, 1};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, axisRotation)
{
  linal::vec3d rotAxis = linal::cross(linal::vec3d{1, 0, 0}, linal::vec3d{0, 1, 1});
  linal::hcoord::hmat<double_t> hmat = linal::hcoord::rot_axis(linal::hcoord::vec_to_hvec(rotAxis), linal::PI_HALF<double>);
  linal::vec3d startvec{0, 1, 1};
  startvec = linal::normalize(startvec);
  linal::hcoord::hvec<double_t> start{startvec[0], startvec[1], startvec[2], 1};
  linal::hcoord::hvec<double_t> result = hmat * start;
  linal::hcoord::hvec<double_t> expected{-1, 0, 0, 1};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, inverseXTranslation)
{
  linal::hcoord::hmat<float_t> xTranslation = linal::hcoord::hmat_translation(linal::hcoord::hvec<float_t>{3, 0, 0});
  linal::hcoord::hmat<float_t> invXTranslation = linal::hcoord::hMatInverse(xTranslation);

  linal::hcoord::hmat<float_t> expected{{1, 0, 0, -3}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  EXPECT_EQ(invXTranslation, expected);
}

TEST(hmatOperations, rot_align_xTox)
{
  linal::hcoord::hvecd xDir = linal::hcoord::X_HVECD;
  linal::hcoord::hmatd rotMat = linal::hcoord::rot_align(xDir, linal::hcoord::X_HVECD);
  linal::hcoord::hvecd result = rotMat * xDir;
  EXPECT_EQ(linal::hcoord::X_HVECD, result);
}

TEST(hmatOperations, rot_align_xToNormalizedOnes)
{
  linal::hcoord::hvecd xDir = linal::hcoord::X_HVECD;
  linal::hcoord::hvecd targetvec{1, 1, 1, 1};
  double_t vec3Len = linal::hcoord::vec3_norm(targetvec);
  targetvec[0] /= vec3Len;
  targetvec[1] /= vec3Len;
  targetvec[2] /= vec3Len;
  linal::hcoord::hmatd rotMat = linal::hcoord::rot_align(xDir, targetvec);
  linal::hcoord::hvecd result = rotMat * xDir;
  constexpr double_t eps = 1E-7;
  for (std::size_t i{0}; i < 4; ++i)
    EXPECT_TRUE(linal::isEq(result[i], targetvec[i], eps));
}

TEST(hmatOperations, rot_align_xToOnes)
{
  linal::hcoord::hvecd xDir = {1, 0, 0, 1};
  linal::hcoord::hvecd targetvec{1, 1, 1, 1};
  linal::hcoord::hmatd rotMat = linal::hcoord::rot_align(xDir, targetvec);
  linal::hcoord::hvecd result = rotMat * xDir;
  EXPECT_EQ(result, targetvec);
}

TEST(hmatOperations, set_translation)
{
  linal::vec3d targetvec{0, 0, 1};
  linal::hcoord::hmatd mat = linal::hcoord::identity<double_t>();
  linal::hcoord::set_translation(mat, targetvec);
  linal::hcoord::hvecd start = {0, 0, 0, 1};
  linal::hcoord::hvecd result = mat * start;
  linal::hcoord::hvecd expected{0, 0, 1, 1};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, get_translation)
{
  linal::vec3d targetvec{0, 0, 1};
  linal::hcoord::hmatd mat = linal::hcoord::identity<double_t>();
  linal::hcoord::set_translation(mat, targetvec);

  linal::vec3d translation{};
  linal::hcoord::get_translation(mat, translation);

  linal::vec3d expected{0, 0, 1};
  EXPECT_EQ(translation, expected);
}

TEST(hmatOperations, hmat_rot_translate)
{
  linal::vec3d axis{0.0, 0.0, 1.0};
  double angle = linal::PI_HALF<double>;
  linal::vec3d translation{0.0, 0.0, 1.0};
  linal::hcoord::hmatd rotMat = linal::hcoord::hmat_rot_translate(axis, angle, translation);

  linal::hcoord::hvecd start{1, 0, 0, 1};
  linal::hcoord::hvecd result = rotMat * start;

  linal::hcoord::hvecd expected{0, 1, 1, 1};
  EXPECT_EQ(result, expected);
}
