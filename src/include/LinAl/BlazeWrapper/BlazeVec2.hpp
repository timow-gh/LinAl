#ifndef LINAL_BLAZEVEC2_HPP
#define LINAL_BLAZEVEC2_HPP

#include <LinAl/BlazeWrapper/BlazeVec.hpp>

namespace LinAl
{

template <typename T>
using Vec2 = Vec<T, 2>;
using Vec2f = Vec2<float_t>;
using Vec2d = Vec2<double_t>;

template <typename T>
using VecAllocator2 = VecAllocator<T, 2>;
using VecAllocator2f = VecAllocator2<float_t>;
using VecAllocator2d = VecAllocator2<double_t>;

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
