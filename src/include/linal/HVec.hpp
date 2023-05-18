#ifndef LINAL_HVEC_HPP
#define LINAL_HVEC_HPP

#include <linal/Vec3.hpp>
#include <linal/utils/Util.hpp>
#include <linal/utils/Warnings.hpp>
DISABLE_ALL_WARNINGS
#include <blaze/math/StaticVector.h>
#include <blaze/util/AlignedAllocator.h>
ENABLE_ALL_WARNINGS

namespace linal
{

namespace hcoord
{

template <typename T>
using hvec = blaze::StaticVector<T, 4, blaze::columnVector, blaze::aligned, blaze::unpadded>;

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
LINAL_NODISCARD LINAL_CONSTEXPR Vec<T, D> hvec_to_vec(const hvec<T>& hVec)
{
  static_assert(D != 0 && D < 4, "Vec dimension must be less than 4");

  Vec<T, D> result;
  for (std::size_t i = 0; i < D; ++i)
  {
    result[i] = hVec[i];
  }

  return result;
}

template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR hvec<T> vec_to_hvec(const Vec<T, D>& vec)
{
  static_assert(D != 0 && D < 4, "Vec dimension must be less than 4");

  hvec<T> result;
  for (std::size_t i = 0; i < D; ++i)
  {
    result[i] = vec[i];
  }

  return result;
}

template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR T vec3_norm(const hvec<T>& hVec)
{
  Vec<T, 3> vec = hvec_to_vec<T, 3>(hVec);
  return blaze::norm(vec);
}

} // namespace hcoord

} // namespace linal

#endif // LINAL_HVEC_HPP
