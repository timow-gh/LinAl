#ifndef LINAL_EIGENLINEARALGEBRA_H
#define LINAL_EIGENLINEARALGEBRA_H

#include <linal/utils/warnings.hpp>
TW_LINAL_DISABLE_ALL_WARNINGS
#include <blaze/math/StaticVector.h>
#include <blaze/util/AlignedAllocator.h>
TW_LINAL_ENABLE_ALL_WARNINGS

namespace linal
{

template <typename T, std::size_t N>
using vec = blaze::StaticVector<T, N, blaze::columnVector, blaze::unaligned, blaze::unpadded>;

template <typename T, std::size_t D>
using vecAllocator = blaze::AlignedAllocator<vec<T, D>>;

} // namespace linal

#endif // LINAL_EIGENLINEARALGEBRA_H
