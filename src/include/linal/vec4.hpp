#ifndef LINAL_VEC4_HPP
#define LINAL_VEC4_HPP

#include <linal/vec.hpp>

namespace linal
{

template <typename T>
using vec4 = vec<T, 4>;
using vec4f = vec4<float>;
using vec4d = vec4<double>;

template <typename T>
using vecAllocator4 = vecAllocator<T, 4>;
using vecAllocator4f = vecAllocator4<float>;
using vecAllocator4d = vecAllocator4<double>;

} // namespace linal

#endif // LINAL_VEC4_HPP
