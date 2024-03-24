#ifndef LINAL_MAT_OPERATIONS_HPP
#define LINAL_MAT_OPERATIONS_HPP

#include <initializer_list>
#include <linal/mat_transposed_type_trait.hpp>
#include <linal/utils/eps.hpp>

namespace linal
{

template <typename TMat, typename T>
constexpr void diagonal(TMat& result, T value) noexcept
{
  using value_type = typename TMat::value_type;
  using size_type = typename TMat::size_type;
  constexpr size_type M = TMat::noOfCols;
  constexpr size_type N = TMat::noOfRows;

  for (size_type i = 0; i < M; ++i)
  {
    for (size_type j = 0; j < N; ++j)
    {
      if (i == j)
      {
        result[i * N + j] = value;
      }
      else
      {
        result[i * N + j] = value_type{0};
      }
    }
  }
}

template <typename TMat, typename TVec>
constexpr void from_rows(TMat& result, std::initializer_list<TVec> rows) noexcept
{
  using size_type = typename TMat::size_type;

  const size_type size = static_cast<size_type>(rows.size());

  assert(size == TMat::noOfCols && "Number of rows does not match column length.");
  for (size_type i = 0; i < size; ++i)
  {
    const auto& rowVec = rows.begin()[i];
    for (size_type j = 0; j < TMat::noOfCols; ++j)
    {
      result(i, j) = rowVec[j];
    }
  }
}

template <typename TMat, typename TVec>
constexpr void from_columns(TMat& result, std::initializer_list<TVec> columns) noexcept
{
  using size_type = typename TMat::size_type;
  [[maybe_unused]] constexpr size_type M = TMat::noOfCols;
  constexpr size_type N = TMat::noOfRows;

  const size_type size = static_cast<size_type>(columns.size());
  assert(size == M && "Number of columns does not match row length.");
  for (size_type j = 0; j < size; ++j)
  {
    const auto& columnVec = columns.begin()[j];
    for (size_type i = 0; i < N; ++i)
    {
      result(i, j) = columnVec[i];
    }
  }
}

template <typename TMat>
[[nodiscard]] constexpr auto transpose(const TMat& mat) noexcept
{
  using size_type = typename TMat::size_type;

  constexpr size_type M = TMat::noOfRows;
  constexpr size_type N = TMat::noOfCols;

  transpose_matrix_type_t<TMat> result;
  for (size_type i = 0; i < M; ++i)
  {
    for (size_type j = 0; j < N; ++j)
    {
      result(j, i) = mat(i, j);
    }
  }
  return result;
}

template <typename TMat>
[[nodiscard]] constexpr bool is_identity(const TMat& mat) noexcept
{
  using size_type = typename TMat::size_type;
  using value_type = typename TMat::value_type;
  constexpr size_type M = TMat::noOfCols;
  constexpr size_type N = TMat::noOfRows;
  static_assert(M == N, "TRhs must be square.");

  for (size_type i = 0; i < M; ++i)
  {
    for (size_type j = 0; j < N; ++j)
    {
      if (i == j)
      {
        if (!isEq(mat(i, j), value_type{1}))
        {
          return false;
        }
      }
      else
      {
        if (!isEq(mat(i, j), value_type{0}))
        {
          return false;
        }
      }
    }
  }
  return true;
}

template <typename TMat>
[[nodiscard]] constexpr bool is_symmetric(const TMat& mat) noexcept
{
  using size_type = typename TMat::size_type;
  constexpr size_type M = TMat::noOfCols;
  constexpr size_type N = TMat::noOfRows;

  static_assert(M == N, "TRhs must be square.");

  for (size_type i = 0; i < M; ++i)
  {
    for (size_type j = 0; j < N; ++j)
    {
      if (!isEq(mat(i, j), mat(j, i)))
      {
        return false;
      }
    }
  }
  return true;
}

} // namespace linal

#endif // LINAL_MAT_OPERATIONS_HPP
