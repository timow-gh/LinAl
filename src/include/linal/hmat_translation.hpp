#ifndef LINAL_HMAT_TRANSLATION_HPP
#define LINAL_HMAT_TRANSLATION_HPP

#include <linal/hmat.hpp>
#include <linal/mat_rot.hpp>
#include <linal/utils/compiler.hpp>
#include <linal/utils/warnings.hpp>
#include <linal/vec.hpp>
#include <linal/vec_operations.hpp>
TW_LINAL_DISABLE_ALL_WARNINGS
#include <blaze/math/Submatrix.h>
TW_LINAL_ENABLE_ALL_WARNINGS

namespace linal
{

namespace hcoord
{

template <typename T, std::size_t D>
LINAL_NODISCARD constexpr hmat<T> hmat_translation(vec<T, D> vec) noexcept
{
  static_assert(D > 1 && D < 4);

  hmat<T> result = hcoord::identity<T>();

  for (std::size_t i = 0; i < D; ++i)
    result(i, D) = vec[i];

  return result;
}

template <typename T>
LINAL_NODISCARD constexpr hmat<T> hmat_translation(hvec<T> vec) noexcept
{
  hmat<T> result = hcoord::identity<T>();
  result(0, 3) = vec[0];
  result(1, 3) = vec[1];
  result(2, 3) = vec[2];
  return result;
}

template <typename T>
LINAL_NODISCARD constexpr hmat<T> hmat_translation(T x, T y, T z) noexcept
{
  hmat<T> result = hcoord::identity<T>();
  result(0, 3) = x;
  result(1, 3) = y;
  result(2, 3) = z;
  return result;
}

template <typename T, std::size_t N>
constexpr void get_translation(const hmat<T>& hmat, vec<T, N>& result) noexcept
{
  static_assert(N > 1 && N < 4);
  result[0] = hmat(0, 3);
  result[1] = hmat(1, 3);
  result[2] = hmat(2, 3);
  if constexpr (vec<T, N>::size() == 4)
    result[3] = hmat(3, 3);
}

template <typename T, std::size_t D>
constexpr void set_translation(hmat<T>& hmat, vec<T, D> translation)
{
  static_assert(D > 1 && D < 4);
  hmat(0, 3) = translation[0];
  hmat(1, 3) = translation[1];
  hmat(2, 3) = translation[2];
}

} // namespace hcoord

} // namespace linal

#endif // LINAL_HMAT_TRANSLATION_HPP
