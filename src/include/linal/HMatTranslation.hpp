#ifndef LINAL_HMATTRANSLATION_HPP
#define LINAL_HMATTRANSLATION_HPP

#include <linal/HMat.hpp>
#include <linal/MatRotation.hpp>
#include <linal/Vec.hpp>
#include <linal/VecOperations.hpp>
#include <linal/utils/Compiler.hpp>
#include <linal/utils/Warnings.hpp>
DISABLE_ALL_WARNINGS
#include <blaze/math/Submatrix.h>
ENABLE_ALL_WARNINGS

namespace linal
{

namespace hcoord
{

template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR hmat<T> create_translation(Vec<T, D> vec)
{
  static_assert(D > 1 && D < 4);

  hmat<T> result = hcoord::identity<T>();

  for (std::size_t i = 0; i < D; ++i)
    result(i, D) = vec[i];

  return result;
}

template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR hmat<T> create_translation(hvec<T> vec)
{
  hmat<T> result = hcoord::identity<T>();
  result(0, 3) = vec[0];
  result(1, 3) = vec[1];
  result(2, 3) = vec[2];
  return result;
}

template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR hmat<T> create_translation(T x, T y, T z)
{
  hmat<T> result = hcoord::identity<T>();
  result(0, 3) = x;
  result(1, 3) = y;
  result(2, 3) = z;
  return result;
}

template <typename T, std::size_t N>
LINAL_CONSTEXPR void get_translation(const hmat<T>& hmat, Vec<T, N>& result)
{
  result[0] = hmat(0, 3);
  result[1] = hmat(1, 3);
  result[2] = hmat(2, 3);
  if constexpr (Vec<T, N>::size() == 4)
    result[3] = hmat(3, 3);
}

template <typename T, std::size_t D>
LINAL_CONSTEXPR void set_translation(hmat<T>& hmat, Vec<T, D> translation)
{
  hmat(0, 3) = translation[0];
  hmat(1, 3) = translation[1];
  hmat(2, 3) = translation[2];
}

template <typename T>
[[deprecated]] LINAL_CONSTEXPR void hMatScaleTranslation(hmat<T>& matrix, T scaleFactor, T lowerLimit, T upperLimit)
{
  auto translSubMatrix = blaze::submatrix<0UL, 3UL, 3UL, 1UL>(matrix);
  translSubMatrix = translSubMatrix * scaleFactor;

  Vec3<T> lengthVec{matrix(0, 3), matrix(1, 3), matrix(2, 3)};
  T length = linal::norm2(lengthVec);
  if (length < lowerLimit)
  {
    lengthVec = linal::normalize(lengthVec) * lowerLimit;
  }
  else if (length > upperLimit)
  {
    lengthVec = linal::normalize(lengthVec) * upperLimit;
  }
  else
    return;

  matrix(0, 3) = lengthVec[0];
  matrix(1, 3) = lengthVec[1];
  matrix(2, 3) = lengthVec[2];
}

} // namespace hcoord

} // namespace linal

#endif // LINAL_HMATTRANSLATION_HPP
