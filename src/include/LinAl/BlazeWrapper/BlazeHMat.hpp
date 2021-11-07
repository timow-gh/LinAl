#ifndef LINAL_BLAZEHMAT_HPP
#define LINAL_BLAZEHMAT_HPP

#include "LinAl/BlazeWrapper/BlazeHVec.hpp"

namespace LinAl
{
// clang-format off
template<typename T>
using HMatrix = blaze::StaticMatrix<T,
                                    4,
                                    4,
                                    blaze::rowMajor,
                                    blaze::aligned,
                                    blaze::padded>;
template<typename T>
using HMatrixAllocator = blaze::AlignedAllocator<HMatrix<T>>;
// clang-format on
} // namespace LinAl

#endif // LINAL_BLAZEHMAT_HPP
