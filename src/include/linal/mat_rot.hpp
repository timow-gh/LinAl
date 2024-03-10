#ifndef LINAL_MAT_ROT_HPP
#define LINAL_MAT_ROT_HPP

#include "linal/utils/util.hpp"

namespace linal
{

/** @brief Create a rotation matrix around the x-axis.
 *
 * The rotation matrix is:
 * {1, 0  ,  0  }
 * {0, cos, -sin}
 * {0, sin,  cos}
 *
 * @tparam TMat The rotation matrix.
 * @tparam T The scalar type.
 * @param alpha The angle in radians.
 */
template <typename TMat, typename T>
constexpr void rot_x(TMat& mat, T alpha) noexcept
{
  auto [cos, sin] = linal_utils::calcCosSin(alpha);
  mat(0, 0) = 1;
  mat(0, 1) = 0;
  mat(0, 2) = 0;

  mat(1, 0) = 0;
  mat(1, 1) = cos;
  mat(1, 2) = -sin;

  mat(2, 0) = 0;
  mat(2, 1) = sin;
  mat(2, 2) = cos;
}

/** @brief Create a rotation matrix around the y-axis.
 *
 * The rotation matrix is:
 * {cos, 0, sin}
 * {0  , 1, 0  }
 * {-sin, 0, cos}
 *
 * @tparam TMat The rotation matrix.
 * @tparam T The scalar type.
 * @param alpha The angle in radians.
 */
template <typename TMat, typename T>
constexpr void rot_y(TMat& mat, T alpha) noexcept
{
  auto [cos, sin] = linal_utils::calcCosSin(alpha);
  mat(0, 0) = cos;
  mat(0, 1) = 0;
  mat(0, 2) = sin;

  mat(1, 0) = 0;
  mat(1, 1) = 1;
  mat(1, 2) = 0;

  mat(2, 0) = -sin;
  mat(2, 1) = 0;
  mat(2, 2) = cos;
}

/** @brief Create a rotation matrix around the z-axis.
 *
 * The rotation matrix is:
 * {cos, -sin, 0}
 * {sin,  cos, 0}
 * {0  ,  0  , 1}
 *
 * @tparam TMat The rotation matrix.
 * @tparam T The scalar type.
 * @param alpha The angle in radians.
 */
template <typename TMat, typename T>
constexpr void rot_z(TMat& mat, T alpha) noexcept
{
  auto [cos, sin] = linal_utils::calcCosSin(alpha);
  mat(0, 0) = cos;
  mat(0, 1) = -sin;
  mat(0, 2) = 0;

  mat(1, 0) = sin;
  mat(1, 1) = cos;
  mat(1, 2) = 0;

  mat(2, 0) = 0;
  mat(2, 1) = 0;
  mat(2, 2) = 1;
}

/** @brief Create a rotation matrix around the given axis.
 *
 *  @attention The axis must be normalized.
 *
 * @tparam T
 * @param axis
 * @param angleRad
 * @return
 */
template <typename T>
constexpr void rot_axis(mat<T, 3, 3>& matrix, vec3<T> axis, T angleRad) noexcept
{
  vec3<T> nAxis = linal::normalize(axis);
  const T c = std::cos(angleRad);
  const T C = 1 - c;
  const T s = std::sin(angleRad);

  const T xxC = nAxis[0] * nAxis[0] * C;
  const T yyC = nAxis[1] * nAxis[1] * C;
  const T zzC = nAxis[2] * nAxis[2] * C;

  const T xyC = nAxis[0] * nAxis[1] * C;
  const T xzC = nAxis[0] * nAxis[2] * C;
  const T yzC = nAxis[1] * nAxis[2] * C;

  const T zs = nAxis[2] * s;
  const T ys = nAxis[1] * s;
  const T xs = nAxis[0] * s;

  // clang-format off
  //  matrix = {{xxC+c,  xyC-zs,   xzC+ys},
  //            {xyC+zs,  yyC+c,    yzC-xs},
  //            {xzC-ys,  yzC-xs,   zzC+c}});
  // clang-format on
  matrix(0, 0) = xxC + c;
  matrix(0, 1) = xyC - zs;
  matrix(0, 2) = xzC + ys;

  matrix(1, 0) = xyC + zs;
  matrix(1, 1) = yyC + c;
  matrix(1, 2) = yzC - xs;

  matrix(2, 0) = xzC - ys;
  matrix(2, 1) = yzC + xs;
  matrix(2, 2) = zzC + c;
}

/** @brief Create a rotation matrix that aligns the source vector with the target vector.
 *
 * The rotation vector is perpendicular to the source and target vectors.
 *
 * @attention Input vectors are not normalized. Make sure the input vectors are normalized if scaling is not desired.
 *
 * @param source The source vector.
 * @param target The target vector.
 */
template <typename TMat, typename TVecA, typename TVecB>
constexpr void rot_align(TMat& mat, const TVecA& source, const TVecB& target) noexcept
{
  // Expect a 3D vector or homogeneous coordinates i.e. 4D vector.
  static_assert(TVecA::dim == 3 || TVecA::dim == 4);
  static_assert(TVecB::dim == 3 || TVecB::dim == 4);
  static_assert(std::is_same_v<typename TMat::value_type, typename TVecA::value_type>);
  static_assert(std::is_same_v<typename TMat::value_type, typename TVecB::value_type>);
  using T = typename TMat::value_type;

  // https://iquilezles.org/www/articles/noacos/noacos.htm
  //     v * v^T     (  c,     v.z, -v.y)
  // M = -------  +  ( -v.z,   c,    v.x)
  //      1+c        (  v.y,  -v.x,  c  )
  const vec3<T> v = cross(source[0], source[1], source[2], target[0], target[1], target[2]);
  const T c = dot(source[0], source[1], source[2], target[0], target[1], target[2]);
  const T k = T(1.0) / (T(1.0) + c);

  const T v10k = v[1] * v[0] * k;
  const T v20k = v[2] * v[0] * k;
  const T v21k = v[2] * v[1] * k;

  // The following matrix is equivalent to the following code:
  // {v[0]*v[0]*k + c,  v10k - v[2] ,     v20k + v[1]    }
  // {v10k + v[2],      v[1]*v[1]*k + c,  v21k - v[0]    }
  // {v20k - v[1],      v21k + v[0],      v[2]*v[2]*k + c}

  mat(0, 0) = v[0] * v[0] * k + c;
  mat(0, 1) = v10k - v[2];
  mat(0, 2) = v20k + v[1];

  mat(1, 0) = v10k + v[2];
  mat(1, 1) = v[1] * v[1] * k + c;
  mat(1, 2) = v21k - v[0];

  mat(2, 0) = v20k - v[1];
  mat(2, 1) = v21k + v[0];
  mat(2, 2) = v[2] * v[2] * k + c;
}

/**
 * @brief Create a transformation matrix from the given local coordinate system vectors.
 *
 * The local coordinate system vectors are the columns of the transformation matrix:
 * lcsX[0], lcsY[0], lcsZ[0]
 * lcsX[1], lcsY[1], lcsZ[1]
 * lcsX[2], lcsY[2], lcsZ[2]
 *
 * @tparam TMat The transformation matrix.
 * @tparam TVec The vector type.
 */
template <typename TMat, typename TVec>
constexpr void transformation_from_lcs_vectors(TMat& mat, const TVec& x, const TVec& y, const TVec& z) noexcept
{
  mat = TMat::from_columns({x, y, z});
}

} // namespace linal

#endif // LINAL_MAT_ROT_HPP
