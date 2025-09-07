#include <gtest/gtest.h>
#include <linal/linal.hpp>

using namespace linal;

TEST(quat, create)
{
  auto quat = quatd::create(1.0, 0.0, 0.0, linal::PI_D);
  EXPECT_NEAR(quat.w(), 0.0, 1e-10);
  EXPECT_NEAR(quat.x(), 1.0, 1e-10);
  EXPECT_NEAR(quat.y(), 0.0, 1e-10);
  EXPECT_NEAR(quat.z(), 0.0, 1e-10);
}

TEST(quat, length)
{
  auto quat = quatd::create(1.0, 0.0, 0.0, linal::PI_D);
  double len = quat.length();
  EXPECT_NEAR(len, 1.0, 1e-10);
}

TEST(quat, is_normalized)
{
  auto quat = quatd::create(1.0, 0.0, 0.0, linal::PI_D);
  EXPECT_TRUE(quat.is_normalized());
}

TEST(quat, dot)
{
  auto q1 = quatd::create(1.0, 1.0, 1.0, linal::PI_D);
  auto q2 = quatd::create(1.0, 1.0, 1.0, linal::PI_D);
  double dotProd = q1.dot(q2);
  EXPECT_DOUBLE_EQ(dotProd, 1.0);

  q2 = quatd::create(1.0, 1.0, 1.0, -linal::PI_D);
  dotProd = q1.dot(q2);
  EXPECT_DOUBLE_EQ(dotProd, -1.0);

  q2 = quatd::create(1.0, 1.0, 1.0, 0.0);
  dotProd = q1.dot(q2);
  EXPECT_NEAR(dotProd, 0.0, 1e-10);
}

TEST(quat, conjugate)
{
  auto quat = quatd::create(1.0, 2.0, 3.0, 4.0);
  auto conjQuat = quat.conjugate();
  EXPECT_DOUBLE_EQ(quat.w(), conjQuat.w());
  EXPECT_DOUBLE_EQ(quat.x(), -conjQuat.x());
  EXPECT_DOUBLE_EQ(quat.y(), -conjQuat.y());
  EXPECT_DOUBLE_EQ(quat.z(), -conjQuat.z());
}

TEST(quat, angle)
{
  auto q1 = quatd::create(1.0, 0.0, 0.0, 0.0);
  auto q2 = quatd::create(1.0, 0.0, 0.0, 0.0);
  double angle = q1.angle(q2);
  EXPECT_NEAR(angle, 0.0, 1e-10);

  q2 = quatd::create(1.0, 0.0, 0.0, linal::PI_D);
  angle = q1.angle(q2);
  EXPECT_NEAR(angle, linal::PI_D, 1e-10);

  q2 = quatd::create(1.0, 0.0, 0.0, linal::PI_2_D);
  angle = q1.angle(q2);
  EXPECT_NEAR(angle, linal::PI_2_D, 1e-10);

  q2 = quatd::create(0.0, 1.0, 0.0, linal::PI_HALF_D);
  angle = q1.angle(q2);
  EXPECT_NEAR(angle, linal::PI_HALF_D, 1e-10);
}

TEST(quat, rotate)
{
  quaternion quat = quatd::create(0.0, 0.0, 1.0, linal::PI_HALF_D);
  linal::double3 vec = quat.rotate(1.0, 0.0, 0.0);
  EXPECT_NEAR(vec[0], 0.0, 1e-10);
  EXPECT_NEAR(vec[1], 1.0, 1e-10);
  EXPECT_NEAR(vec[2], 0.0, 1e-10);

  quat = quatd::create(0.0, 1.0, 0.0, linal::PI_HALF_D);
  vec = quat.rotate(0.0, 0.0, 1.0);
  EXPECT_NEAR(vec[0], 1.0, 1e-10);
  EXPECT_NEAR(vec[1], 0.0, 1e-10);
  EXPECT_NEAR(vec[2], 0.0, 1e-10);

  quat = quatd::create(1.0, 0.0, 0.0, linal::PI_D);
  vec = quat.rotate(0.0, 1.0, 0.0);
  EXPECT_NEAR(vec[0], 0.0, 1e-10);
  EXPECT_NEAR(vec[1], -1.0, 1e-10);
  EXPECT_NEAR(vec[2], 0.0, 1e-10);  
}

TEST(quat, rotate_range)
{
  quaternion quat = quatd::create(0.0, 0.0, 1.0, linal::PI_HALF_D);
  std::array<double, 6> points = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0}; // Two points (1,0,0) and (0,1,0)
  quat.rotate(points.begin(), points.end());
  EXPECT_NEAR(points[0], 0.0, 1e-10);
  EXPECT_NEAR(points[1], 1.0, 1e-10);
  EXPECT_NEAR(points[2], 0.0, 1e-10);
  EXPECT_NEAR(points[3], -1.0, 1e-10);
  EXPECT_NEAR(points[4], 0.0, 1e-10);
  EXPECT_NEAR(points[5], 0.0, 1e-10);  
}

TEST(quat, rotate_range_with_out_iter)
{
  quaternion quat = quatd::create(0.0, 0.0, 1.0, linal::PI_HALF_D);
  std::array<double, 6> points = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0}; // Two points (1,0,0) and (0,1,0)
  std::array<double, 6> outPoints;
  quat.rotate(points.begin(), points.end(), outPoints.begin());
  EXPECT_NEAR(outPoints[0], 0.0, 1e-10);
  EXPECT_NEAR(outPoints[1], 1.0, 1e-10);
  EXPECT_NEAR(outPoints[2], 0.0, 1e-10);
  EXPECT_NEAR(outPoints[3], -1.0, 1e-10);
  EXPECT_NEAR(outPoints[4], 0.0, 1e-10);
  EXPECT_NEAR(outPoints[5], 0.0, 1e-10);
}

TEST(quat, slerp)
{
  auto q1 = quatd::create(0.0, 0.0, 1.0, 0.0);
  auto q2 = quatd::create(0.0, 0.0, 1.0, linal::PI_D);

  // vector to rotate: (1,0,0)
  double x = 1.0;
  double y = 0.0;
  double z = 0.0;

  auto qStart = quatd::slerp(q1, q2, 0.0);
  linal::double3 vec = qStart.rotate(x, y, z);
  EXPECT_NEAR(vec[0], 1.0, 1e-10);
  EXPECT_NEAR(vec[1], 0.0, 1e-10);
  EXPECT_NEAR(vec[2], 0.0, 1e-10);

  auto qQuarter = quatd::slerp(q1, q2, 0.25);
  vec = qQuarter.rotate(x, y, z);
  EXPECT_NEAR(vec[0], std::sqrt(2) / 2, 1e-10);
  EXPECT_NEAR(vec[1], std::sqrt(2) / 2, 1e-10);
  EXPECT_NEAR(vec[2], 0.0, 1e-10);

  auto qMid = quatd::slerp(q1, q2, 0.5);
  vec = qMid.rotate(x, y, z);
  EXPECT_NEAR(vec[0], 0.0, 1e-10);
  EXPECT_NEAR(vec[1], 1.0, 1e-10);
  EXPECT_NEAR(vec[2], 0.0, 1e-10);

  auto qEnd = quatd::slerp(q1, q2, 1.0);
  vec = qEnd.rotate(x, y, z);
  EXPECT_NEAR(vec[0], -1.0, 1e-10);
  EXPECT_NEAR(vec[1], 0.0, 1e-10);
  EXPECT_NEAR(vec[2], 0.0, 1e-10);
}