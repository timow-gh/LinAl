#ifndef LINAL_HVEC_HPP
#define LINAL_HVEC_HPP

#include <linal/utils/util.hpp>
#include <linal/utils/warnings.hpp>
#include <linal/vec3.hpp>
TW_LINAL_DISABLE_ALL_WARNINGS
#include <blaze/math/StaticVector.h>
#include <blaze/util/AlignedAllocator.h>
TW_LINAL_ENABLE_ALL_WARNINGS

namespace linal
{

namespace hcoord
{

template <typename T>
using hvec = blaze::StaticVector<T, 4, blaze::columnVector, blaze::unaligned, blaze::unpadded>;

using hvecf = hvec<float>;
using hvecd = hvec<double>;

template <typename T>
using hvecAllocator = blaze::AlignedAllocator<hvec<T>>;

using hvecAllocatorf = hvecAllocator<float>;
using hvecAllocatord = hvecAllocator<double>;

constexpr hvecf ZERO_HVECF = hvecf{0, 0, 0, 1};
constexpr hvecf X_HVECF = hvecf{1, 0, 0, 1};
constexpr hvecf Y_HVECF = hvecf{0, 1, 0, 1};
constexpr hvecf Z_HVECF = hvecf{0, 0, 1, 1};

constexpr hvecd ZERO_HVECD = hvecd{0, 0, 0, 1};
constexpr hvecd X_HVECD = hvecd{1, 0, 0, 1};
constexpr hvecd Y_HVECD = hvecd{0, 1, 0, 1};
constexpr hvecd Z_HVECD = hvecd{0, 0, 1, 1};

template <typename T, std::size_t D>
LINAL_NODISCARD constexpr vec<T, D> hvec_to_vec(const hvec<T>& hvec) noexcept
{
  static_assert(D > 1 && D < 4);

  vec<T, D> result;
  for (std::size_t i = 0; i < D; ++i)
  {
    result[i] = hvec[i];
  }

  return result;
}

template <typename T, std::size_t D>
LINAL_NODISCARD constexpr hvec<T> vec_to_hvec(const vec<T, D>& vec) noexcept
{
  static_assert(D > 1 && D < 4);

  hvec<T> result;
  for (std::size_t i = 0; i < D; ++i)
  {
    result[i] = vec[i];
  }

  // Homogeneous coordinate is always 1
  result[3] = 1;

  return result;
}

template <typename T>
LINAL_NODISCARD constexpr T vec3_norm(const hvec<T>& hvec) noexcept
{
  vec<T, 3> vec = hvec_to_vec<T, 3>(hvec);
  return blaze::norm(vec);
}

} // namespace hcoord

} // namespace linal

#endif // LINAL_HVEC_HPP
