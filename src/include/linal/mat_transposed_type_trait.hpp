#ifndef LINAL_MAT_TRANSPOSED_TYPE_TRAIT_HPP
#define LINAL_MAT_TRANSPOSED_TYPE_TRAIT_HPP

namespace linal
{

template <typename TMat, typename T, int M, int N>
struct mat_transpose_traits;

template <typename T, int M, int N>
class mat;

template <typename T, int M, int N>
struct mat_transpose_traits<mat<T, M, N>, T, M, N>
{
  using transpose_matrix_type = mat<T, N, M>;
};

template <typename T>
class hmat;

template <typename T, int M, int N>
struct mat_transpose_traits<hmat<T>, T, M, N>
{
  using transpose_matrix_type = hmat<T>;
};

template<typename TMat>
using transpose_matrix_type_t = typename mat_transpose_traits<TMat, typename TMat::value_type, TMat::noOfRows, TMat::noOfCols>::transpose_matrix_type;

} // namespace linal

#endif // LINAL_MAT_TRANSPOSED_TYPE_TRAIT_HPP
