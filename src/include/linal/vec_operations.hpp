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

/** @brief Returns the projection of source onto target.
 *
 * \link [vector_projection](https://en.wikipedia.org/wiki/vector_projection) \endlink
 *
 * @param source The vector to be projected.
 * @param target The vector to be projected onto.
 * @return The projection of source onto target.
 */
template <typename TVec>
LINAL_NODISCARD constexpr TVec projection(const TVec& source, const TVec& target) noexcept
{
  return target * (dot(source, target)) / (dot(target, target));
}

/** @brief Returns the rejection of source onto target.
 *
 * \link [vector_projection](https://en.wikipedia.org/wiki/vector_projection) \endlink
 *
 * @param source The vector of which the rejection is to be computed.
 * @param target The vector to be projected onto.
 * @return The rejection of source onto target.
 */
template <typename TVec>
LINAL_NODISCARD constexpr TVec rejection(const TVec& source, const TVec& target) noexcept
{
  return source - projection(source, target);
}

/** @brief Checks if the vectors are collinear.
 *
 * @param source The first vector, must be of length one.
 * @param target The second vector, must be of length one.
 * @return True, if the vectors are collinear.
 */
template <typename TVec>
LINAL_NODISCARD constexpr bool
collinear(const TVec& source, const TVec& target, typename TVec::value_type eps = eps_v<typename TVec::value_type>) noexcept
{
  LINAL_ASSERT(normalize(source) == source);
  LINAL_ASSERT(normalize(target) == target);
  return (typename TVec::value_type{1} - std::abs(dot(source, target))) < eps;
}

} // namespace linal

#endif // LINAL_VECTOROPERATIONS_H
