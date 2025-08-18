#include <array>
#include <gtest/gtest.h>
#include <linal/linal.hpp>

using namespace linal;

constexpr double22 create_default_mat() noexcept
{
  double22 mat;
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;
  return mat;
}

TEST(mat, construct_default)
{
  double22 mat;
  EXPECT_EQ(mat(0, 0), 0);
  EXPECT_EQ(mat(0, 1), 0);
  EXPECT_EQ(mat(1, 0), 0);
  EXPECT_EQ(mat(1, 1), 0);
}

TEST(mat, zeros)
{
  const auto mat = double22{0.0};
  using size_type = typename double22::size_type;
  for (size_type i{0}; i < 2; ++i)
  {
    for (size_type j{0}; j < 2; ++j)
    {
      EXPECT_EQ(mat(i, j), 0);
    }
  }
}

TEST(mat, diag)
{
  int value = 1;
  const auto mat = int22::diagonal(value);
  using size_type = typename int22::size_type;
  for (size_type i{0}; i < 2; ++i)
  {
    for (size_type j{0}; j < 2; ++j)
    {
      if (i == j)
      {
        EXPECT_EQ(mat(i, j), value);
      }
      else
      {
        EXPECT_EQ(mat(i, j), 0);
      }
    }
  }
}

TEST(mat, standard_functions)
{
  double22 mat = create_default_mat();

  EXPECT_EQ(mat(0, 0), 1);
  EXPECT_EQ(mat(0, 1), 2);
  EXPECT_EQ(mat(1, 0), 3);
  EXPECT_EQ(mat(1, 1), 4);

  EXPECT_EQ(mat.noOfCols, 2);
  EXPECT_EQ(mat.noOfRows, 2);
  EXPECT_EQ(mat.size, 4);
}

TEST(mat, comparison_policy)
{
  double22 mat1 = create_default_mat();
  double22 mat2 = create_default_mat();
  double22 mat3{0.0};

  EXPECT_TRUE(mat1 == mat2);
  EXPECT_FALSE(mat1 == mat3);
  EXPECT_FALSE(mat1 != mat2);
  EXPECT_TRUE(mat1 != mat3);
}

TEST(mat, addition_policy)
{
  double22 mat1 = create_default_mat();

  double22 mat2;
  mat2(0, 0) = 5;
  mat2(0, 1) = 6;
  mat2(1, 0) = 7;
  mat2(1, 1) = 8;

  double22 result = mat1 + mat2;
  EXPECT_EQ(result(0, 0), 6);
  EXPECT_EQ(result(0, 1), 8);
  EXPECT_EQ(result(1, 0), 10);
  EXPECT_EQ(result(1, 1), 12);

  result = mat1 + 2;
  EXPECT_EQ(result(0, 0), 3);
  EXPECT_EQ(result(0, 1), 4);
  EXPECT_EQ(result(1, 0), 5);
  EXPECT_EQ(result(1, 1), 6);

  result = 2 + mat1;
  EXPECT_EQ(result(0, 0), 3);
  EXPECT_EQ(result(0, 1), 4);
  EXPECT_EQ(result(1, 0), 5);
  EXPECT_EQ(result(1, 1), 6);

  mat1 += mat2;
  EXPECT_EQ(mat1(0, 0), 6);
  EXPECT_EQ(mat1(0, 1), 8);
  EXPECT_EQ(mat1(1, 0), 10);
  EXPECT_EQ(mat1(1, 1), 12);

  mat1 += 2;
  EXPECT_EQ(mat1(0, 0), 8);
  EXPECT_EQ(mat1(0, 1), 10);
  EXPECT_EQ(mat1(1, 0), 12);
  EXPECT_EQ(mat1(1, 1), 14);
}

