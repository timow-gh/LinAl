#ifndef LINAL_UTIL_HPP
#define LINAL_UTIL_HPP

#include <linal/HVec.hpp>
#include <linal/Vec3.hpp>
#include <linal/utils/Compiler.hpp>

namespace linal
{

template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR auto calcCosSin(T alphaRad)
{
  return std::make_pair(std::cos(alphaRad), std::sin(alphaRad));
}

template <typename T, typename = std::enable_if<std::is_same_v<T, HVec<T>>>>
LINAL_NODISCARD LINAL_CONSTEXPR Vec3<T> hVecToVec3(const HVec<T>& hVec)
{
  return Vec3<T>{hVec[0], hVec[1], hVec[2]};
}

template <typename T, typename = std::enable_if<std::is_same_v<T, HVec<T>>>>
LINAL_NODISCARD LINAL_CONSTEXPR HVec<T> vec3ToHVec(const Vec3<T>& vec3)
{
  return HVec<T>{vec3[0], vec3[1], vec3[2], 1};
}

} // namespace linal

#endif // LINAL_UTIL_HPP
