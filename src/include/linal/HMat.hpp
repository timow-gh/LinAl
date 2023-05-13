#ifndef LINAL_HMAT_HPP
#define LINAL_HMAT_HPP

#include <linal/utils/Warnings.hpp>
DISABLE_ALL_WARNINGS
#include <blaze/math/StaticMatrix.h>
#include <blaze/util/AlignedAllocator.h>
ENABLE_ALL_WARNINGS

namespace linal
{

template <typename T>
using HMatrix = blaze::StaticMatrix<T, 4, 4, blaze::rowMajor, blaze::aligned, blaze::unpadded>;
using HMatrixf = HMatrix<float_t>;
using HMatrixd = HMatrix<double_t>;

template <typename T>
using HMatrixAllocator = blaze::AlignedAllocator<HMatrix<T>>;
using HMatrixAllocatorf = HMatrixAllocator<HMatrixf>;
using HMatrixAllocatord = HMatrixAllocator<HMatrixd>;

} // namespace linal

#endif // LINAL_HMAT_HPP
