#ifndef GLFWTESTAPP_BLAZECONTAINERS_H
#define GLFWTESTAPP_BLAZECONTAINERS_H

#include <array>
#include <linal/Vec.hpp>
#include <linal/Vec2.hpp>
#include <linal/Vec3.hpp>
#include <linal/Vec4.hpp>
#include <memory>
#include <vector>

namespace linal
{

template <typename T, std::size_t D>
using VecVector = std::vector<linal::Vec<T, D>, linal::VecAllocator<T, D>>;

template <typename T>
using Vec2Vector = std::vector<linal::Vec2<T>, linal::VecAllocator2<T>>;
using Vec2fVector = std::vector<linal::Vec2f, linal::VecAllocator2f>;
using Vec2dVector = std::vector<linal::Vec2d, linal::VecAllocator2d>;

template <typename T>
using Vec3Vector = std::vector<linal::Vec3<T>, linal::VecAllocator3<T>>;
using Vec3fVector = std::vector<linal::Vec3f, linal::VecAllocator3f>;
using Vec3dVector = std::vector<linal::Vec3d, linal::VecAllocator3d>;

template <typename T>
using Vec4Vector = std::vector<linal::Vec4<T>, linal::VecAllocator4<T>>;
using Vec4fVector = std::vector<linal::Vec4f, linal::VecAllocator4f>;
using Vec4dVector = std::vector<linal::Vec4d, linal::VecAllocator4d>;

template <typename T, std::size_t D, std::size_t N>
using VecArray = std::array<linal::Vec<T, D>, N>;

template <typename T, std::size_t N>
using Vec2Array = std::array<linal::Vec2<T>, N>;
template <typename std::size_t N>
using Vec2fArray = std::array<linal::Vec2f, N>;
template <typename std::size_t N>
using Vec2dArray = std::array<linal::Vec2d, N>;

template <typename T, std::size_t N>
using Vec3Array = std::array<linal::Vec3<T>, N>;
template <typename std::size_t N>
using Vec3fArray = std::array<linal::Vec3f, N>;
template <typename std::size_t N>
using Vec3dArray = std::array<linal::Vec3d, N>;

} // namespace linal

#endif // GLFWTESTAPP_BLAZECONTAINERS_H
