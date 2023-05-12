#ifndef GLFWTESTAPP_BLAZEMATRIXOPERATIONS_H
#define GLFWTESTAPP_BLAZEMATRIXOPERATIONS_H

#include <LinAl/Utils/Warnings.hpp>
DISABLE_ALL_WARNINGS
#include <LinAl/BlazeWrapper/BlazeContainers.hpp>
#include <LinAl/BlazeWrapper/BlazeVec.hpp>
ENABLE_ALL_WARNINGS

namespace LinAl
{

template <typename T, std::size_t M, std::size_t N>
using Matrix = blaze::StaticMatrix<T, M, N, blaze::rowMajor, blaze::aligned, blaze::unpadded>;

template <typename T>
using Matrix3 = Matrix<T, 3, 3>;
using Matrix3f = Matrix3<float_t>;
using Matrix3d = Matrix3<double_t>;

template <typename T, std::size_t M, std::size_t N>
using MatrixAllocator = blaze::AlignedAllocator<Matrix<T, M, N>>;

template <typename T>
using MatrixAllocator3 = MatrixAllocator<T, 3, 3>;
using MatrixAllocator3f = MatrixAllocator3<float_t>;
using MatrixAllocator3d = MatrixAllocator3<double_t>;

} // namespace LinAl

#endif // GLFWTESTAPP_BLAZEMATRIXOPERATIONS_H
