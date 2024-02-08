#ifndef LINAL_ELEMENT_ACCESS_POLICY_HPP
#define LINAL_ELEMENT_ACCESS_POLICY_HPP

#include "linal/utils/assert.hpp"
#include "linal/utils/compiler.hpp"

namespace linal
{

template <typename array_type, typename array_traits>
struct element_access_policy
{
  using value_type = typename array_traits::value_type;
  using reference = typename array_traits::reference;
  using size_type = typename array_traits::size_type;

  [[nodiscard]] constexpr reference operator()(size_type rowIdx, size_type colIdx) noexcept
  {
    auto& matrix = static_cast<array_type&>(*this);
    LINAL_ASSERT(rowIdx < matrix.noOfRows && colIdx < matrix.noOfCols);
    return matrix[rowIdx * matrix.noOfCols + colIdx];
  }

  [[nodiscard]] LINAL_CONST constexpr value_type operator()(size_type rowIdx, size_type colIdx) const noexcept
  {
    const auto& matrix = static_cast<const array_type&>(*this);
    LINAL_ASSERT(rowIdx < matrix.noOfRows && colIdx < matrix.noOfCols);
    return matrix[rowIdx * matrix.noOfCols + colIdx];
  }
};

} // namespace linal

#endif // LINAL_ELEMENT_ACCESS_POLICY_HPP