TEST(mat, subtraction_policy)
{
  double22 mat1 = create_default_mat();

  double22 mat2;
  mat2(0, 0) = 5;
  mat2(0, 1) = 6;
  mat2(1, 0) = 7;
  mat2(1, 1) = 8;

  double22 result = mat1 - mat2;
  EXPECT_EQ(result(0, 0), -4);
  EXPECT_EQ(result(0, 1), -4);
  EXPECT_EQ(result(1, 0), -4);
  EXPECT_EQ(result(1, 1), -4);

  result = mat1 - 2;
  EXPECT_EQ(result(0, 0), -1);
  EXPECT_EQ(result(0, 1), 0);
  EXPECT_EQ(result(1, 0), 1);
  EXPECT_EQ(result(1, 1), 2);

  result = 2 - mat1;
  EXPECT_EQ(result(0, 0), 1);
  EXPECT_EQ(result(0, 1), 0);
  EXPECT_EQ(result(1, 0), -1);
  EXPECT_EQ(result(1, 1), -2);

  mat1 -= mat2;
  EXPECT_EQ(mat1(0, 0), -4);
  EXPECT_EQ(mat1(0, 1), -4);
  EXPECT_EQ(mat1(1, 0), -4);
  EXPECT_EQ(mat1(1, 1), -4);

  mat1 -= 2;
  EXPECT_EQ(mat1(0, 0), -6);
  EXPECT_EQ(mat1(0, 1), -6);
  EXPECT_EQ(mat1(1, 0), -6);
  EXPECT_EQ(mat1(1, 1), -6);
}

TEST(mat, multiplication_policy)
{
  auto mat1 = double22(1);
  mat1 = create_default_mat();
  auto result = mat1 * 2;
  EXPECT_EQ(result(0, 0), 2);
  EXPECT_EQ(result(0, 1), 4);
  EXPECT_EQ(result(1, 0), 6);
  EXPECT_EQ(result(1, 1), 8);

  result = 3 * mat1;
  EXPECT_EQ(result(0, 0), 3);
  EXPECT_EQ(result(0, 1), 6);
  EXPECT_EQ(result(1, 0), 9);
  EXPECT_EQ(result(1, 1), 12);

  mat1 = create_default_mat();
  mat1 *= 2;
  EXPECT_EQ(mat1(0, 0), 2);
  EXPECT_EQ(mat1(0, 1), 4);
  EXPECT_EQ(mat1(1, 0), 6);
  EXPECT_EQ(mat1(1, 1), 8);
}

TEST(mat, division_policy)
{
  auto mat1 = create_default_mat();
  auto result = mat1 / 2;
  EXPECT_EQ(result(0, 0), 0.5);
  EXPECT_EQ(result(0, 1), 1);
  EXPECT_EQ(result(1, 0), 1.5);
  EXPECT_EQ(result(1, 1), 2);

  EXPECT_EQ(mat1(0, 0), 1);
  EXPECT_EQ(mat1(0, 1), 2);
  EXPECT_EQ(mat1(1, 0), 3);
  EXPECT_EQ(mat1(1, 1), 4);

  mat1 /= 0.5;
  EXPECT_EQ(mat1(0, 0), 2);
  EXPECT_EQ(mat1(0, 1), 4);
  EXPECT_EQ(mat1(1, 0), 6);
  EXPECT_EQ(mat1(1, 1), 8);
}

TEST(mat, unary_policy)
{
  auto mat1 = create_default_mat();
  auto result = -mat1;
  EXPECT_EQ(result(0, 0), -1);
  EXPECT_EQ(result(0, 1), -2);
  EXPECT_EQ(result(1, 0), -3);
  EXPECT_EQ(result(1, 1), -4);
}

TEST(mat, get_column)
{
  double22 mat = create_default_mat();
  double2 columnA = mat.get_column(0);
  EXPECT_TRUE(columnA == double2(1.0, 3.0));
  double2 columnB = mat.get_column(1);
  EXPECT_TRUE(columnB == double2(2.0, 4.0));
}

