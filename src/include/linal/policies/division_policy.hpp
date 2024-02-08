#ifndef LINAL_DIVISION_POLICY_HPP
#define LINAL_DIVISION_POLICY_HPP

#include <type_traits>

namespace linal
{

template <typename array_type, typename array_traits>
struct division_policy
{
  using value_type = typename array_traits::value_type;
  using size_type = typename array_traits::size_type;
  static const size_type dim = array_traits::dim;

  template <typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
  constexpr array_type& operator/=(U scalar) noexcept
  {
    auto& lhs = static_cast<array_type&>(*this);
    for (size_type i = 0; i < dim; ++i)
    {
      lhs[i] /= scalar;
    }
    return lhs;
  }

  template <typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
  [[nodiscard]] friend constexpr array_type operator/(const array_type& rhs, U scalar) noexcept
  {
    return array_type(rhs) /= scalar;
  }
};

} // namespace linal

#endif // LINAL_DIVISION_POLICY_HPP
