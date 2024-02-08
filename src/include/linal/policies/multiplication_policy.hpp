#ifndef LINAL_MULTIPLICATION_POLICY_HPP
#define LINAL_MULTIPLICATION_POLICY_HPP

#include "linal/utils/compiler.hpp"
#include <type_traits>

namespace linal
{

template <typename array_type, typename array_traits>
struct multiplication_policy
{
  using value_type = typename array_traits::value_type;
  using size_type = typename array_traits::size_type;
  static const size_type dim = array_traits::dim;

  template <typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
  constexpr array_type& operator*=(U scalar) noexcept
  {
    auto& lhs = static_cast<array_type&>(*this);
    for (size_type i = 0; i < dim; ++i)
    {
      lhs[i] *= scalar;
    }
    return lhs;
  }

  template <typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
  [[nodiscard]] LINAL_CONST constexpr friend array_type operator*(array_type lhs, U scalar) noexcept
  {
    return lhs *= scalar;
  }

  template <typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
  [[nodiscard]] LINAL_CONST constexpr friend array_type operator*(U scalar, array_type rhs) noexcept
  {
    return rhs *= scalar;
  }
};

} // namespace linal

#endif // LINAL_MULTIPLICATION_POLICY_HPP