TEST(mat, get_row)
{
  double22 mat = create_default_mat();
  double2 rowA = mat.get_row(0);
  EXPECT_TRUE(rowA == double2(1.0, 2.0));
  double2 rowB = mat.get_row(1);
  EXPECT_TRUE(rowB == double2(3.0, 4.0));
}

TEST(mat, matrix_matrix_multiplication)
{
  auto mat1 = double22(1);
  auto mat2 = double22(1);
  double22 result = mat1 * mat2;
  EXPECT_EQ(result(0, 0), 2);
  EXPECT_EQ(result(0, 1), 2);
  EXPECT_EQ(result(1, 0), 2);
  EXPECT_EQ(result(1, 1), 2);
  EXPECT_TRUE(mat1 == double22(1));
  EXPECT_TRUE(mat2 == double22(1));

  auto mat3 = double22(2);
  auto mat4 = mat<double, 2, 3>(2);
  auto result2 = mat3 * mat4;
  EXPECT_EQ(result2(0, 0), 8);
  EXPECT_EQ(result2(0, 1), 8);
  EXPECT_EQ(result2(0, 2), 8);
  EXPECT_EQ(result2(1, 0), 8);
  EXPECT_EQ(result2(1, 1), 8);
  EXPECT_EQ(result2(1, 2), 8);
}

TEST(mat, matrix_vector_multiplication)
{
  double22 mat = create_default_mat();
  double2 vec{1.0, 2.0};
  double2 result = mat * vec;
  EXPECT_TRUE(result == double2(5.0, 11.0));
  EXPECT_TRUE(mat == create_default_mat());
}

TEST(mat, transpose)
{
  double22 mat = create_default_mat();
  double22 transposed = mat.transpose();
  EXPECT_EQ(transposed(0, 0), 1);
  EXPECT_EQ(transposed(0, 1), 3);
  EXPECT_EQ(transposed(1, 0), 2);
  EXPECT_EQ(transposed(1, 1), 4);

  mat = transpose(transposed);
  EXPECT_EQ(mat(0, 0), 1);
  EXPECT_EQ(mat(0, 1), 2);
  EXPECT_EQ(mat(1, 0), 3);
  EXPECT_EQ(mat(1, 1), 4);

  ::mat<double, 3, 2> mat2;
  mat2(0, 0) = 1;
  mat2(0, 1) = 2;
  mat2(1, 0) = 3;
  mat2(1, 1) = 4;
  mat2(2, 0) = 5;
  mat2(2, 1) = 6;

  ::mat<double, 2, 3> transposed2 = mat2.transpose();
  EXPECT_EQ(transposed2(0, 0), 1);
  EXPECT_EQ(transposed2(0, 1), 3);
  EXPECT_EQ(transposed2(0, 2), 5);
  EXPECT_EQ(transposed2(1, 0), 2);
  EXPECT_EQ(transposed2(1, 1), 4);
  EXPECT_EQ(transposed2(1, 2), 6);
}

TEST(mat, is_identity)
{
  double22 mat = double22::identity();
  EXPECT_TRUE(mat.is_identity());
  EXPECT_TRUE(is_identity(mat));
  mat(0, 0) = 2;
  EXPECT_FALSE(mat.is_identity());
  EXPECT_FALSE(is_identity(mat));

  mat(0, 0) = 1;
  mat(0, 1) = 3;
  mat(1, 0) = 2;
  EXPECT_FALSE(mat.is_identity());
  EXPECT_FALSE(is_identity(mat));
}

TEST(mat, is_symmetric)
{
  double22 mat = create_default_mat();
  EXPECT_FALSE(mat.is_symmetric());
  EXPECT_FALSE(is_symmetric(mat));
  mat(0, 1) = 3;
  EXPECT_TRUE(mat.is_symmetric());
  EXPECT_TRUE(is_symmetric(mat));
}

