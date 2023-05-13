#ifndef LINAL_VEC4_HPP
#define LINAL_VEC4_HPP

#include <linal/Vec.hpp>

namespace linal
{

template <typename T>
using Vec4 = Vec<T, 4>;
using Vec4f = Vec4<float_t>;
using Vec4d = Vec4<double_t>;

template <typename T>
using VecAllocator4 = VecAllocator<T, 4>;
using VecAllocator4f = VecAllocator4<float_t>;
using VecAllocator4d = VecAllocator4<double_t>;

} // namespace linal

#endif // LINAL_VEC4_HPP
