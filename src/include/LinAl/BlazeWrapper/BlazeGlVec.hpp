#ifndef GLFWTESTAPP_BLAZEGLVECTOR_HPP
#define GLFWTESTAPP_BLAZEGLVECTOR_HPP

#include "LinAlBlaze.hpp"

namespace LinAl {
using GLVecf = blaze::StaticVector<float_t, 4, blaze::rowMajor,
                                   blaze::unaligned, blaze::unpadded>;

using GLVecfAllocator = blaze::AlignedAllocator<GLVecf>;
} // namespace LinAl

#endif // GLFWTESTAPP_BLAZEGLVECTOR_HPP
