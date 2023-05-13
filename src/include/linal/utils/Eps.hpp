#ifndef LINAL_EPS_H
#define LINAL_EPS_H

namespace linal
{

template <typename TFloat>
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

template <typename TFloat>
constexpr inline TFloat eps_f = eps<TFloat>::value;

constexpr inline float eps_f32{eps_f<float>};
constexpr inline double eps_f64{eps_f<double>};

template <typename T>
LINAL_CONSTEXPR bool isZero(T value, T eps)
{
  return std::abs(value) < eps;
}

template <typename T>
LINAL_CONSTEXPR bool isZero(T value)
{
  return isZero(value, eps<T>::value());
}

template <typename T>
LINAL_CONSTEXPR bool isLess(T lhs, T rhs, T eps)
{
  return lhs + eps < rhs;
}

template <typename T>
LINAL_CONSTEXPR bool isLess(T lhs, T rhs)
{
  return isLess(lhs, rhs, eps<T>::value());
}

template <typename T>
LINAL_CONSTEXPR bool isLessEq(T lhs, T rhs, T eps)
{
  return !(isLess(rhs, lhs, eps));
}

template <typename T>
LINAL_CONSTEXPR bool isLessEq(T lhs, T rhs)
{
  return isLessEq(lhs, rhs, eps<T>::value());
}

template <typename T>
LINAL_CONSTEXPR bool isGreater(T lhs, T rhs, T eps)
{
  return isLess(rhs, lhs, eps);
}

template <typename T>
LINAL_CONSTEXPR bool isGreater(T lhs, T rhs)
{
  return isGreater(lhs, rhs, eps<T>::value());
}

template <typename T>
LINAL_CONSTEXPR bool isGreaterEq(T lhs, T rhs, T eps)
{
  return !isLess(lhs, rhs, eps);
}

template <typename T>
LINAL_CONSTEXPR bool isGreaterEq(T lhs, T rhs)
{
  return isGreaterEq(lhs, rhs, eps<T>::value());
}

template <typename T>
LINAL_CONSTEXPR bool isEq(T lhs, T rhs, T eps)
{
  return std::abs(lhs - rhs) < eps;
}

template <typename T>
LINAL_CONSTEXPR bool isEq(T lhs, T rhs)
{
  return isEq(lhs, rhs, eps<T>::value());
}

} // namespace linal

#endif // LINAL_EPS_H
