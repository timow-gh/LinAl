#ifndef GLFWTESTAPP_BLAZEMATRIXOPERATIONS_H
#define GLFWTESTAPP_BLAZEMATRIXOPERATIONS_H

#include "BlazeContainers.hpp"
#include "BlazeVec.hpp"

namespace LinAl
{
template <typename T, std::size_t M, std::size_t N>
using Matrix = blaze::
    StaticMatrix<T, M, N, blaze::rowMajor, blaze::aligned, blaze::padded>;

template <typename T>
using Matrix3 = blaze::
    StaticMatrix<T, 3, 3, blaze::rowMajor, blaze::aligned, blaze::padded>;

using Matrix3f = blaze::
    StaticMatrix<float_t, 3, 3, blaze::rowMajor, blaze::aligned, blaze::padded>;

using Matrix3d = blaze::StaticMatrix<double_t,
                                     3,
                                     3,
                                     blaze::rowMajor,
                                     blaze::aligned,
                                     blaze::padded>;

template <typename T, std::size_t M, std::size_t N>
using MatrixAllocator = blaze::AlignedAllocator<Matrix<T, M, N>>;
using Matrix3fAllocator = blaze::AlignedAllocator<Matrix3f>;
using Matrix3dAllocator = blaze::AlignedAllocator<Matrix3d>;
} // namespace LinAl

#endif // GLFWTESTAPP_BLAZEMATRIXOPERATIONS_H
