#ifndef LINAL_QUAT_HPP
#define LINAL_QUAT_HPP

#include "linal/utils/assert.hpp"
#include "linal/vec.hpp"

namespace linal
{

/** \brief Unit quaternion to represent rotations in 3D space */
template <typename TFloat>
class quaternion
{
public:
  using value_type = TFloat;
  using vec_type = linal::vec<value_type, 3>;
  using size_type = typename vec_type::size_type;
  using iterator = value_type*;
  using const_iterator = const value_type*;

private:
  // Components of the quaternion
  value_type m_w{0.0};
  vec_type m_vec{0.0, 0.0, 0.0};

public:
  /** \brief Creates a quaternion from axis-angle representation.
   *
   * \param x The x component of the axis.
   * \param y The y component of the axis.
   * \param z The z component of the axis.
   * \param angle The angle of rotation (in radians).
   */
  static constexpr quaternion create(value_type x, value_type y, value_type z, value_type angle) noexcept
  {
    quaternion quat;
    value_type angleHalf = angle / 2;
    quat.m_w = std::cos(angleHalf);
    value_type sinHalfAngle = std::sin(angleHalf);
    quat.m_vec = {x * sinHalfAngle, y * sinHalfAngle, z * sinHalfAngle};
    quat.normalize();
    return quat;
  }

  /** \brief Creates a quaternion from vector components (no rotation, since w=0).
   *
   * \note Useful to represent pure vectors as quaternions for the rotation calculation.
   *
   * \param x The x component of the vector part.
   * \param y The y component of the vector part.
   * \param z The z component of the vector part.
   */
  static constexpr quaternion create(value_type x, value_type y, value_type z) noexcept
  {
    quaternion quat;
    quat.m_w = 0.0;
    quat.m_vec = {x, y, z};
    quat.normalize();
    return quat;
  }

  quaternion() noexcept = default;

  /** \brief Constructs a quaternion from its components.
   *
   * \attention Assumes components to represent a normalized quaternion.
   *
   * \param w The scalar part of the quaternion.
   * \param x The x component of the vector part.
   * \param y The y component of the vector part.
   * \param z The z component of the vector part.
   */
  quaternion(value_type w, value_type x, value_type y, value_type z) noexcept
      : m_w(w)
      , m_vec(x, y, z)
  {
    LINAL_ASSERT(is_normalized());
  }

  /** \brief Constructs a quaternion from vector components (no rotation, since w=0).
   *
   * \note Useful to represent pure vectors as quaternions for the rotation calculation.
   *
   * \attention Assumes the vector to be normalized.
   *
   * \param x The x component of the vector part.
   * \param y The y component of the vector part.
   * \param z The z component of the vector part.
   */
  quaternion(value_type x, value_type y, value_type z) noexcept
      : m_w(0.0)
      , m_vec(x, y, z)
  {
    LINAL_ASSERT(is_normalized());
  }

  [[nodiscard]] constexpr value_type x() const noexcept { return m_vec[0]; }
  [[nodiscard]] constexpr value_type y() const noexcept { return m_vec[1]; }
  [[nodiscard]] constexpr value_type z() const noexcept { return m_vec[2]; }
  [[nodiscard]] constexpr value_type w() const noexcept { return m_w; }

  /** \brief Multiplies two quaternions.
   *
   * \note Quaternion multiplication: q1 * q2 = (w1*w2 - v1·v2, w1*v2 + w2*v1 + v1×v2)
   *
   * \param lhs The left-hand side quaternion.
   * \param rhs The right-hand side quaternion.
   * \return The result of the multiplication.
   */
  friend constexpr quaternion operator*(const quaternion& lhs, const quaternion& rhs) noexcept
  {
    LINAL_ASSERT(lhs.is_normalized());
    LINAL_ASSERT(rhs.is_normalized());

    quaternion result;
    result.m_w = lhs.m_w * rhs.m_w - lhs.m_vec.dot(rhs.m_vec);
    result.m_vec = lhs.m_w * rhs.m_vec + rhs.m_w * lhs.m_vec + lhs.m_vec.cross(rhs.m_vec);
    return result;
  }

