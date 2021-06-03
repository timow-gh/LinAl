#ifndef GLFWTESTAPP_EIGENLINEARALGEBRA_H
#define GLFWTESTAPP_EIGENLINEARALGEBRA_H

#include "LinAlBlaze.hpp"

namespace LinAl
{
template <typename T, std::size_t D>
using Vec = blaze::
    StaticVector<T, D, blaze::columnVector, blaze::aligned, blaze::padded>;

template <typename T, std::size_t D>
using VecAllocator = blaze::AlignedAllocator<Vec<T, D>>;
} // namespace LinAl

#endif // GLFWTESTAPP_EIGENLINEARALGEBRA_H
