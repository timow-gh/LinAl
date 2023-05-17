#ifndef LINAL_HMATROTATION_HPP
#define LINAL_HMATROTATION_HPP

#include <linal/HMat.hpp>
#include <linal/MatRotation.hpp>
#include <linal/Vec.hpp>
#include <linal/VecOperations.hpp>
#include <linal/utils/Compiler.hpp>
#include <linal/utils/Util.hpp>

namespace linal
{

namespace hcoord
{

//! alpha in radians
template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR hmat<T> rot_x(T alphaRad)
{
  hmat<T> result = hcoord::identity<T>();
  auto R = blaze::submatrix<0UL, 0UL, 3UL, 3UL>(result);
  R = linal::rot_x(alphaRad);
  return result;
}

//! alpha in radians
template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR hmat<T> rot_y(T alphaRad)
{
  hmat<T> result = hcoord::identity<T>();
  auto R = blaze::submatrix<0UL, 0UL, 3UL, 3UL>(result);
  R = linal::rot_y(alphaRad);
  return result;
}

//! alpha in radians
template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR hmat<T> rot_z(T alphaRad)
{
  hmat<T> result = hcoord::identity<T>();
  auto R = blaze::submatrix<0UL, 0UL, 3UL, 3UL>(result);
  R = linal::rot_z(alphaRad);
  return result;
}

template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR hmat<T> rot_axis(const hvec<T>& axis, T alphaRad)
{
  hmat<T> result = hcoord::identity<T>();
  auto R = blaze::submatrix<0UL, 0UL, 3UL, 3UL>(result);
  R = linal::rot_axis(linal::linal_utils::hVecToVec3<T>(axis), alphaRad);
  return result;
}

//! Make sure the input vectors are normalized if scaling is not desired.
template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR hmat<T> rot_align(const hvec<T>& source, const hvec<T>& target)
{
  hmat<T> result = hcoord::identity<T>();
  auto R = blaze::submatrix<0UL, 0UL, 3UL, 3UL>(result);
  R = linal::rot_align(linal::linal_utils::hVecToVec3(source), linal::linal_utils::hVecToVec3(target));
  return result;
}

} // namespace hcoord

} // namespace linal

#endif // LINAL_HMATROTATION_HPP
