#ifndef LINAL_HVECOPERATIONS_HPP
#define LINAL_HVECOPERATIONS_HPP

#include <linal/HVec.hpp>

namespace linal
{

template <typename T>
LINAL_NODISCARD LINAL_CONSTEXPR T hVecNorm2(const HVec<T>& hVec)
{
  return blaze::norm(hVecToVec3(hVec));
}

} // namespace linal

#endif // LINAL_HVECOPERATIONS_HPP