  /** \brief Returns the length (magnitude) of the quaternion.
   *
   * \note Definition: |q| = sqrt(w^2 + x^2 + y^2 + z^2)
   *
   * \return The length of the quaternion.
   */
  [[nodiscard]] constexpr value_type length() const noexcept
  {
    value_type len = m_w * m_w;
    for (size_type i = 0; i < 3; ++i)
    {
      len += m_vec[i] * m_vec[i];
    }
    return std::sqrt(len);
  }

  /** \brief Normalizes the quaternion. */
  constexpr void normalize() noexcept
  {
    value_type len = length();
    if (len > value_type(0))
    {
      m_w /= len;
      m_vec /= len;
    }
  }

  constexpr bool is_normalized() const noexcept
  {
    value_type len = length();
    return ::linal::isEq(len, value_type(1));
  }

  /** \brief Computes the dot product of two quaternions. */
  constexpr value_type dot(const quaternion& other) const noexcept
  {
    value_type result = value_type(0);
    result += m_w * other.m_w;
    for (size_type i = 0; i < 3; ++i)
    {
      result += m_vec[i] * other.m_vec[i];
    }
    return result;
  }

  /** \brief Computes the conjugate of the quaternion.
   *
   * \note q* = (w, -x, -y, -z)
   *
   * \return The conjugate of the quaternion.
   */
  constexpr quaternion conjugate() const noexcept
  {
    LINAL_ASSERT(is_normalized());

    quaternion conj;
    conj.m_w = m_w;
    conj.m_vec = -m_vec;
    return conj;
  }

  /** \brief Computes the angle between two quaternions.
   *
   * \param other The other quaternion.
   * \return The angle in radians.
   */
  [[nodiscard]] constexpr double angle(const quaternion& other) const noexcept
  {
    LINAL_ASSERT(is_normalized());
    LINAL_ASSERT(other.is_normalized());

    quaternion delta = this->conjugate() * other;
    return 2.0 * std::atan2(delta.m_vec.length(), delta.m_w);
  }

  /** \brief Rotates a 3D vector using this quaternion.
   *
   * \note textbook definition: v' = q * v * q^-1
   *
   * \param x The x component of the vector to rotate.
   * \param y The y component of the vector to rotate.
   * \param z The z component of the vector to rotate.
   * \return The rotated vector as a linal::vec<value_type, 3>.
   */
  [[nodiscard]] constexpr linal::vec<value_type, 3> rotate(value_type x, value_type y, value_type z) const noexcept
  {
    LINAL_ASSERT(is_normalized());

    quaternion vecQuat = quaternion::create(x, y, z);

    quaternion conjQuat = conjugate();
    quaternion resultQuat = (*this * vecQuat) * conjQuat;
    LINAL_ASSERT(resultQuat.is_normalized());
    return linal::vec<value_type, 3>{resultQuat.x(), resultQuat.y(), resultQuat.z()};
  }
  // \overload for linal::vec
  [[nodiscard]] constexpr linal::vec<value_type, 3> rotate(const linal::vec<value_type, 3>& vec) const noexcept
  {
    return rotate(vec[0], vec[1], vec[2]);
  }

  /** \brief Rotates a sequence of vectors given as components in the range [begin, end).
   *
   * Example:
   * std::array<double, 6> points = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0}; // Two points (1,0,0) and (0,1,0)
   * quaternion quat = quaternion::create(0.0, 0.0, 1.0, linal::PI_HALF_D); // 90 degree rotation around Z axis
   * quat.rotate(points.begin(), points.end());
   *
   * \param begin Iterator to the beginning of the range of vector components.
   * \param end Iterator to the end of the range of vector components.
   * \pre The range [begin, end) must contain a multiple of 3 elements.
   */
  template <typename TIter>
  constexpr void rotate(TIter begin, TIter end) const noexcept
  {
    LINAL_ASSERT(is_normalized());
    LINAL_ASSERT(std::distance(begin, end) % 3 == 0);

    for (auto it = begin; it != end; it += 3)
    {
      linal::vec<value_type, 3> vec = this->rotate(*it, *(it + 1), *(it + 2));
      *it = vec[0];
      *(it + 1) = vec[1];
      *(it + 2) = vec[2];
    }
  }

