#ifndef LINAL_BLAZEVEC3_HPP
#define LINAL_BLAZEVEC3_HPP

#include "BlazeVec.hpp"

namespace LinAl {
template <typename T> using Vec3 = blaze::StaticVector<T, 3>;
using Vec3f = blaze::StaticVector<float_t, 3, blaze::columnVector,
                                  blaze::aligned, blaze::padded>;
using Vec3d = blaze::StaticVector<double_t, 3, blaze::columnVector,
                                  blaze::aligned, blaze::padded>;

template <typename T> using Vec3Allocator = blaze::AlignedAllocator<Vec<T, 3>>;
using Vec3fAllocator = blaze::AlignedAllocator<Vec3f>;
using Vec3dAllocator = blaze::AlignedAllocator<Vec3d>;

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
