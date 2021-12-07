#ifndef LINAL_BLAZEUTIL_HPP
#define LINAL_BLAZEUTIL_HPP

#include <LinAl/BlazeWrapper/BlazeHVec.hpp>
#include <LinAl/BlazeWrapper/BlazeVec3.hpp>

namespace LinAl
{
template <typename T>
auto calcCosSin(T alpha)
{
    return std::make_pair(std::cos(alpha), std::sin(alpha));
}

template <typename T>
Vec3<T> hVecToVec3(HVec<T> hVec)
{
    return Vec3<T>{hVec[0], hVec[1], hVec[2]};
}

template <typename T>
HVec<T> vec3ToHVec(Vec3<T> vec3)
{
    return HVec<T>{vec3[0], vec3[1], vec3[2], 1};
}

} // namespace LinAl

#endif // LINAL_BLAZEUTIL_HPP
