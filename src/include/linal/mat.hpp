#ifndef LINAL_BLAZEMATRIXOPERATIONS_H
#define LINAL_BLAZEMATRIXOPERATIONS_H

#include <linal/containers.hpp>
#include <linal/utils/compiler.hpp>
#include <linal/utils/warnings.hpp>
#include <linal/vec.hpp>

namespace linal
{

template <typename T, std::size_t M, std::size_t N>
using mat = blaze::StaticMatrix<T, M, N, blaze::rowMajor, blaze::unaligned, blaze::unpadded>;

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
void transpose(mat<T, M, N>& matrix) noexcept
{
  blaze::transpose(matrix);
}

} // namespace linal

#endif // LINAL_BLAZEMATRIXOPERATIONS_H
