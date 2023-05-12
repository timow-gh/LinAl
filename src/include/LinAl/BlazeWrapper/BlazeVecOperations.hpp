#ifndef GLFWTESTAPP_VECTOROPERATIONS_H
#define GLFWTESTAPP_VECTOROPERATIONS_H

#include <Core/Math/Eps.hpp>
#include <Core/Utils/Compiler.hpp>
#include <LinAl/BlazeWrapper/BlazeVec.hpp>
#include <cmath>
#include <numeric>

namespace LinAl
{

template <typename T, std::size_t D>
CORE_NODISCARD CORE_CONSTEXPR auto dot(Vec<T, D> lhs, Vec<T, D> rhs)
{
  return blaze::dot(lhs, rhs);
}

template <typename T, std::size_t D>
CORE_NODISCARD CORE_CONSTEXPR Vec<T, D> cross(Vec<T, D> lhs, Vec<T, D> rhs)
{
  return blaze::cross(lhs, rhs);
}

template <typename T, std::size_t D>
CORE_NODISCARD CORE_CONSTEXPR auto norm2Squared(Vec<T, D> vector)
{
  T sum{0};
  for (const auto& value: vector)
    sum += value * value;
  return sum;
}

template <typename T, std::size_t D>
CORE_NODISCARD CORE_CONSTEXPR T norm2(Vec<T, D> vec)
{
  return blaze::norm(vec);
}

template <typename T, std::size_t D>
CORE_NODISCARD CORE_CONSTEXPR Vec<T, D> normalize(Vec<T, D> vector)
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
CORE_NODISCARD CORE_CONSTEXPR Vec<T, D> projection(Vec<T, D> source, Vec<T, D> target)
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
CORE_NODISCARD CORE_CONSTEXPR Vec<T, D> rejection(Vec<T, D> source, Vec<T, D> target)
{
  return source - projection(source, target);
}

// clang-format off
struct isNormalized{};
// clang-format on

template <typename T, std::size_t D>
CORE_NODISCARD CORE_CONSTEXPR bool collinear(Vec<T, D> source, Vec<T, D> target, T eps, isNormalized)
{
  return Core::isZero(T{1} - std::abs(LinAl::dot(source, target)));
}

template <typename T, std::size_t D>
CORE_NODISCARD CORE_CONSTEXPR bool collinear(Vec<T, D> source, Vec<T, D> target, T eps)
{
  return collinear(LinAl::normalize(source), LinAl::normalize(target), eps);
}

} // namespace LinAl

#endif // GLFWTESTAPP_VECTOROPERATIONS_H
