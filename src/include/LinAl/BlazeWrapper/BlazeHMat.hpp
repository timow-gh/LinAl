#ifndef LINAL_BLAZEHMAT_HPP
#define LINAL_BLAZEHMAT_HPP

#include <LinAl/BlazeWrapper/BlazeHVec.hpp>

namespace LinAl
{

template <typename T>
class HMatrix
    : public blaze::StaticMatrix<T, 4, 4, blaze::rowMajor, blaze::aligned, blaze::padded> {
  public:
    using blaze::StaticMatrix<T, 4, 4>::StaticMatrix;
    using value_type = T;
};

using HMatrixf = HMatrix<float_t>;
using HMatrixd = HMatrix<double_t>;

template <typename T>
using HMatrixAllocator = blaze::AlignedAllocator<HMatrix<T>>;
using HMatrixAllocatorf = HMatrixAllocator<HMatrixf>;
using HMatrixAllocatord = HMatrixAllocator<HMatrixd>;

} // namespace LinAl

#endif // LINAL_BLAZEHMAT_HPP
