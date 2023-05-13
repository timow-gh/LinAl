#ifndef GLFWTESTAPP_EIGENLINEARALGEBRA_H
#define GLFWTESTAPP_EIGENLINEARALGEBRA_H

#include <linal/utils/Warnings.hpp>
DISABLE_ALL_WARNINGS
#include <blaze/math/StaticVector.h>
#include <blaze/util/AlignedAllocator.h>
ENABLE_ALL_WARNINGS

namespace linal
{

template <typename T, std::size_t N>
using Vec = blaze::StaticVector<T, N, blaze::columnVector, blaze::aligned, blaze::padded>;

template <typename T, std::size_t D>
using VecAllocator = blaze::AlignedAllocator<Vec<T, D>>;

} // namespace linal

#endif // GLFWTESTAPP_EIGENLINEARALGEBRA_H
