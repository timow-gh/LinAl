#ifndef LINAL_UTILS_RADIANS_HPP
#define LINAL_UTILS_RADIANS_HPP

#include "linal/utils/constants.hpp"

namespace linal
{

template<typename T>
constexpr T degrees_to_radians(T degrees)
{
  return degrees * (linal::PI<T> / T(180.0));
}

template<typename T>
constexpr T radians_to_degrees(T radians)
{
  return radians * (T(180.0) / linal::PI<T>);
}

} // namespace linal

#endif // LINAL_UTILS_RADIANS_HPP