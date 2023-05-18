#ifndef LINAL_VECTOROPERATIONS_H
#define LINAL_VECTOROPERATIONS_H

#include <cmath>
#include <linal/utils/assert.hpp>
#include <linal/utils/compiler.hpp>
#include <linal/utils/eps.hpp>
#include <linal/vec.hpp>
#include <numeric>

namespace linal
{

template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR auto norm2Squared(vec<T, D> vector)
{
  T sum{0};
  for (const auto& value: vector)
    sum += value * value;
  return sum;
}

template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR T norm2(vec<T, D> vec)
{
  return blaze::norm(vec);
}

template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR auto dot(vec<T, D> lhs, vec<T, D> rhs)
{
  return blaze::dot(lhs, rhs);
}

template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR vec<T, D> cross(vec<T, D> lhs, vec<T, D> rhs)
{
  return blaze::cross(lhs, rhs);
}

template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR vec<T, D> normalize(vec<T, D> vector)
{
  return vec<T, D>{blaze::normalize(vector)};
}

/** @brief Returns the projection of source onto target.
 *
 * \link [vector_projection](https://en.wikipedia.org/wiki/vector_projection) \endlink
 *
 * @tparam T The type of the vector components.
 * @tparam D The dimension of the vectors.
 * @param source The vector to be projected.
 * @param target The vector to be projected onto.
 * @return The projection of source onto target.
 */
template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR vec<T, D> projection(vec<T, D> source, vec<T, D> target)
{
  return target * (dot(source, target)) / (dot(target, target));
}

/** @brief Returns the rejection of source onto target.
 *
 * \link [vector_projection](https://en.wikipedia.org/wiki/vector_projection) \endlink
 *
 * @tparam T The type of the vector components.
 * @tparam D The dimension of the vectors.
 * @param source The vector of which the rejection is to be computed.
 * @param target The vector to be projected onto.
 * @return The rejection of source onto target.
 */
template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR vec<T, D> rejection(vec<T, D> source, vec<T, D> target)
{
  return source - projection(source, target);
}

/** @brief Checks if the vectors are collinear.
 *
 * @tparam T The type of the vector components.
 * @tparam D The dimension of the vectors.
 * @param source The first vector, must be of length one.
 * @param target The second vector, must be of length one.
 * @return True, if the vectors are collinear.
 */
template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR bool collinear(vec<T, D> source, vec<T, D> target, T eps = eps_v<T>)
{
  LINAL_ASSERT(normalize(source) == source);
  LINAL_ASSERT(normalize(target) == target);
  return (T{1} - std::abs(linal::dot(source, target))) < eps;
}

} // namespace linal

#endif // LINAL_VECTOROPERATIONS_H
