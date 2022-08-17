#ifndef GLFWTESTAPP_EIGENLINEARALGEBRA_H
#define GLFWTESTAPP_EIGENLINEARALGEBRA_H

#include <Core/Utils/Compiler.hpp>
#include <LinAl/BlazeWrapper/LinAlBlaze.hpp>

namespace LinAl
{

template <typename T, std::size_t N>
class Vec : public blaze::StaticVector<T, N, blaze::columnVector, blaze::aligned, blaze::padded> {
  public:
    using blaze::StaticVector<T, N>::StaticVector;
    using value_type = T;
};

template <typename T, std::size_t D>
using VecAllocator = blaze::AlignedAllocator<Vec<T, D>>;

} // namespace LinAl

#endif // GLFWTESTAPP_EIGENLINEARALGEBRA_H