TEST(mat, is_orthogonal)
{
  double22 mat = create_default_mat();
  EXPECT_FALSE(mat.is_orthogonal());
  EXPECT_FALSE(is_orthogonal(mat));
  mat(0, 0) = 0;
  mat(0, 1) = 1;
  mat(1, 0) = -1;
  mat(1, 1) = 0;
  EXPECT_TRUE(mat.is_orthogonal());
  EXPECT_TRUE(is_orthogonal(mat));
}

// TODO? add tests for the following functions:
//  - determinant
//  - inverse
//  - adjugate
//  - cofactor
//  - minor
//  - trace
//  - is_diagonal
//  - is_invertible
//  - is_singular
//  - is_positive_definite
//  - is_positive_semidefinite
//  - is_negative_definite
//  - is_negative_semidefinite
//  - is_indefinite
//  - is_skew_symmetric
//  - is_hermitian
//  - is_normal
//  - is_unitary
//  - is_orthonormal
//  - is_orthogonal
//  - is_rotation
//  - is_homogeneous
//  - is_homogeneous_affine
//  - is_homogeneous_projective
//  - is_homogeneous_euclidean
//  - is_homogeneous_similarity
//  - is_homogeneous_conformal
//  - is_homogeneous_dilation

// Geometry related functions
// 4d means 4x4 matrix for homogeneous coordinates
//  - translate (4d)
//  - scale (2d, 3d, 4d)
//  - shear (2d, 3d, 4d)
//  - rotate (2d, 3d, 4d)
//  - rotate_x (3d, 4d)
//  - rotate_y (3d, 4d)
//  - rotate_z (3d, 4d)
//  - rotate_axis (3d, 4d)
//  - rotate_euler (3d, 4d)
//  - rotate_quaternion (3d, 4d)
//  - look_at_RH (right handed), for opengl (3d, 4d)
//  - look_at_LH (left handed), for directx, metal, vulkan (3d, 4d)
//  - perspective (4d)
//  - orthographic (4d)

