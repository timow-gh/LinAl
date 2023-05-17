#ifndef LINAL_UTIL_HPP
#define LINAL_UTIL_HPP

#include <linal/HVec.hpp>
#include <linal/Vec3.hpp>
#include <linal/utils/Compiler.hpp>

namespace linal
{

namespace linal_utils
{

template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR auto calcCosSin(T alphaRad)
{
  return std::make_pair(std::cos(alphaRad), std::sin(alphaRad));
}

template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR Vec3<T> hVecToVec3(const hcoord::hvec<T>& hVec)
{
  return Vec3<T>{hVec[0], hVec[1], hVec[2]};
}

template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR hcoord::hvec<T> vec3ToHVec(const Vec3<T>& vec3)
{
  return hcoord::hvec<T>{vec3[0], vec3[1], vec3[2], 1};
}

} // namespace linal_utils

} // namespace linal

#endif // LINAL_UTIL_HPP
