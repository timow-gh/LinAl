#ifndef LINAL_UTIL_HPP
#define LINAL_UTIL_HPP

#include <linal/hvec.hpp>
#include <linal/utils/compiler.hpp>
#include <linal/vec3.hpp>

namespace linal
{

struct linal_utils
{

  template <typename T>
  LINAL_NODISCARD static constexpr auto calcCosSin(T alphaRad) noexcept
  {
    return std::make_pair(std::cos(alphaRad), std::sin(alphaRad));
  }
};

} // namespace linal

#endif // LINAL_UTIL_HPP
