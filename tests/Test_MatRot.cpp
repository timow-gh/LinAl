#include <gtest/gtest.h>
#include <linal/linal.hpp>

using namespace linal;

TEST(matRot, rotX90Degrees)
{
  double33 rotMat;
  rot_x(rotMat, linal::PI_HALF<double>);
  double3 start{0.0, 1.0, 0.0};
  double3 result = rotMat * start;
  double3 expected{0.0, 0.0, 1.0};
  constexpr double_t eps = 1E-9;
  using size_type = double3::size_type;
  for (size_type i{0}; i < 3; ++i)
  {
    EXPECT_TRUE(linal::isEq(result[i], expected[i], eps));
  }
}

TEST(matRot, rotY90Degrees)
{
  double33 rotMat;
  rot_y(rotMat, linal::PI_HALF<double>);
  double3 start{1.0, 0.0, 0.0};
  double3 result = rotMat * start;
  double3 expected{0.0, 0.0, -1.0};
  constexpr double_t eps = 1E-9;
  using size_type = double3::size_type;
  for (size_type i{0}; i < 3; ++i)
  {
    EXPECT_TRUE(linal::isEq(result[i], expected[i], eps));
  }
}

TEST(matRot, rotZ90Degrees)
{
  double33 rotMat;
  rot_z(rotMat, linal::PI_HALF<double>);
  double3 start{1.0, 0.0, 0.0};
  double3 result = rotMat * start;
  double3 expected{0.0, 1.0, 0.0};
  constexpr double_t eps = 1E-9;
  using size_type = double3::size_type;
  for (size_type i{0}; i < 3; ++i)
  {
    EXPECT_TRUE(linal::isEq(result[i], expected[i], eps));
  }
}

TEST(matRot, rotAxisMatchesRotZForZAxis)
{
  const double angle = linal::PI_HALF<double> * 0.5;

  double33 rotMatAxis;
  rot_axis(rotMatAxis, vec3<double>{0.0, 0.0, 1.0}, angle);

  double33 rotMatZ;
  rot_z(rotMatZ, angle);

  constexpr double_t eps = 1E-9;
  using size_type = double33::size_type;
  for (size_type i{0}; i < 3; ++i)
  {
    for (size_type j{0}; j < 3; ++j)
    {
      EXPECT_TRUE(linal::isEq(rotMatAxis(i, j), rotMatZ(i, j), eps));
    }
  }
}

TEST(matRot, rotAxisFullTurnIsIdentity)
{
  double33 rotMat;
  const vec3<double> axis = linal::normalize(vec3<double>{1.0, 1.0, 1.0});
  rot_axis(rotMat, axis, linal::PI_2<double>);

  const double33 identity = double33::identity();
  constexpr double_t eps = 1E-9;
  using size_type = double33::size_type;
  for (size_type i{0}; i < 3; ++i)
  {
    for (size_type j{0}; j < 3; ++j)
    {
      EXPECT_TRUE(linal::isEq(rotMat(i, j), identity(i, j), eps));
    }
  }
}

TEST(matRot, transformationFromLcsVectorsColumns)
{
  const double3 x{0.0, 1.0, 0.0};
  const double3 y{-1.0, 0.0, 0.0};
  const double3 z{0.0, 0.0, 1.0};

  double33 transformation;
  transformation_from_lcs_vectors(transformation, x, y, z);

  EXPECT_DOUBLE_EQ(transformation(0, 0), x[0]);
  EXPECT_DOUBLE_EQ(transformation(1, 0), x[1]);
  EXPECT_DOUBLE_EQ(transformation(2, 0), x[2]);

  EXPECT_DOUBLE_EQ(transformation(0, 1), y[0]);
  EXPECT_DOUBLE_EQ(transformation(1, 1), y[1]);
  EXPECT_DOUBLE_EQ(transformation(2, 1), y[2]);

  EXPECT_DOUBLE_EQ(transformation(0, 2), z[0]);
  EXPECT_DOUBLE_EQ(transformation(1, 2), z[1]);
  EXPECT_DOUBLE_EQ(transformation(2, 2), z[2]);
}
