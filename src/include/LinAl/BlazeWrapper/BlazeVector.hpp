#ifndef GLFWTESTAPP_EIGENLINEARALGEBRA_H
#define GLFWTESTAPP_EIGENLINEARALGEBRA_H

#include "LinAlBlaze.hpp"

namespace LinAl {
template <typename T, std::size_t D>
using Vec = blaze::StaticVector<T, D, blaze::columnVector, blaze::aligned,
                                blaze::padded>;

template <typename T> using Vec2 = blaze::StaticVector<T, 2>;
using Vec2f = blaze::StaticVector<float_t, 2, blaze::columnVector,
                                  blaze::aligned, blaze::padded>;
using Vec2d = blaze::StaticVector<double_t, 2, blaze::columnVector,
                                  blaze::aligned, blaze::padded>;

template <typename T, std::size_t D>
using VecAllocator = blaze::AlignedAllocator<Vec<T, D>>;
template <typename T> using Vec2Allocator = blaze::AlignedAllocator<Vec<T, 2>>;
using Vec2fAllocator = blaze::AlignedAllocator<Vec2f>;
using Vec2dAllocator = blaze::AlignedAllocator<Vec2d>;

constexpr Vec2f ZERO_VEC2F = Vec2f{0, 0};
constexpr Vec2f X_VEC2F = Vec2f{1, 0};
constexpr Vec2f Y_VEC2F = Vec2f{0, 1};
constexpr Vec2f Z_VEC2F = Vec2f{0, 0};

constexpr Vec2d ZERO_VEC2D = Vec2d{0, 0};
constexpr Vec2d X_VEC2D = Vec2d{1, 0};
constexpr Vec2d Y_VEC2D = Vec2d{0, 1};
constexpr Vec2d Z_VEC2D = Vec2d{0, 0};

template <typename T> using Vec3 = blaze::StaticVector<T, 3>;
using Vec3f = blaze::StaticVector<float_t, 3, blaze::columnVector,
                                  blaze::aligned, blaze::padded>;
using Vec3d = blaze::StaticVector<double_t, 3, blaze::columnVector,
                                  blaze::aligned, blaze::padded>;

template <typename T, std::size_t D>
using VecAllocator = blaze::AlignedAllocator<Vec<T, D>>;
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

template <typename T> using Vec4 = blaze::StaticVector<T, 4>;
using Vec4f = blaze::StaticVector<float_t, 4, blaze::columnVector,
                                  blaze::aligned, blaze::padded>;
using Vec4d = blaze::StaticVector<double_t, 4, blaze::columnVector,
                                  blaze::aligned, blaze::padded>;

template <typename T, std::size_t D>
using VecAllocator = blaze::AlignedAllocator<Vec<T, D>>;
template <typename T> using Vec4Allocator = blaze::AlignedAllocator<Vec<T, 4>>;
using Vec4fAllocator = blaze::AlignedAllocator<Vec4f>;
using Vec4dAllocator = blaze::AlignedAllocator<Vec4d>;
} // namespace LinAl

#endif // GLFWTESTAPP_EIGENLINEARALGEBRA_H
