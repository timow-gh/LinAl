#ifndef LINAL_VEC_COMPARE_HPP
#define LINAL_VEC_COMPARE_HPP

#include <cstdint>
#include "linal/utils/compiler.hpp"
#include "linal/utils/eps.hpp"
#include "linal/vec.hpp"

namespace linal
{

/* @brief Checks if the elements of the vector are equal to zero with the given eps.*/
template <typename TVec, typename T>
LINAL_NODISCARD constexpr bool is_zero(const TVec& vec, const T eps) noexcept
{
  auto iter = vec.cbegin();
  auto end = vec.cend();
  while (iter != end)
  {
    if (!isZero(*iter, eps))
    {
      return false;
    }
    ++iter;
  }
  return true;
}

/* @brief Checks if the elements of the vector are equal to zero using the default eps.*/
template <typename TVec>
LINAL_NODISCARD constexpr bool is_zero(const TVec& vec) noexcept
{
  return is_zero(vec, linal::eps<typename TVec::value_type>::value);
}

/* @brief Compare two vectors with the given eps.*/
template <typename TVec, typename T>
LINAL_NODISCARD constexpr bool is_equal(const TVec& lhs, const TVec& rhs, const T eps) noexcept
{
  assert(lhs.dim == rhs.dim);
  auto lhsIter = lhs.cbegin();
  auto rhsIter = rhs.cbegin();
  auto end = lhs.cend();
  while (lhsIter != end)
  {
    if (!isEq(*lhsIter, *rhsIter, eps))
    {
      return false;
    }
    ++lhsIter;
    ++rhsIter;
  }
  return true;
}

/* @brief Compare two vectors using the default eps.*/
template <typename TVec>
LINAL_NODISCARD constexpr bool is_equal(const TVec& lhs, const TVec& rhs) noexcept
{
  return is_equal(lhs, rhs, linal::eps<typename TVec::value_type>::value);
}

} // namespace linal

#endif // LINAL_VEC_COMPARE_HPP