  /** \brief Rotates a sequence of vectors given as components in the range [begin, end).
   *
   * Example:
   * std::array<double, 6> points = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0}; // Two points (1,0,0) and (0,1,0)
   * quaternion quat = quaternion::create(0.0, 0.0, 1.0, linal::PI_HALF_D); // 90 degree rotation around Z axis
   * quat.rotate(points.begin(), points.end());
   *
   * \param begin Iterator to the beginning of the range of vector components.
   * \param end Iterator to the end of the range of vector components.
   * \param out Output iterator to write the rotated vector components.
   * \pre The range [begin, end) must contain a multiple of 3 elements.
   */
  template <typename TIter, typename TOutIter>
  constexpr void rotate(TIter begin, TIter end, TOutIter out) const noexcept
  {
    LINAL_ASSERT(is_normalized());
    LINAL_ASSERT(std::distance(begin, end) % 3 == 0);

    for (auto it = begin; it != end; it += 3, out += 3)
    {
      linal::vec<value_type, 3> vec = this->rotate(*it, *(it + 1), *(it + 2));
      *out = vec[0];
      *(out + 1) = vec[1];
      *(out + 2) = vec[2];
    }
  }

  enum class RotationDirection
  {
    ShortestPath,
    LongestPath
  };

  /** \brief Spherical linear interpolation between two quaternions.
   *
   * \note Interpolates along the shortest path on the 4D unit sphere.
   *
   * \attention Repeatedly interpolating between quaternions using slerp can lead to drift away from unit length. Make sure to renormalize
   * the result if necessary.
   *
   * \param fromQ The starting quaternion (must be normalized).
   * \param toQ The ending quaternion (must be normalized).
   * \param fraction The interpolation factor in [0, 1].
   * \param rotDirection The rotation direction, either shortest or longest path.
   * \param epsilon Threshold to switch to linear interpolation for very close quaternions. This avoids numerical instability.
   * \return The interpolated quaternion.
   */
  [[nodiscard]] static constexpr quaternion slerp(quaternion fromQ,
                                                  quaternion toQ,
                                                  value_type fraction,
                                                  RotationDirection rotDirection = RotationDirection::ShortestPath,
                                                  value_type epsilon = value_type(1e-6)) noexcept
  {
    LINAL_ASSERT(fromQ.is_normalized());
    LINAL_ASSERT(toQ.is_normalized());
    LINAL_ASSERT(fraction >= value_type(0) && fraction <= value_type(1));

    value_type dotProd = calc_dot(fromQ, toQ, rotDirection);

    if (dotProd > (1.0 - epsilon))
    {
      return calc_linear_interpolation(fromQ, toQ, fraction);
    }
    else
    {
      return slerp_internal(dotProd, fromQ, toQ, fraction);
    }
  }

