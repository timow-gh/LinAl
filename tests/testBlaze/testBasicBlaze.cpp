#include <iostream>

#include "blaze/Math.h"
#include "gtest/gtest.h"

TEST(basicBlazeTest, Matrix) {
  blaze::DynamicMatrix<int> A(2UL, 3UL, 0);
  A(0, 0) = 1;
  A(0, 2) = 4;
  A(1, 1) = -2;
  constexpr blaze::StaticMatrix<int, 3UL, 2UL, blaze::columnMajor> B{
      {3, -1}, {0, 2}, {-1, 0}};
  blaze::StaticMatrix<int, 2, 2> C = A * B;
  constexpr blaze::StaticMatrix<int, 2, 2> CExpected{{-1, -1}, {0, -4}};
  EXPECT_EQ(CExpected, C);
}
