#ifndef GLFWTESTAPP_EIGENLINEARALGEBRA_H
#define GLFWTESTAPP_EIGENLINEARALGEBRA_H

#include <LinAl/Utils/Warnings.hpp>
DISABLE_ALL_WARNINGS
#include <blaze/math/StaticVector.h>
#include <blaze/util/AlignedAllocator.h>
ENABLE_ALL_WARNINGS

namespace LinAl
{

template <typename T, std::size_t N>
using Vec = blaze::StaticVector<T, N, blaze::columnVector, blaze::aligned, blaze::unpadded>;

template <typename T, std::size_t D>
using VecAllocator = blaze::AlignedAllocator<Vec<T, D>>;

} // namespace LinAl

#endif // GLFWTESTAPP_EIGENLINEARALGEBRA_H
