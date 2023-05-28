#ifndef LINAL_EPS_H
#define LINAL_EPS_H

#include <cmath>
#include <linal/utils/compiler.hpp>

namespace linal
{

template <typename T>
struct eps;

template <>
struct eps<float>
{
  static constexpr float value{1e-6F};
};

template <>
struct eps<double>
{
  static constexpr double value{1e-12};
};

template <typename T>
constexpr inline T eps_v = eps<T>::value;

constexpr inline float eps_f32{eps_v<float>};
constexpr inline double eps_f64{eps_v<double>};

template <typename T>
constexpr bool isZero(T value, T eps) noexcept
{
  return std::abs(value) < eps;
}

template <typename T>
constexpr bool isZero(T value) noexcept
{
  return isZero(value, eps<T>::value);
}

template <typename T>
constexpr bool isLess(T lhs, T rhs, T eps) noexcept
{
  return lhs + eps < rhs;
}

template <typename T>
constexpr bool isLess(T lhs, T rhs) noexcept
{
  return isLess(lhs, rhs, eps<T>::value);
}

template <typename T>
constexpr bool isLessEq(T lhs, T rhs, T eps) noexcept
{
  return !(isLess(rhs, lhs, eps));
}

template <typename T>
constexpr bool isLessEq(T lhs, T rhs) noexcept
{
  return isLessEq(lhs, rhs, eps<T>::value);
}

template <typename T>
constexpr bool isGreater(T lhs, T rhs, T eps) noexcept
{
  return isLess(rhs, lhs, eps);
}

template <typename T>
constexpr bool isGreater(T lhs, T rhs) noexcept
{
  return isGreater(lhs, rhs, eps<T>::value);
}

template <typename T>
constexpr bool isGreaterEq(T lhs, T rhs, T eps) noexcept
{
  return !isLess(lhs, rhs, eps);
}

template <typename T>
constexpr bool isGreaterEq(T lhs, T rhs) noexcept
{
  return isGreaterEq(lhs, rhs, eps<T>::value);
}

template <typename T>
constexpr bool isEq(T lhs, T rhs, T eps) noexcept
{
  return std::abs(lhs - rhs) < eps;
}

template <typename T>
constexpr bool isEq(T lhs, T rhs) noexcept
{
  return isEq(lhs, rhs, eps<T>::value);
}

} // namespace linal

#endif // LINAL_EPS_H