  template <typename TFloatIter, typename TQuatOutIter>
  static constexpr void slerp(quaternion fromQ,
                              quaternion toQ,
                              TFloatIter fractionBegin,
                              TFloatIter fractionEnd,
                              TQuatOutIter outBegin,
                              RotationDirection rotDirection = RotationDirection::ShortestPath,
                              value_type epsilon = value_type(1e-6)) noexcept
  {
    LINAL_ASSERT(fromQ.is_normalized());
    LINAL_ASSERT(toQ.is_normalized());
    LINAL_ASSERT(std::distance(fractionBegin, fractionEnd) > 0);

    value_type dotProd = calc_dot(fromQ, toQ, rotDirection);

    if (dotProd > (value_type(1.0) - epsilon))
    {
      for (auto it = fractionBegin; it != fractionEnd; ++it)
      {
        value_type fraction = *it;
        LINAL_ASSERT(fraction >= value_type(0) && fraction <= value_type(1));
        *outBegin++ = calc_linear_interpolation(fromQ, toQ, fraction);
      }
    }
    else
    {
      for (auto it = fractionBegin; it != fractionEnd; ++it)
      {
        value_type fraction = *it;
        LINAL_ASSERT(fraction >= value_type(0) && fraction <= value_type(1));
        *outBegin++ = slerp_internal(dotProd, fromQ, toQ, fraction);
      }
    }
  }

private:
  // Calculate dot product and adjust to ensure shortest path
  [[nodiscard]] static constexpr value_type calc_dot(const quaternion& fromQ, quaternion& toQ, RotationDirection direction) noexcept
  {
    value_type dotProd = fromQ.dot(toQ);

    // Use shortest path
    if (dotProd < 0.0 && direction == RotationDirection::ShortestPath)
    {
      toQ.m_w = -toQ.m_w;
      toQ.m_vec = -toQ.m_vec;
      dotProd = -dotProd;
    }
    return dotProd;
  }

  // If the quaternions are very close, use linear interpolation
  [[nodiscard]] static constexpr quaternion
  calc_linear_interpolation(const quaternion& fromQ, const quaternion& toQ, value_type fraction) noexcept
  {
    quaternion result;
    result.m_w = (1 - fraction) * fromQ.m_w + fraction * toQ.m_w;
    result.m_vec = (1 - fraction) * fromQ.m_vec + fraction * toQ.m_vec;
    result.normalize();
    return result;
  }

  /**
   * @brief Performs internal spherical linear interpolation (SLERP) between two unit quaternions.
   *
   * The SLERP formula is obtained as follows:
   *
   * 1. For unit quaternions q0 and q1:
   *        dotProd = q0 · q1 = cos(theta)
   *    where theta is the angle between them on the 4D unit sphere.
   *
   * 2. The path on the unit sphere can be parameterized as:
   *        q(t) = q0 * cos(t * theta) + v * sin(t * theta)
   *    where v is the unit vector orthogonal to q0 in the plane spanned by q0 and q1.
   *
   * 3. Express v in terms of q0 and q1:
   *        v = (q1 - q0 * cos(theta)) / sin(theta)
   *
   *    Substituting back gives:
   *        q(t) = (sin((1 - t) * theta) / sin(theta)) * q0
   *              + (sin(t * theta) / sin(theta)) * q1
   *
   * The resulting interpolation weights are:
   *        weightA = sin((1 - fraction) * theta) / sin(theta)
   *        weightB = sin(fraction * theta) / sin(theta)
   *
   * The interpolated quaternion is then:
   *        result = weightA * fromQ + weightB * toQ
   *
   * @param dotProd    Dot product between fromQ and toQ.
   * @param fromQ      Starting quaternion (must be normalized).
   * @param toQ        Target quaternion (must be normalized).
   * @param fraction   Interpolation parameter in [0, 1].
   * @return Interpolated quaternion on the unit sphere.
   */
  [[nodiscard]] static constexpr quaternion
  slerp_internal(const value_type dotProd, const quaternion& fromQ, const quaternion& toQ, value_type fraction) noexcept
  {
    LINAL_ASSERT(fromQ.is_normalized());
    LINAL_ASSERT(toQ.is_normalized());

    value_type sinAngle = std::sqrt(value_type(1) - dotProd * dotProd);
    value_type angle = std::atan2(sinAngle, dotProd);
    value_type weightA = std::sin((value_type(1) - fraction) * angle) / sinAngle;
    value_type weightB = std::sin(fraction * angle) / sinAngle;

    quaternion result;
    result.m_w = weightA * fromQ.m_w + weightB * toQ.m_w;
    result.m_vec = weightA * fromQ.m_vec + weightB * toQ.m_vec;

    return result;
  }
};

using quatf = quaternion<float>;
using quatd = quaternion<double>;

} // namespace linal

#endif // LINAL_QUAT_HPP