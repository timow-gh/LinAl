#ifndef LINAL_VEC_COMPARE_HPP
#define LINAL_VEC_COMPARE_HPP

#include <cstdint>
#include <linal/utils/compiler.hpp>
#include <linal/utils/eps.hpp>
#include <linal/vec.hpp>

namespace linal
{

/* @brief Checks if the elements of the vector are equal to zero with the given eps.*/
template <typename T, std::size_t N>
LINAL_NODISCARD constexpr bool is_zero(linal::vec<T, N> vec, const T eps) noexcept
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
template <typename T, std::size_t N>
LINAL_NODISCARD constexpr bool is_zero(linal::vec<T, N> vec) noexcept
{
  return is_zero(vec, linal::eps<T>::value);
}

/* @brief Compare two vectors with the given eps.*/
template <typename T, std::size_t N>
LINAL_NODISCARD constexpr bool is_equal(linal::vec<T, N> lhs, linal::vec<T, N> rhs, const T eps) noexcept
{
  assert(lhs.size() == rhs.size());
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
template <typename T, std::size_t N>
LINAL_NODISCARD constexpr bool is_equal(linal::vec<T, N> lhs, linal::vec<T, N> rhs) noexcept
{
  return is_equal(lhs, rhs, linal::eps<T>::value);
}

} // namespace linal

#endif // LINAL_VEC_COMPARE_HPP
