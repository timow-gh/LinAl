#ifndef LINAL_BLAZECONTAINERS_H
#define LINAL_BLAZECONTAINERS_H

#include <array>
#include <linal/vec.hpp>
#include <linal/vec2.hpp>
#include <linal/vec3.hpp>
#include <linal/vec4.hpp>
#include <memory>
#include <vector>

namespace linal
{

template <typename T, std::size_t D>
using vecvector = std::vector<linal::vec<T, D>, linal::vecAllocator<T, D>>;

template <typename T>
using vec2vector = std::vector<linal::vec2<T>, linal::vecAllocator2<T>>;
using vec2fvector = std::vector<linal::vec2f, linal::vecAllocator2f>;
using vec2dvector = std::vector<linal::vec2d, linal::vecAllocator2d>;

template <typename T>
using vec3vector = std::vector<linal::vec3<T>, linal::vecAllocator3<T>>;
using vec3fvector = std::vector<linal::vec3f, linal::vecAllocator3f>;
using vec3dvector = std::vector<linal::vec3d, linal::vecAllocator3d>;

template <typename T>
using vec4vector = std::vector<linal::vec4<T>, linal::vecAllocator4<T>>;
using vec4fvector = std::vector<linal::vec4f, linal::vecAllocator4f>;
using vec4dvector = std::vector<linal::vec4d, linal::vecAllocator4d>;

template <typename T, std::size_t D, std::size_t N>
using vecArray = std::array<linal::vec<T, D>, N>;

template <typename T, std::size_t N>
using vec2Array = std::array<linal::vec2<T>, N>;
template <typename std::size_t N>
using vec2fArray = std::array<linal::vec2f, N>;
template <typename std::size_t N>
using vec2dArray = std::array<linal::vec2d, N>;

template <typename T, std::size_t N>
using vec3Array = std::array<linal::vec3<T>, N>;
template <typename std::size_t N>
using vec3fArray = std::array<linal::vec3f, N>;
template <typename std::size_t N>
using vec3dArray = std::array<linal::vec3d, N>;

} // namespace linal

#endif // LINAL_BLAZECONTAINERS_H
