#ifndef LINAL_HMAT_HPP
#define LINAL_HMAT_HPP

#include "linal/array_type_traits.hpp"
#include "linal/mat.hpp"
#include "linal/mat_rot.hpp"
#include "linal/utils/compiler.hpp"
#include "linal/utils/util.hpp"

namespace linal
{

template <typename T>
using hvec = vec<T, 4>;
using hvecf = hvec<float>;
using hvecd = hvec<double>;

/** @brief A 4x4 matrix class for homogeneous transformations.
 *
 *
 *  @tparam T The type of the elements.
 */
template <typename T>
class hmat
    : public element_access_policy<hmat<T>, array_traits<T, int, 16>>
    , public addition_policy<hmat<T>, array_traits<T, int, 16>>
    , public subtraction_policy<hmat<T>, array_traits<T, int, 16>>
    , public multiplication_policy<hmat<T>, array_traits<T, int, 16>>
    , public division_policy<hmat<T>, array_traits<T, int, 16>>
    , public comparison_policy<hmat<T>, array_traits<T, int, 16>>
    , public unary_policy<hmat<T>, array_traits<T, int, 16>>
{
public:
  using value_type = T;
  using size_type = int;
  using iterator = T*;
  using const_iterator = const T*;
  static constexpr size_type noOfCols = 4;
  static constexpr size_type noOfRows = 4;
  static constexpr size_type size = noOfCols * noOfRows;

  static constexpr hmat identity()
  {
    hmat result;
    linal::diagonal(result, value_type{1});
    return result;
  }

  static LINAL_CONST constexpr hmat from_rows(std::initializer_list<vec<value_type, noOfCols>> rows) noexcept
  {
    hmat result;
    linal::from_rows(result, rows);
    return result;
  }

  static LINAL_CONST constexpr hmat from_columns(std::initializer_list<vec<value_type, noOfRows>> columns) noexcept
  {
    hmat result;
    linal::from_columns(result, columns);
    return result;
  }

  constexpr hmat() = default;

  constexpr hmat(const mat<T, 3, 3>& rotationMatrix)
  {
    set_rotation(rotationMatrix);
    set_translation({0, 0, 0, 1});
  }

  explicit constexpr hmat(const vec3<T>& translation) { set_translation(translation); }

  explicit constexpr hmat(const hvec<T>& translation) { set_translation(translation); }

  constexpr hmat(const mat<T, 3, 3>& rotationMatrix, const vec3<T>& translation)
  {
    set_rotation(rotationMatrix);
    set_translation(translation);
  }

  constexpr iterator data() noexcept { return m_data; }
  constexpr const_iterator data() const noexcept { return m_data; }

  constexpr value_type& operator[](int index) noexcept { return m_data[index]; }
  constexpr const value_type& operator[](int index) const noexcept { return m_data[index]; }

  constexpr hmat operator*(const hmat& rhs) const noexcept { return linal::matrix_multiply<hmat, hmat, hmat>(*this, rhs); }

  constexpr hvec<T> operator*(const hvec<T>& rhs) const noexcept { return linal::matrix_vec_multiply(*this, rhs); }

  constexpr hvec<T> get_translation() const
  {
    auto& matrix = *this;
    return hvec<T>{matrix(0, 3), matrix(1, 3), matrix(2, 3), matrix(3, 3)};
  }

  constexpr void set_translation(const vec3<T>& translation)
  {
    auto& matrix = *this;
    matrix(0, 3) = translation[0];
    matrix(1, 3) = translation[1];
    matrix(2, 3) = translation[2];
    matrix(3, 3) = 1;
  }

  constexpr void set_translation(const hvec<T>& translation)
  {
    auto& matrix = *this;
    matrix(0, 3) = translation[0];
    matrix(1, 3) = translation[1];
    matrix(2, 3) = translation[2];
    matrix(3, 3) = translation[3];
  }

  [[nodiscard]] constexpr mat<T, 3, 3> get_rotation() const
  {
    auto& matrix = *this;
    mat<T, 3, 3> result;
    for (size_type i{0}; i < 3; ++i)
    {
      for (size_type j{0}; j < 3; ++j)
      {
        result(i, j) = matrix(i, j);
      }
    }
    return result;
  }

  constexpr void set_rotation(const mat<T, 3, 3>& rotation)
  {
    auto& matrix = *this;
    for (size_type i{0}; i < 3; ++i)
    {
      for (size_type j{0}; j < 3; ++j)
      {
        matrix(i, j) = rotation(i, j);
      }
    }
  }

  /** @brief Invert the matrix.
   *
   * The inverse of a homogeneous transformation matrix is calculated by
   * transposing the rotation part of the matrix and multiplying the
   * transposed rotation matrix with the negative translation vector.
   *
   * @attention The rotation part of the matrix must be orthogonal.
   *
   * @return Reference this matrix.
   */
  [[nodiscard]] constexpr hmat& inverse()
  {
    hmat& matrix = *this;
    // Transpose the rotation part of the matrix
    for (size_type i{0}; i < 3; ++i)
    {
      for (size_type j{0}; j < 3; ++j)
      {
        std::swap(matrix(i, j), matrix(j, i));
      }
    }

    // The translation par of the inverted matrix is calculated by
    // multiplying the transposed rotation matrix with the negative
    // translation vector.
    mat<T, 3, 3> rot = get_rotation();
    hvec<T> translation = get_translation();
    vec3<T> rotated = -rot * vec3<T>{translation[0], translation[1], translation[2]};
    set_translation(rotated);

    return *this;
  }

  /** @brief Invert the given matrix.
   *
   *  /ref inverse
   *
   * @return The inverted matrix.
   */
  [[nodiscard]] friend constexpr hmat inverse(const hmat& matrix) noexcept
  {
    hmat result = matrix;
    result.inverse();
    return result;
  }

  /** @brief Create a rotation matrix around the x-axis.
   *
   * The rotation matrix is:
   * {1, 0,     0,      0}
   * {0, cos,   -sin,   0}
   * {0, sin,   cos,    0}
   * {0, 0,     0,      1}
   *
   * @param alphaRad The angle in radians.
   * @return The rotation matrix.
   */
  [[nodiscard]] static constexpr hmat<T> rot_x(T alphaRad) noexcept
  {
    hmat<T> result = hmat<T>::identity();
    linal::rot_x(result, alphaRad);
    return result;
  }

  /** @brief Create a rotation matrix around the y-axis.
   *
   * The rotation matrix is:
   * {cos,  0,  sin,  0}
   * {0,    1,  0,    0}
   * {-sin, 0,  cos,  0}
   * {0,    0,  0,    1}
   *
   * @param alphaRad The angle in radians.
   * @return The rotation matrix.
   */
  [[nodiscard]] static constexpr hmat<T> rot_y(T alphaRad) noexcept
  {
    hmat<T> result = hmat<T>::identity();
    linal::rot_y(result, alphaRad);
    return result;
  }

  /** @brief Create a rotation matrix around the z-axis.
   *
   * The rotation matrix is:
   * {cos,   -sin,  0,  0}
   * {sin,   cos,   0,  0}
   * {0,     0,     1,  0}
   * {0,     0,     0,  1}
   *
   * @param alphaRad The angle in radians.
   * @return The rotation matrix.
   */
  [[nodiscard]] static constexpr hmat<T> rot_z(T alphaRad) noexcept
  {
    hmat<T> result = hmat<T>::identity();
    linal::rot_z(result, alphaRad);
    return result;
  }

private:
  T m_data[16]{};
};

using hmatf = hmat<float>;
using hmatd = hmat<double>;

constexpr inline hvecf hvecfx = {1.0f, 0.0f, 0.0f, 1.0f};
constexpr inline hvecf hvecfy = {0.0f, 1.0f, 0.0f, 1.0f};
constexpr inline hvecf hvecfz = {0.0f, 0.0f, 1.0f, 1.0f};

constexpr inline hvecd hvecdx = {1.0, 0.0, 0.0, 1.0};
constexpr inline hvecd hvecdy = {0.0, 1.0, 0.0, 1.0};
constexpr inline hvecd hvecdz = {0.0, 0.0, 1.0, 1.0};

/** @brief Create a rotation matrix around an arbitrary axis.
 *
 * @param axis The axis to rotate around.
 * @param alphaRad The angle in radians.
 * @return The rotation matrix.
 */
template <typename T>
constexpr void rot_axis(hmat<T>& matrix, const vec3<T>& axis, T alphaRad) noexcept
{
  linal::double33 rotMatrix = linal::double33::identity();
  linal::rot_axis(rotMatrix, axis, alphaRad);
  matrix = hmat<T>::identity();
  matrix.set_rotation(rotMatrix);
}

template <typename T, typename TVec>
constexpr void rot_align(hmat<T>& result, const TVec& source, const TVec& target) noexcept
{
  static_assert(TVec::dim == 3 || TVec::dim == 4);

  double33 rotMatrix = double33::identity();
  linal::rot_align(rotMatrix, source, target);
  result = hmat<T>::identity();
  result.set_rotation(rotMatrix);
}

/* @brief Create the rotation matrix first and applies the translation to it.
 *
 * @param axis The axis to rotate around.
 * @param alphaRad The angle in radians.
 * @param translation The translation vector.
 * @return The resulting transformation matrix.
 */
template <typename TVec>
[[nodiscard]] constexpr hmat<typename TVec::value_type>
rot_translate(const TVec& axis, typename TVec::value_type alphaRad, const TVec& translation) noexcept
{
  using T = typename TVec::value_type;

  hmat<T> result;
  linal::rot_axis(result, axis, alphaRad);
  result.set_translation(translation);
  return result;
}

} // namespace linal

#endif // LINAL_HMAT_HPP
