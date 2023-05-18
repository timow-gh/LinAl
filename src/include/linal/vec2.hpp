#ifndef LINAL_VEC2_HPP
#define LINAL_VEC2_HPP

#include <linal/vec.hpp>

namespace linal
{

template <typename T>
using vec2 = vec<T, 2>;
using vec2f = vec2<float>;
using vec2d = vec2<double>;

template <typename T>
using vecAllocator2 = vecAllocator<T, 2>;
using vecAllocator2f = vecAllocator2<float>;
using vecAllocator2d = vecAllocator2<double>;

constexpr vec2f ZERO_VEC2F = vec2f{0, 0};
constexpr vec2f X_VEC2F = vec2f{1, 0};
constexpr vec2f Y_VEC2F = vec2f{0, 1};
constexpr vec2f Z_VEC2F = vec2f{0, 0};

constexpr vec2d ZERO_VEC2D = vec2d{0, 0};
constexpr vec2d X_VEC2D = vec2d{1, 0};
constexpr vec2d Y_VEC2D = vec2d{0, 1};
constexpr vec2d Z_VEC2D = vec2d{0, 0};

} // namespace linal

#endif // LINAL_VEC2_HPP
