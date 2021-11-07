#ifndef LINAL_BLAZEHVEC_HPP
#define LINAL_BLAZEHVEC_HPP

namespace LinAl
{
// clang-format off
template <typename T>
using HVec = blaze::StaticVector<T,
                                4,
                                blaze::columnVector,
                                blaze::aligned,
                                blaze::padded>;
// clang-format on

template <typename T>
using HVecAllocator = blaze::AlignedAllocator<HVec<T>>;
} // namespace LinAl

#endif // LINAL_BLAZEHVEC_HPP
