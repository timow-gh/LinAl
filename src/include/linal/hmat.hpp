#ifndef LINAL_HMAT_HPP
#define LINAL_HMAT_HPP

#include <linal/utils/compiler.hpp>
#include <linal/utils/warnings.hpp>
TW_LINAL_DISABLE_ALL_WARNINGS
#include <blaze/math/StaticMatrix.h>
#include <blaze/math/Submatrix.h>
#include <blaze/util/AlignedAllocator.h>
TW_LINAL_ENABLE_ALL_WARNINGS

namespace linal
{

namespace hcoord
{

template <typename T>
using hmat = blaze::StaticMatrix<T, 4, 4, blaze::rowMajor, blaze::aligned, blaze::padded>;
using hmatf = hmat<float>;
using hmatd = hmat<double>;

template <typename T>
using hmatAllocator = blaze::AlignedAllocator<hmat<T>>;
using hmatAllocatorf = hmatAllocator<hmatf>;
using hmatAllocatord = hmatAllocator<hmatd>;

template <typename T>
LINAL_NODISCARD constexpr hmat<T> identity() noexcept
{
  hmat<T> result;
  for (std::size_t i{0}; i < 4; ++i)
  {
    result(i, i) = 1.0;
  }
  return result;
}

template <typename T>
LINAL_NODISCARD constexpr hmat<T> hMatInverse(const hmat<T>& matrix) noexcept
{
  hmat<T> result = matrix;

  auto R = blaze::submatrix<0UL, 0UL, 3UL, 3UL>(result);
  blaze::transpose(R);

  auto p = blaze::submatrix<0UL, 3UL, 3UL, 1UL>(result);
  p = -R * p;

  return result;
}

} // namespace hcoord

} // namespace linal

#endif // LINAL_HMAT_HPP
