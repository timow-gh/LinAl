#ifndef LINAL_MATROTATION_HPP
#define LINAL_MATROTATION_HPP

#include <linal/HMat.hpp>
#include <linal/Mat.hpp>
#include <linal/VecOperations.hpp>
#include <linal/utils/Compiler.hpp>
#include <linal/utils/Util.hpp>
#include <linal/utils/Warnings.hpp>
DISABLE_ALL_WARNINGS
#include <blaze/math/Submatrix.h>
ENABLE_ALL_WARNINGS

namespace linal
{

//! alpha in radians
template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR mat3<T> rot_x(T alpha)
{
  auto [cos, sin] = linal_utils::calcCosSin(alpha);
  // clang-format off
    return mat3<T>{{1, 0,    0},
                     {0, cos, -sin},
                     {0, sin,  cos}};
  // clang-format on
}

//! alpha in radians
template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR mat3<T> rot_y(T alpha)
{
  auto [cos, sin] = linal_utils::calcCosSin(alpha);
  // clang-format off
    return mat3<T>{{cos,   0, sin},
                      {0,     1,  0},
                      {-sin,  0,  cos}};
  // clang-format on
}

//! alpha in radians
template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR mat3<T> rot_z(T alpha)
{
  auto [cos, sin] = linal_utils::calcCosSin(alpha);
  // clang-format off
    return mat3<T>{{cos, -sin, 0},
                      {sin, cos,  0},
                      {0,   0,    1}};
  // clang-format on
}

//! Angle in radians
template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR auto rot_axis(Vec<T, 3> axis, T angleRad)
{
  Vec<T, 3> nAxis = linal::normalize(axis);
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
    return mat3<T>{
      {xxC+c,   xyC-zs,   xzC+ys},
      {xyC+zs,  yyC+c,    yzC-xs},
      {xzC-ys,  yzC-xs,   zzC+c}};
  // clang-format on
}

//! Input Vectors are not normalized.
//! Make sure the input vectors are normalized if scaling is not desired.
template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR auto rot_align(Vec<T, 3> source, Vec<T, 3> target)
{
  // clang-format off
    // https://iquilezles.org/www/articles/noacos/noacos.htm
    /*
        v * v^T     (  c,     v.z, -v.y)
    M = -------  +  ( -v.z,   c,    v.x)
         1+c        (  v.y,  -v.x,  c  )
    */
    const Vec<T, 3> v = cross(source, target);
    const T c = dot(source, target);
    const T k = T(1.0) / (T(1.0) + c);

    const T v10k = v[1]*v[0]*k;
    const T v20k = v[2]*v[0]*k;
    const T v21k = v[2]*v[1]*k;

    return mat3<T>
             { {v[0]*v[0]*k + c,  v10k - v[2] ,     v20k + v[1]    },
             {v10k + v[2],      v[1]*v[1]*k + c,  v21k - v[0]      },
             {v20k - v[1],      v21k + v[0],      v[2]*v[2]*k + c} };
  // clang-format on
}

template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR auto createLcsTransformation(Vec<T, 3> lcsX, Vec<T, 3> lcsY, Vec<T, 3> lcsZ)
{
  // clang-format off
    return mat3<T>{{lcsX[0], lcsY[0], lcsZ[0]},
                     {lcsX[1], lcsY[1], lcsZ[1]},
                     {lcsX[2], lcsY[2], lcsZ[2]}};
  // clang-format on
}

} // namespace linal

#endif // LINAL_MATROTATION_HPP
