#ifndef LINAL_UNARY_POLICY_HPP
#define LINAL_UNARY_POLICY_HPP

#include "linal/array_type_traits.hpp"
#include "linal/utils/compiler.hpp"

namespace linal
{

template <typename array_type, typename array_traits>
class unary_policy
{
public:
  using value_type = typename array_traits::value_type;
  using size_type = typename array_traits::size_type;
  static const size_type dim = array_traits::dim;

  [[nodiscard]] constexpr array_type& operator-() noexcept
  {
    auto& self = static_cast<array_type&>(*this);
    for (size_type idx = 0; idx < dim; ++idx)
    {
      self[idx] = -self[idx];
    }
    return self;
  }

  [[nodiscard]] LINAL_CONST constexpr array_type operator-() const noexcept
  {
    auto& self = static_cast<const array_type&>(*this);
    array_type result;
    for (size_type idx = 0; idx < dim; ++idx)
    {
      result[idx] = -self[idx];
    }
    return result;
  }
};

} // namespace linal

#endif // LINAL_UNARY_POLICY_HPP
