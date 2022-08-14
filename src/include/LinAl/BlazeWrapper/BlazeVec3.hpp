#ifndef LINAL_BLAZEVEC3_HPP
#define LINAL_BLAZEVEC3_HPP

#include <LinAl/BlazeWrapper/BlazeVec.hpp>

namespace LinAl
{

template <typename T>
using Vec3 = Vec<T, 3>;
using Vec3f = Vec3<float_t>;
using Vec3d = Vec3<double_t>;

template <typename T>
using VecAllocator3 = VecAllocator<T, 3>;
using VecAllocator3f = VecAllocator3<float_t>;
using VecAllocator3d = VecAllocator3<double_t>;

constexpr Vec3f ZERO_VEC3F = Vec3f{0, 0, 0};
constexpr Vec3f X_VEC3F = Vec3f{1, 0, 0};
constexpr Vec3f Y_VEC3F = Vec3f{0, 1, 0};
constexpr Vec3f Z_VEC3F = Vec3f{0, 0, 1};

constexpr Vec3d ZERO_VEC3D = Vec3d{0, 0, 0};
constexpr Vec3d X_VEC3D = Vec3d{1, 0, 0};
constexpr Vec3d Y_VEC3D = Vec3d{0, 1, 0};
constexpr Vec3d Z_VEC3D = Vec3d{0, 0, 1};

} // namespace LinAl
#endif // LINAL_BLAZEVEC3_HPP
