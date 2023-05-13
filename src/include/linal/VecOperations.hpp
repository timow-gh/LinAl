#ifndef GLFWTESTAPP_VECTOROPERATIONS_H
#define GLFWTESTAPP_VECTOROPERATIONS_H

#include <cmath>
#include <linal/Vec.hpp>
#include <linal/utils/Assert.hpp>
#include <linal/utils/Compiler.hpp>
#include <linal/utils/Eps.hpp>
#include <numeric>

namespace linal
{

template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR auto norm2Squared(Vec<T, D> vector)
{
  T sum{0};
  for (const auto& value: vector)
    sum += value * value;
  return sum;
}

template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR T norm2(Vec<T, D> vec)
{
  return blaze::norm(vec);
}

template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR auto dot(Vec<T, D> lhs, Vec<T, D> rhs)
{
  return blaze::dot(lhs, rhs);
}

template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR Vec<T, D> cross(Vec<T, D> lhs, Vec<T, D> rhs)
{
  LINAL_ASSERT(norm2(lhs) > T{0.0});
  LINAL_ASSERT(norm2(rhs) > T{0.0});
  return blaze::cross(lhs, rhs);
}

template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR Vec<T, D> normalize(Vec<T, D> vector)
{
  return Vec<T, D>{blaze::normalize(vector)};
}

/** @brief Returns the projection of source onto target.
 *
 * \link [Vector_projection](https://en.wikipedia.org/wiki/Vector_projection) \endlink
 *
 * @tparam T The type of the vector components.
 * @tparam D The dimension of the vectors.
 * @param source The vector to be projected.
 * @param target The vector to be projected onto.
 * @return The projection of source onto target.
 */
template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR Vec<T, D> projection(Vec<T, D> source, Vec<T, D> target)
{
  return target * (dot(source, target)) / (dot(target, target));
}

/** @brief Returns the rejection of source onto target.
 *
 * \link [Vector_projection](https://en.wikipedia.org/wiki/Vector_projection) \endlink
 *
 * @tparam T The type of the vector components.
 * @tparam D The dimension of the vectors.
 * @param source The vector of which the rejection is to be computed.
 * @param target The vector to be projected onto.
 * @return The rejection of source onto target.
 */
template <typename T, std::size_t D>
LINAL_NODISCARD LINAL_CONSTEXPR Vec<T, D> rejection(Vec<T, D> source, Vec<T, D> target)
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
LINAL_NODISCARD LINAL_CONSTEXPR bool collinear(Vec<T, D> source, Vec<T, D> target, T eps = eps_f<T>)
{
  LINAL_ASSERT(normalize(source) == source);
  LINAL_ASSERT(normalize(target) == target);
  return (T{1} - std::abs(linal::dot(source, target))) < eps;
}

} // namespace linal

#endif // GLFWTESTAPP_VECTOROPERATIONS_H
