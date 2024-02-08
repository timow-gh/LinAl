#ifndef LINAL_ADDITIONPOLICY_HPP
#define LINAL_ADDITIONPOLICY_HPP

#include <linal/array_type_traits.hpp>
#include <linal/utils/compiler.hpp>
#include <type_traits>

namespace linal
{

template <typename array_type, typename array_traits>
struct addition_policy
{
  using value_type = typename array_traits::value_type;
  using size_type = typename array_traits::size_type;
  static const size_type dim = array_traits::dim;

  constexpr array_type& operator+=(const array_type& rhs) noexcept
  {
    auto& lhs = static_cast<array_type&>(*this);
    for (size_type i = 0; i < dim; ++i)
    {
      lhs[i] += rhs[i];
    }
    return lhs;
  }

  [[nodiscard]] LINAL_CONST constexpr array_type operator+(const array_type& rhs) const noexcept
  {
    const auto& lhs = static_cast<const array_type&>(*this);
    array_type result{lhs};
    result += rhs;
    return result;
  }

  template <typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
  constexpr array_type& operator+=(U scalar) noexcept
  {
    auto& lhs = static_cast<array_type&>(*this);
    for (size_type i = 0; i < dim; ++i)
    {
      lhs[i] += scalar;
    }
    return lhs;
  }

  template <typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
  [[nodiscard]] LINAL_CONST friend constexpr array_type operator+(U scalar, array_type rhs) noexcept
  {
    for (size_type i = 0; i < dim; ++i)
    {
      rhs[i] += scalar;
    }
    return rhs;
  }

  template <typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
  [[nodiscard]] LINAL_CONST friend constexpr array_type operator+(array_type lhs, U scalar) noexcept
  {
    for (size_type i = 0; i < dim; ++i)
    {
      lhs[i] += scalar;
    }
    return lhs;
  }
};

} // namespace linal

#endif // LINAL_ADDITIONPOLICY_HPP
