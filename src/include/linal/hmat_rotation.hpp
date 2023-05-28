#ifndef LINAL_HMAT_ROTATION_HPP
#define LINAL_HMAT_ROTATION_HPP

#include <linal/hmat.hpp>
#include <linal/mat_rot.hpp>
#include <linal/utils/compiler.hpp>
#include <linal/utils/util.hpp>
#include <linal/vec.hpp>
#include <linal/vec_operations.hpp>

namespace linal
{

namespace hcoord
{

//! alpha in radians
template <typename T>
LINAL_NODISCARD constexpr hmat<T> rot_x(T alphaRad) noexcept
{
  hmat<T> result = hcoord::identity<T>();
  auto R = blaze::submatrix<0UL, 0UL, 3UL, 3UL>(result);
  R = linal::rot_x(alphaRad);
  return result;
}

//! alpha in radians
template <typename T>
LINAL_NODISCARD constexpr hmat<T> rot_y(T alphaRad) noexcept
{
  hmat<T> result = hcoord::identity<T>();
  auto R = blaze::submatrix<0UL, 0UL, 3UL, 3UL>(result);
  R = linal::rot_y(alphaRad);
  return result;
}

//! alpha in radians
template <typename T>
LINAL_NODISCARD constexpr hmat<T> rot_z(T alphaRad) noexcept
{
  hmat<T> result = hcoord::identity<T>();
  auto R = blaze::submatrix<0UL, 0UL, 3UL, 3UL>(result);
  R = linal::rot_z(alphaRad);
  return result;
}

template <typename T>
LINAL_NODISCARD constexpr hmat<T> rot_axis(const hvec<T>& axis, T alphaRad) noexcept
{
  hmat<T> result = hcoord::identity<T>();
  auto R = blaze::submatrix<0UL, 0UL, 3UL, 3UL>(result);
  R = linal::rot_axis(hcoord::hvec_to_vec<T, 3>(axis), alphaRad);
  return result;
}

//! Make sure the input vectors are normalized if scaling is not desired.
template <typename T>
LINAL_NODISCARD constexpr hmat<T> rot_align(const hvec<T>& source, const hvec<T>& target) noexcept
{
  hmat<T> result = hcoord::identity<T>();
  auto R = blaze::submatrix<0UL, 0UL, 3UL, 3UL>(result);
  R = linal::rot_align(hcoord::hvec_to_vec<T, 3>(source), hcoord::hvec_to_vec<T, 3>(target));
  return result;
}

} // namespace hcoord

} // namespace linal

#endif // LINAL_HMAT_ROTATION_HPP