TEST(mat, from_rows)
{
  double2 row1{1.0, 2.0};
  double2 row2{3.0, 4.0};
  double22 mat = double22::from_rows({row1, row2});
  EXPECT_DOUBLE_EQ(mat(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(mat(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(mat(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(mat(1, 1), 4.0);

#ifdef DEBUG
  ASSERT_DEBUG_DEATH([[maybe_unused]] auto res = double22::from_rows({row1}), "Number of rows does not match column length.");
  ASSERT_DEBUG_DEATH([[maybe_unused]] auto res = double22::from_rows({row1, row2, row2}), "Number of rows does not match column length.");
#endif
}

TEST(mat, from_columns)
{
  double2 column1{1.0, 3.0};
  double2 column2{2.0, 4.0};
  double22 mat = double22::from_columns({column1, column2});
  EXPECT_DOUBLE_EQ(mat(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(mat(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(mat(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(mat(1, 1), 4.0);

#ifdef DEBUG
  ASSERT_DEBUG_DEATH([[maybe_unused]] auto res = double22::from_columns({column1}), "Number of columns does not match row length.");
  ASSERT_DEBUG_DEATH([[maybe_unused]] auto res = double22::from_columns({column1, column2, column2}), "Number of columns does not match row length.");
#endif
}

std::array<double3, 3> create90DegRotatedLcs() noexcept
{
  return {double3{0.0, 1.0, 0.0}, double3{-1.0, 0.0, 0.0}, double3{0.0, 0.0, 1.0}};
}

static void testZRotation(const double3& a, const double33& rotationMatrix)
{
  double3 b = rotationMatrix * a;
  double3 bExpected{0.0, 1.0, 1.0};
  EXPECT_EQ(b, bExpected);

  double3 c = rotationMatrix * b;
  double3 cExpected{-1.0, 0.0, 1.0};
  EXPECT_EQ(c, cExpected);

  double3 d = rotationMatrix * c;
  double3 dExpected{0.0, -1.0, 1.0};
  EXPECT_EQ(d, dExpected);

  double3 e = rotationMatrix * d;
  double3 eExpected{1.0, 0.0, 1.0};
  EXPECT_EQ(e, eExpected);
}

TEST(createLcsToGlobalRotationMatrix_vectors, TRhs)
{
  std::array<double3, 3> rotatedLcs = create90DegRotatedLcs();
  double33 rotationMatrix;
  linal::transformation_from_lcs_vectors(rotationMatrix, rotatedLcs[0], rotatedLcs[1], rotatedLcs[2]);
  const double3 a{1.0, 0.0, 1.0};
  testZRotation(a, rotationMatrix);
}

TEST(Matrix3dOperations, xRotation)
{
  double33 rotMat;
  rot_x(rotMat, linal::PI_HALF<double>);
  double3 start{0.0, 1.0, 0.0};
  double3 result = rotMat * start;
  double3 expected{0.0, 0.0, 1.0};
  EXPECT_EQ(result, expected);
}

TEST(Matrix3dOperations, yRotation)
{
  double33 rotMat;
  rot_y(rotMat, linal::PI_HALF<double>);
  double3 start{0.0, 0.0, 1.0};
  double3 result = rotMat * start;
  double3 expected{1.0, 0.0, 0.0};
  EXPECT_EQ(result, expected);
}

TEST(Matrix3dOperations, zRotation)
{
  double33 rotMat;
  rot_z(rotMat, linal::PI_HALF<double>);
  double3 start{1.0, 0.0, 0.0};
  double3 result = rotMat * start;
  double3 expected{0.0, 1.0, 0.0};
  EXPECT_EQ(result, expected);
}

TEST(Matrix3Operations, rot_align_xToy)
{
  constexpr double3 xDir{1.0, 0.0, 0.0};
  constexpr double3 yDir{0.0, 1.0, 0.0};
  double33 rotMat;
  rot_align(rotMat, xDir, yDir);
  double3 result = rotMat * xDir;
  EXPECT_EQ(yDir, result);

  double3 result2 = rotMat * yDir;
  double3 expected2{-1.0, 0.0, 0.0};
  EXPECT_EQ(result2, expected2);
}

TEST(Matrix3Operations, rot_align_xToz)
{
  constexpr double3 xDir{1.0, 0.0, 0.0};
  constexpr double3 zDir{0.0, 0.0, 1.0};
  double33 rotMat;
  rot_align(rotMat, xDir, zDir);
  double3 result = rotMat * xDir;
  EXPECT_EQ(zDir, result);
}

TEST(Matrix3Operations, rot_align_xTox)
{
  constexpr double3 xDir{1.0, 0.0, 0.0};
  double33 rotMat;
  rot_align(rotMat, xDir, xDir);
  double3 result = rotMat * xDir;
  EXPECT_EQ(xDir, result);
}

TEST(Matrix3Operations, rot_align_xToNormalizedOnes)
{
  constexpr double3 xDir{1.0, 0.0, 0.0};
  constexpr double3 targetvec{1.0, 1.0, 1.0};
  auto normalized = normalize(targetvec);
  double33 rotMat;
  rot_align(rotMat, xDir, normalized);
  double3 result = rotMat * xDir;
  constexpr double_t eps = 1E-7;
  using size_type = double3::size_type;
  for (size_type i{0}; i < 3; ++i)
  {
    EXPECT_TRUE(linal::isEq(result[i], normalized[i], eps));
  }
}

TEST(Matrix3Operations, rot_align_xToOnes)
{
  double3 xDir{1.0, 0.0, 0.0};
  double3 targetvec{1.0, 1.0, 1.0};
  double33 rotMat;
  rot_align(rotMat, xDir, targetvec);
  double3 result = rotMat * xDir;
  EXPECT_EQ(result, targetvec);
}
