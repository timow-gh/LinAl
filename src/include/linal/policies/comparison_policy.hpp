#ifndef LINAL_COMPARISON_POLICY_HPP
#define LINAL_COMPARISON_POLICY_HPP

#include "linal/utils/eps.hpp"

namespace linal
{

template <typename array_type, typename array_traits>
class comparison_policy
{
  using value_type = typename array_traits::value_type;
  using size_type = typename array_traits::size_type;
  static const size_type dim = array_traits::dim;

  [[nodiscard]] constexpr friend bool operator==(const array_type& lhs, const array_type& rhs) noexcept
  {
    for (size_type idx = 0; idx < dim; ++idx)
    {
      if (!isEq(lhs[idx], rhs[idx]))
      {
        return false;
      }
    }
    return true;
  }

  [[nodiscard]] constexpr friend bool operator!=(const array_type& lhs, const array_type& rhs) noexcept { return !(lhs == rhs); }
};

} // namespace linal

#endif // LINAL_COMPARISON_POLICY_HPP
