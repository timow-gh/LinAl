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

using HMatrixf = blaze::StaticMatrix<float_t,
                                    4,
                                    4,
                                    blaze::rowMajor,
                                    blaze::aligned,
                                    blaze::padded>;

using HMatrixd = blaze::StaticMatrix<double_t,
                                    4,
                                    4,
                                    blaze::rowMajor,
                                    blaze::aligned,
                                    blaze::padded>;

template<typename T>
using HMatrixAllocator = blaze::AlignedAllocator<HMatrix<T>>;
using HMatrixfAllocator = blaze::AlignedAllocator<HMatrixf>;
using HMatrixdAllocator = blaze::AlignedAllocator<HMatrixd>;
// clang-format on
} // namespace LinAl

#endif // LINAL_BLAZEHMAT_HPP
