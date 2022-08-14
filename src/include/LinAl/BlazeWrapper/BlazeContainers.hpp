#ifndef GLFWTESTAPP_BLAZECONTAINERS_H
#define GLFWTESTAPP_BLAZECONTAINERS_H

#include <LinAl/BlazeWrapper/BlazeVec.hpp>
#include <LinAl/BlazeWrapper/BlazeVec2.hpp>
#include <LinAl/BlazeWrapper/BlazeVec3.hpp>
#include <LinAl/BlazeWrapper/BlazeVec4.hpp>
#include <array>
#include <memory>
#include <vector>

namespace LinAl
{

template <typename T, std::size_t D>
using VecVector = std::vector<LinAl::Vec<T, D>, LinAl::VecAllocator<T, D>>;

template <typename T>
using Vec2Vector = std::vector<LinAl::Vec2<T>, LinAl::VecAllocator2<T>>;
using Vec2fVector = std::vector<LinAl::Vec2f, LinAl::VecAllocator2f>;
using Vec2dVector = std::vector<LinAl::Vec2d, LinAl::VecAllocator2d>;

template <typename T>
using Vec3Vector = std::vector<LinAl::Vec3<T>, LinAl::VecAllocator3<T>>;
using Vec3fVector = std::vector<LinAl::Vec3f, LinAl::VecAllocator3f>;
using Vec3dVector = std::vector<LinAl::Vec3d, LinAl::VecAllocator3d>;

template <typename T>
using Vec4Vector = std::vector<LinAl::Vec4<T>, LinAl::VecAllocator4<T>>;
using Vec4fVector = std::vector<LinAl::Vec4f, LinAl::VecAllocator4f>;
using Vec4dVector = std::vector<LinAl::Vec4d, LinAl::VecAllocator4d>;

template <typename T, std::size_t D, std::size_t N>
using VecArray = std::array<LinAl::Vec<T, D>, N>;

template <typename T, std::size_t N>
using Vec2Array = std::array<LinAl::Vec2<T>, N>;
template<typename std::size_t N>
using Vec2fArray = std::array<LinAl::Vec2f, N>;
template<typename std::size_t N>
using Vec2dArray = std::array<LinAl::Vec2d, N>;

template <typename T, std::size_t N>
using Vec3Array = std::array<LinAl::Vec3<T>, N>;
template<typename std::size_t N>
using Vec3fArray = std::array<LinAl::Vec3f, N>;
template<typename std::size_t N>
using Vec3dArray = std::array<LinAl::Vec3d, N>;

} // namespace LinAl

#endif // GLFWTESTAPP_BLAZECONTAINERS_H
