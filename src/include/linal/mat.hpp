#ifndef LINAL_BLAZEMATRIXOPERATIONS_H
#define LINAL_BLAZEMATRIXOPERATIONS_H

#include <linal/utils/Compiler.hpp>
#include <linal/utils/warnings.hpp>
DISABLE_ALL_WARNINGS
#include <linal/containers.hpp>
#include <linal/vec.hpp>
ENABLE_ALL_WARNINGS

namespace linal
{

template <typename T, std::size_t M, std::size_t N>
using mat = blaze::StaticMatrix<T, M, N, blaze::rowMajor, blaze::aligned, blaze::unpadded>;

template <typename T>
using mat3 = mat<T, 3, 3>;
using mat3f = mat3<float>;
using mat3d = mat3<double>;

template <typename T, std::size_t M, std::size_t N>
using matAllocator = blaze::AlignedAllocator<mat<T, M, N>>;

template <typename T>
using matAllocator3 = matAllocator<T, 3, 3>;
using matAllocator3f = matAllocator3<float>;
using matAllocator3d = matAllocator3<double>;

template <typename T, std::size_t M, std::size_t N>
LINAL_CONSTEXPR void transpose(mat<T, M, N>& matrix)
{
  blaze::transpose(matrix);
}

} // namespace linal

#endif // LINAL_BLAZEMATRIXOPERATIONS_H
