#ifndef LINAL_BLAZEHMAT_HPP
#define LINAL_BLAZEHMAT_HPP

#include <LinAl/Utils/Warnings.hpp>
DISABLE_ALL_WARNINGS
#include <blaze/math/StaticMatrix.h>
#include <blaze/util/AlignedAllocator.h>
ENABLE_ALL_WARNINGS

namespace LinAl
{

template <typename T>
using HMatrix = blaze::StaticMatrix<T, 4, 4, blaze::rowMajor, blaze::aligned, blaze::unpadded>;
using HMatrixf = HMatrix<float_t>;
using HMatrixd = HMatrix<double_t>;

template <typename T>
using HMatrixAllocator = blaze::AlignedAllocator<HMatrix<T>>;
using HMatrixAllocatorf = HMatrixAllocator<HMatrixf>;
using HMatrixAllocatord = HMatrixAllocator<HMatrixd>;

} // namespace LinAl

#endif // LINAL_BLAZEHMAT_HPP
