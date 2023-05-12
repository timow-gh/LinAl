#ifndef LINAL_BLAZEHVECOPERATIONS_HPP
#define LINAL_BLAZEHVECOPERATIONS_HPP

#include <LinAl/BlazeWrapper/BlazeHVec.hpp>

namespace LinAl
{

template <typename T>
CORE_NODISCARD CORE_CONSTEXPR T hVecNorm2(const HVec<T>& hVec)
{
  return blaze::norm(hVecToVec3(hVec));
}

} // namespace LinAl

#endif // LINAL_BLAZEHVECOPERATIONS_HPP
