#ifndef LINAL_BLAZEVEC4_HPP
#define LINAL_BLAZEVEC4_HPP

#include <LinAl/BlazeWrapper/BlazeVec.hpp>

namespace LinAl
{

template <typename T>
using Vec4 = Vec<T, 4>;
using Vec4f = Vec4<float_t>;
using Vec4d = Vec4<double_t>;

template <typename T>
using VecAllocator4 = VecAllocator<T, 4>;
using VecAllocator4f = VecAllocator4<float_t>;
using VecAllocator4d = VecAllocator4<double_t>;

} // namespace LinAl

#endif // LINAL_BLAZEVEC4_HPP
