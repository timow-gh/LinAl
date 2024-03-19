#ifndef LINAL_BLAZEMATRIXOPERATIONS_H
#define LINAL_BLAZEMATRIXOPERATIONS_H

#include "linal/array_type_traits.hpp"
#include "linal/mat_operations.hpp"
#include "linal/policies/addition_policy.hpp"
#include "linal/policies/comparison_policy.hpp"
#include "linal/policies/division_policy.hpp"
#include "linal/policies/element_access_policy.hpp"
#include "linal/policies/multiplication_policy.hpp"
#include "linal/policies/subtraction_policy.hpp"
#include "linal/utils/compiler.hpp"
#include "linal/vec.hpp"

namespace linal
{

template <typename T, int M, int N>
class mat;

template <typename T, int M, int N>
[[nodiscard]] constexpr bool is_orthogonal(const mat<T, M, N>& mat) noexcept;

template <typename LMat, typename RMat, typename TResult>
constexpr TResult matrix_multiply(const LMat& lhs, const RMat& rhs) noexcept;

template <typename TMat, typename TVec>
constexpr TVec matrix_vec_multiply(const TMat& lhs, const TVec& rhs) noexcept;

/* @brief A matrix class.
 *
 * @attention This matrix class has row major storage.
 *
 * @tparam T The type of the matrix elements.
 * @tparam M The number of rows
 * @tparam N The number of columns.
 */
template <typename T, int M, int N>
class mat
    : public element_access_policy<mat<T, M, N>, array_traits<T, decltype(M), M * N>>
    , public addition_policy<mat<T, M, N>, array_traits<T, decltype(M), M * N>>
    , public subtraction_policy<mat<T, M, N>, array_traits<T, decltype(M), M * N>>
    , public multiplication_policy<mat<T, M, N>, array_traits<T, decltype(M), M * N>>
    , public division_policy<mat<T, M, N>, array_traits<T, decltype(M), M * N>>
    , public comparison_policy<mat<T, M, N>, array_traits<T, decltype(M), M * N>>
    , public unary_policy<mat<T, M, N>, array_traits<T, decltype(M), M * N>>
{
public:
  using value_type = T;
  using size_type = int;
  using iterator = T*;
  using const_iterator = const T*;
  using reference = T&;

  static constexpr size_type noOfRows = M;
  static constexpr size_type noOfCols = N;
  static constexpr size_type size = M * N;

  constexpr mat() noexcept = default;
  constexpr mat(const mat&) noexcept = default;
  constexpr mat& operator=(const mat&) noexcept = default;
  constexpr mat(mat&&) noexcept = default;
  constexpr mat& operator=(mat&&) noexcept = default;
  ~mat() noexcept = default;

  constexpr explicit mat(value_type value) noexcept
  {
    for (size_type i = 0; i < size; ++i)
    {
      m_data[i] = value;
    }
  }

  constexpr iterator data() noexcept { return m_data; }
  constexpr const_iterator data() const noexcept { return m_data; }

  /** @brief Accesses the element at the specified index.
   *
   * The elements of the matrix are stored in row-major order of a one-dimensional array.
   * This operator allows for accessing the one-dimensional array directly.
   *
   * @param i The row index.
   * @param j The column index.
   * @return The element at the specified index.
   */
  [[nodiscard]] constexpr reference operator[](size_type i) noexcept { return m_data[i]; }
  /** /overload */
  [[nodiscard]] LINAL_CONST constexpr value_type operator[](size_type i) const noexcept { return m_data[i]; }

  static LINAL_CONST constexpr mat diagonal(T value) noexcept
  {
    mat result;
    linal::diagonal(result, value);
    return result;
  }
  static LINAL_CONST constexpr mat identity() noexcept { return mat::diagonal(value_type{1}); }
  static LINAL_CONST constexpr mat from_rows(std::initializer_list<vec<value_type, noOfRows>> rows) noexcept
  {
    mat result;
    linal::from_rows(result, rows);
    return result;
  }
  static LINAL_CONST constexpr mat from_columns(std::initializer_list<vec<value_type, noOfCols>> columns) noexcept
  {
    mat result;
    linal::from_columns(result, columns);
    return result;
  }

  /** @brief Gets a row from the matrix.
   *
   * Creates and returns vector of the elements in the specified row.
   *
   * @param i The index of the row.
   * @return The row.
   */
  [[nodiscard]] LINAL_CONST constexpr vec<value_type, N> get_row(size_type i) const noexcept
  {
    assert(i < M && "Index out of range.");
    vec<value_type, N> result;
    auto& mat = *this;
    for (size_type j = 0; j < N; ++j)
    {
      result[j] = m_data[i * N + j];
    }
    return result;
  }

  /** @brief Gets a column from the matrix.
   *
   * Creates and returns vector of the elements in the specified column.
   *
   * @param j The index of the column.
   * @return The column.
   */
  [[nodiscard]] LINAL_CONST constexpr vec<value_type, M> get_column(size_type j) const noexcept
  {
    assert(j < N && "Index out of range.");
    vec<value_type, M> result;
    for (size_type i = 0; i < M; ++i)
    {
      result[i] = m_data[i * N + j];
    }
    return result;
  }

  /** @brief Transposes the matrix.
   *
   * The transpose of a matrix is a new matrix whose rows are the columns of the original.
   *
   * @return The transposed matrix.
   */
  [[nodiscard]] constexpr mat<T, N, M> transpose() const noexcept { return linal::transpose(*this); }

  /** @brief Checks if the matrix is the identity matrix.
   *
   * The identity matrix is a square matrix with ones on the main diagonal and zeros elsewhere.
   *
   * @return True if the matrix is the identity matrix, false otherwise.
   */
  [[nodiscard]] constexpr bool is_identity() const noexcept { return linal::is_identity(*this); }

  /** @brief Checks if the matrix is symmetric.
   *
   * A matrix is symmetric if it is equal to its transpose.
   *
   * @return True if the matrix is symmetric, false otherwise.
   */
  [[nodiscard]] constexpr bool is_symmetric() const noexcept { return linal::is_symmetric(*this); }

  /** @brief Checks if the matrix is orthogonal.
   *
   * A matrix is orthogonal if its transpose is equal to its inverse.
   * The inverse of a matrix is the matrix that, when multiplied with the original matrix, gives the identity matrix.
   *
   * @return True if the matrix is orthogonal, false otherwise.
   */
  [[nodiscard]] constexpr bool is_orthogonal() const noexcept { return linal::is_orthogonal(*this); }

  /** @brief Multiplies the matrix with another matrix.
   *
   * The matrix must have the same number of rows as the other matrix has columns.
   *
   * @param rhs The matrix to multiply with.
   * @return The resulting matrix.
   */
  template <typename TRhs, typename = std::enable_if_t<std::is_same_v<typename TRhs::value_type, mat::value_type>>>
  constexpr auto operator*(const TRhs& rhs) const noexcept
  {
    using TResult = mat<value_type, mat::noOfRows, TRhs::noOfCols>;
    return linal::matrix_multiply<mat, TRhs, TResult>(*this, rhs);
  }

  /** @brief Multiplies the matrix with a vector.
   *
   * The matrix must have the same number of columns as the vector has elements.
   *
   * @param rhs The vector to multiply with.
   * @return The resulting vector.
   */
  constexpr vec<value_type, M> operator*(const vec<value_type, N>& rhs) const noexcept { return linal::matrix_vec_multiply(*this, rhs); }

protected:
  value_type m_data[M * N]{};
};

template <typename T, int M, int N>
[[nodiscard]] constexpr bool is_orthogonal(const mat<T, M, N>& mat) noexcept
{
  static_assert(M == N, "TRhs must be square.");

  using matrix = ::linal::mat<T, N, M>;
  using size_type = typename matrix::size_type;

  const matrix transposed = transpose(mat);

  const matrix product = mat * transposed;
  bool res = product == matrix::identity();
  return res;
}

template <typename LMat, typename RMat, typename TResult>
constexpr TResult matrix_multiply(const LMat& lhs, const RMat& rhs) noexcept
{
  static_assert(RMat::noOfRows == LMat::noOfCols && "TRhs dimensions do not match.");

  using size_type = typename TResult::size_type;

  TResult result;
  for (size_type i = 0; i < LMat::noOfRows; ++i)
  {
    for (size_type j = 0; j < RMat::noOfCols; ++j)
    {
      for (size_type k = 0; k < LMat::noOfCols; ++k)
      {
        result(i, j) += lhs(i, k) * rhs(k, j);
      }
    }
  }
  return result;
}

template <typename TMat, typename TVec>
constexpr TVec matrix_vec_multiply(const TMat& lhs, const TVec& rhs) noexcept
{
  using value_type = typename TMat::value_type;
  using size_type = typename TMat::size_type;
  static_assert(TVec::dim == TMat::noOfCols, "TRhs and vector dimensions do not match.");

  TVec result;
  for (size_type i = 0; i < TMat::noOfRows; ++i)
  {
    for (size_type j = 0; j < TMat::noOfCols; ++j)
    {
      result[i] += lhs(i, j) * rhs[j];
    }
  }
  return result;
}

template <typename T>
using mat22 = mat<T, 2, 2>;

template <typename T>
using mat33 = mat<T, 3, 3>;

using int22 = mat22<int32_t>;
using int33 = mat33<int32_t>;

using uint22 = mat22<uint32_t>;
using uint33 = mat33<uint32_t>;

using long22 = mat22<int64_t>;
using long33 = mat33<int64_t>;

using ulong22 = mat22<uint64_t>;
using ulong33 = mat33<uint64_t>;

using float22 = mat22<float>;
using float33 = mat33<float>;

using double22 = mat22<double>;
using double33 = mat33<double>;

} // namespace linal

#endif // LINAL_BLAZEMATRIXOPERATIONS_H
