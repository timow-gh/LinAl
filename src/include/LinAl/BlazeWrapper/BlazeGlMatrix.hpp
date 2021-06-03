#ifndef GLFWTESTAPP_BLAZEGLMATRIX_HPP
#define GLFWTESTAPP_BLAZEGLMATRIX_HPP

#include "LinAlBlaze.hpp"

namespace LinAl
{
using GlMatrix = blaze::StaticMatrix<float_t,
                                     4,
                                     4,
                                     blaze::rowMajor,
                                     blaze::unaligned,
                                     blaze::unpadded>;

using GlProjMatrixAllocator = blaze::AlignedAllocator<GlMatrix>;

} // namespace LinAl
#endif // GLFWTESTAPP_BLAZEGLMATRIX_HPP
