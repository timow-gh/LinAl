#ifndef GLFWTESTAPP_BLAZECONTAINERS_H
#define GLFWTESTAPP_BLAZECONTAINERS_H

#include "BlazeVec.hpp"
#include "BlazeVec2.hpp"
#include "BlazeVec3.hpp"
#include <array>
#include <memory>
#include <vector>

namespace LinAl {

template <typename T, std::size_t D>
using VecVector = std::vector<LinAl::Vec<T, D>, LinAl::VecAllocator<T, D>>;

template <typename T>
using Vec3Vector = std::vector<LinAl::Vec3<T>, LinAl::Vec3Allocator<T>>;

using Vec3fVector = std::vector<LinAl::Vec3f, LinAl::Vec3fAllocator>;

using Vec3dVector = std::vector<LinAl::Vec3d, LinAl::Vec3dAllocator>;

template <typename T, std::size_t D, std::size_t N>
using VecArray = std::array<LinAl::Vec<T, D>, N>;

template <typename T, std::size_t N>
using Vec2Array = std::array<LinAl::Vec2<T>, N>;

template <std::size_t N> using Vec2fArray = std::array<LinAl::Vec2f, N>;

template <std::size_t N> using Vec2dArray = std::array<LinAl::Vec2d, N>;

template <typename T, std::size_t N>
using Vec3Array = std::array<LinAl::Vec3<T>, N>;

template <std::size_t N> using Vec3fArray = std::array<LinAl::Vec3f, N>;

template <std::size_t N> using Vec3dArray = std::array<LinAl::Vec3d, N>;

} // namespace LinAl

#endif // GLFWTESTAPP_BLAZECONTAINERS_H
