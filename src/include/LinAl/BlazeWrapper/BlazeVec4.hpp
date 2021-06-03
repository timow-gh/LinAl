#ifndef LINAL_BLAZEVEC4_HPP
#define LINAL_BLAZEVEC4_HPP

#include "BlazeVec.hpp"

namespace LinAl
{
template <typename T>
using Vec4 = blaze::StaticVector<T, 4>;
using Vec4f = blaze::StaticVector<float_t,
                                  4,
                                  blaze::columnVector,
                                  blaze::aligned,
                                  blaze::padded>;
using Vec4d = blaze::StaticVector<double_t,
                                  4,
                                  blaze::columnVector,
                                  blaze::aligned,
                                  blaze::padded>;

template <typename T, std::size_t D>
using VecAllocator = blaze::AlignedAllocator<Vec<T, D>>;
template <typename T>
using Vec4Allocator = blaze::AlignedAllocator<Vec<T, 4>>;
using Vec4fAllocator = blaze::AlignedAllocator<Vec4f>;
using Vec4dAllocator = blaze::AlignedAllocator<Vec4d>;
} // namespace LinAl

#endif // LINAL_BLAZEVEC4_HPP
