#ifndef LINAL_HMAT_TRANSFORMATIONS_HPP
#define LINAL_HMAT_TRANSFORMATIONS_HPP

#include <linal/hmat.hpp>
#include <linal/hmat_rotation.hpp>
#include <linal/hmat_translation.hpp>
#include <linal/vec3.hpp>

namespace linal
{

namespace hcoord
{

/* @brief Create the rotation matrix first and applies the translation to it.
 *
 * @param axis The axis to rotate around.
 * @param alphaRad The angle in radians.
 * @param translation The translation vector.
 * @return The resulting transformation matrix.
 */
template <typename T>
LINAL_NODISCARD constexpr hmat<T> hmat_rot_translate(vec3<T> axis, T alphaRad, vec3<T> translation) noexcept
{
  hmat<T> result = ::linal::hcoord::rot_axis(vec_to_hvec(axis), alphaRad);
  ::linal::hcoord::set_translation(result, translation);
  return result;
}

} // namespace hcoord

} // namespace linal

#endif // LINAL_HMAT_TRANSFORMATIONS_HPP
