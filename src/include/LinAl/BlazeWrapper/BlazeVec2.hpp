#ifndef LINAL_BLAZEVEC2_HPP
#define LINAL_BLAZEVEC2_HPP

#include "BlazeVec.hpp"

namespace LinAl {
template <typename T> using Vec2 = blaze::StaticVector<T, 2>;
using Vec2f = blaze::StaticVector<float_t, 2, blaze::columnVector,
                                  blaze::aligned, blaze::padded>;
using Vec2d = blaze::StaticVector<double_t, 2, blaze::columnVector,
                                  blaze::aligned, blaze::padded>;

template <typename T> using Vec2Allocator = blaze::AlignedAllocator<Vec2<T>>;
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
} // namespace LinAl

#endif // LINAL_BLAZEVEC2_HPP
