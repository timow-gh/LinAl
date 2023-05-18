#ifndef LINAL_UTIL_HPP
#define LINAL_UTIL_HPP

#include <linal/HVec.hpp>
#include <linal/Vec3.hpp>
#include <linal/utils/Compiler.hpp>

namespace linal
{

struct linal_utils
{

  template <typename T>
  LINAL_NODISCARD static LINAL_CONSTEXPR auto calcCosSin(T alphaRad)
  {
    return std::make_pair(std::cos(alphaRad), std::sin(alphaRad));
  }

};

} // namespace linal

#endif // LINAL_UTIL_HPP
