#ifndef LINAL_BLAZEUTIL_HPP
#define LINAL_BLAZEUTIL_HPP

#include <Core/Utils/Compiler.hpp>
#include <LinAl/BlazeWrapper/BlazeHVec.hpp>
#include <LinAl/BlazeWrapper/BlazeVec3.hpp>

namespace LinAl
{

template <typename T>
CORE_NODISCARD CORE_CONSTEXPR auto calcCosSin(T alphaRad)
{
    return std::make_pair(std::cos(alphaRad), std::sin(alphaRad));
}

template <typename T, typename = std::enable_if<std::is_same_v<T, HVec<T>>>>
CORE_NODISCARD CORE_CONSTEXPR Vec3<T> hVecToVec3(const HVec<T>& hVec)
{
    return Vec3<T>{hVec[0], hVec[1], hVec[2]};
}

template <typename TVec,
          typename = std::enable_if<std::is_same_v<TVec, Vec3<typename TVec::value_type>>>>
CORE_NODISCARD CORE_CONSTEXPR HVec<typename TVec::value_type> vec3ToHVec(const TVec& vec3)
{
    return HVec<typename TVec::value_type>{vec3[0], vec3[1], vec3[2], 1};
}

} // namespace LinAl

#endif // LINAL_BLAZEUTIL_HPP
