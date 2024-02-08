#include <gtest/gtest.h>
#include <linal/hmat.hpp>
#include <linal/utils/constants.hpp>
#include <linal/vec_operations.hpp>

TEST(hmatOperations, createIdentity)
{
  auto result = linal::hmatf::identity();
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

TEST(hmatOperations, constructor_translation)
{
  linal::hvecf translation{1.0f, 2.0f, 3.0f, 1.0f};
  linal::hmatf mat{translation};
  linal::hvecf result = mat.get_translation();
  EXPECT_EQ(translation, result);

  linal::float3 vec{1.0f, 2.0f, 3.0f};
  mat = linal::hmatf{vec};
  result = mat.get_translation();
  linal::hvecf expected{1.0f, 2.0f, 3.0f, 1.0f};
  EXPECT_EQ(expected, result);
}

TEST(hmatOperations, xTranslation)
{
  linal::hvecf expected({3.0f, 0.0f, 0.0f, 1.0f});
  linal::hmatf mat = linal::hmatf::from_rows({linal::hvecf{1.0f, 0.0f, 0.0f, 3.0f},
                                              linal::hvecf{0.0f, 1.0f, 0.0f, 0.0f},
                                              linal::hvecf{0.0f, 0.0f, 1.0f, 0.0f},
                                              linal::hvecf{0.0f, 0.0f, 0.0f, 1.0f}});
  linal::hvecf translation = mat.get_translation();
  EXPECT_EQ(expected, translation);
}

TEST(hmatOperations, from_columns)
{
  linal::hmatf matrix = linal::hmatf::from_columns({linal::hvecf{1.0f, 0.0f, 0.0f, 0.0f},
                                                    linal::hvecf{0.0f, 1.0f, 0.0f, 0.0f},
                                                    linal::hvecf{0.0f, 0.0f, 1.0f, 0.0f},
                                                    linal::hvecf{3.0f, 0.0f, 0.0f, 1.0f}});
  linal::hvecf expected{3.0f, 0.0f, 0.0f, 1.0f};
  linal::hvecf translation = matrix.get_translation();
  EXPECT_EQ(expected, translation);

  linal::hmatf expectedMat = linal::hmatf::identity();
  expectedMat(0, 3) = 3.0f;
  EXPECT_EQ(matrix, expectedMat);
}

TEST(hmatOperations, xRotation)
{
  linal::hmatf hmat = linal::hmatf::rot_x(linal::PI_HALF<float>);
  linal::hvecf start{0.0f, 1.0f, 0.0f, 1.0f};
  linal::hvecf result = hmat * start;
  linal::hvecf expected{0.0f, 0.0f, 1.0f, 1.0f};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, yRotation)
{
  linal::hmatf hmat = linal::hmatf::rot_y(linal::PI_HALF<float>);
  linal::hvecf start{0.0f, 0.0f, 1.0f, 1.0f};
  linal::hvecf result = hmat * start;
  linal::hvecf expected{1.0f, 0.0f, 0.0f, 1.0f};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, zRotation)
{
  linal::hmatf hmat = linal::hmatf::rot_z(linal::PI_HALF<float>);
  linal::hvecf start{1.0f, 0.0f, 0.0f, 1.0f};
  linal::hvecf result = hmat * start;
  linal::hvecf expected{0.0f, 1.0f, 0.0f, 1.0f};
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, axisRotation)
{
  linal::double3 rotAxis = linal::cross(linal::double3{1.0, 0.0, 0.0}, linal::double3{0.0, 1.0, 1.0});
  linal::hmatd matrix;
  linal::rot_axis(matrix, rotAxis, linal::PI_HALF<double>);
  linal::double3 startvec{0.0, 1.0, 1.0};
  startvec = startvec.normalize();
  linal::hvecd start{startvec[0], startvec[1], startvec[2], 1.0};
  linal::hvecd result = matrix * start;
  linal::hvecd expected{-1.0, 0.0, 0.0, 1.0};
  EXPECT_EQ(result, expected);
}

// TEST(hmatOperations, inverseXTranslation)
//{
//  linal::hmatf xTranslation = linal::hmat_translation(linal::hvecf{3, 0, 0});
//  linal::hmatf invXTranslation = linal::hMatInverse(xTranslation);
//
//  linal::hmatf expected{{1, 0, 0, -3}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
//  EXPECT_EQ(invXTranslation, expected);
//}

TEST(hmatOperations, rot_align_xTox)
{
  linal::hmatd rotMat = linal::hmatd::identity();
  linal::rot_align(rotMat, linal::double3X, linal::double3X);
  linal::hvecd result = rotMat * linal::hvecdx;
  EXPECT_EQ(linal::hvecdx, result);
}

TEST(hmatOperations, rot_align_xToNormalizedOnes)
{
  auto xDir = linal::hvecdx;
  auto target = linal::double3{1.0, 1.0, 1.0};
  double_t vec3Len = linal::length(target);
  target[0] /= vec3Len;
  target[1] /= vec3Len;
  target[2] /= vec3Len;
  linal::hmatd rotMat;
  linal::rot_align(rotMat, xDir, target);
  linal::hvecd result = rotMat * xDir;
  constexpr double_t eps = 1E-7;
  constexpr auto size = std::min(xDir.dim, target.dim);
  for (std::size_t i{0}; i < size; ++i)
    EXPECT_TRUE(linal::isEq(result[i], target[i], eps));
}

TEST(hmatOperations, rot_align_xToOnes)
{
  linal::hvecd xDir = {1.0, 0.0, 0.0, 1.0};
  linal::hvecd targetvec{1.0, 1.0, 1.0, 1.0};
  linal::hmatd rotMat;
  linal::rot_align(rotMat, xDir, targetvec);
  linal::hvecd result = rotMat * xDir;
  EXPECT_EQ(result, targetvec);
}

TEST(hmatOperations, set_translation)
{
  linal::double3 targetvec(0.0, 0.0, 1.0);
  linal::hmatd mat = linal::hmatd::identity();
  mat.set_translation(targetvec);
  linal::hvecd start(0.0, 0.0, 0.0, 1.0);
  linal::hvecd result = mat * start;
  linal::hvecd expected(0.0, 0.0, 1.0, 1.0);
  EXPECT_EQ(result, expected);
}

TEST(hmatOperations, get_translation)
{
  linal::double3 targetvec{0, 0, 1};
  linal::hmatd mat = linal::hmatd::identity();
  mat.set_translation(targetvec);

  linal::hvecd translation = mat.get_translation();

  linal::hvecd expected(0.0, 0.0, 1.0, 1.0);
  EXPECT_EQ(translation, expected);
}

TEST(hmatOperations, hmat_rot_translate)
{
  linal::double3 axis{0.0, 0.0, 1.0};
  double angle = linal::PI_HALF<double>;
  linal::double3 translation{0.0, 0.0, 1.0};
  linal::hmatd rotMat = linal::rot_translate(axis, angle, translation);

  linal::hvecd start{1, 0, 0, 1};
  linal::hvecd result = rotMat * start;

  linal::hvecd expected{0, 1, 1, 1};
  EXPECT_EQ(result, expected);
}
