#ifndef LINAL_VEC3_HPP
#define LINAL_VEC3_HPP

#include <linal/vec.hpp>

namespace linal
{

template <typename T>
using vec3 = vec<T, 3>;
using vec3f = vec3<float>;
using vec3d = vec3<double>;

template <typename T>
using vecAllocator3 = vecAllocator<T, 3>;
using vecAllocator3f = vecAllocator3<float>;
using vecAllocator3d = vecAllocator3<double>;

constexpr vec3f ZERO_VEC3F = vec3f{0, 0, 0};
constexpr vec3f X_VEC3F = vec3f{1, 0, 0};
constexpr vec3f Y_VEC3F = vec3f{0, 1, 0};
constexpr vec3f Z_VEC3F = vec3f{0, 0, 1};

constexpr vec3d ZERO_VEC3D = vec3d{0, 0, 0};
constexpr vec3d X_VEC3D = vec3d{1, 0, 0};
constexpr vec3d Y_VEC3D = vec3d{0, 1, 0};
constexpr vec3d Z_VEC3D = vec3d{0, 0, 1};

} // namespace linal
#endif // LINAL_VEC3_HPP
