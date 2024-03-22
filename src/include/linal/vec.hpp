#ifndef LINAL_EIGENLINEARALGEBRA_H
#define LINAL_EIGENLINEARALGEBRA_H

#include "linal/policies/addition_policy.hpp"
#include "linal/policies/comparison_policy.hpp"
#include "linal/policies/division_policy.hpp"
#include "linal/policies/multiplication_policy.hpp"
#include "linal/policies/subtraction_policy.hpp"
#include "linal/policies/unary_policy.hpp"
#include "linal/utils/compiler.hpp"
#include <cassert>
#include <type_traits>

namespace linal
{

template <typename T, int D>
class vec;

template <typename T>
[[nodiscard]] constexpr vec<T, 3> cross(const vec<T, 3>& lhs, const vec<T, 3>& rhs) noexcept;

template <typename T, int D>
[[nodiscard]] constexpr T dot(const vec<T, D>& lhs, const vec<T, D>& rhs) noexcept;

template <typename T, int D>
[[nodiscard]] constexpr T length(const vec<T, D>& vector) noexcept;

template <typename T, int D>
[[nodiscard]] constexpr T length_squared(const vec<T, D>& vector) noexcept;

template <typename T, int D>
constexpr vec<T, D> normalize(const vec<T, D>& vector) noexcept;

template <typename T, int D>
class vec
    : public addition_policy<vec<T, D>, array_traits<T, decltype(D), D>>
    , public subtraction_policy<vec<T, D>, array_traits<T, decltype(D), D>>
    , public multiplication_policy<vec<T, D>, array_traits<T, decltype(D), D>>
    , public division_policy<vec<T, D>, array_traits<T, decltype(D), D>>
    , public comparison_policy<vec<T, D>, array_traits<T, decltype(D), D>>
    , public unary_policy<vec<T, D>, array_traits<T, decltype(D), D>>
{
public:
  using value_type = T;
  using size_type = int;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;

  static constexpr size_type dim = D;

  constexpr vec() noexcept = default;
  constexpr vec(const vec&) noexcept = default;
  constexpr vec(vec&&) noexcept = default;
  constexpr vec& operator=(const vec&) noexcept = default;
  constexpr vec& operator=(vec&&) noexcept = default;
  ~vec() noexcept = default;

  constexpr explicit vec(value_type value) noexcept
  {
    for (size_type i = 0; i < D; ++i)
    {
      m_data[i] = value;
    }
  }

  template <typename U, typename = std::enable_if<std::is_convertible_v<U, T>>>
  constexpr vec(const vec<U, D>& other) noexcept
  {
    for (size_type i = 0; i < D; ++i)
    {
      m_data[i] = static_cast<T>(other[i]);
    }
  }

  template <typename... Args, typename = std::enable_if_t<sizeof...(Args) == D && std::conjunction_v<std::is_convertible<Args, T>...>>>
  constexpr vec(Args... args) noexcept
      : m_data{static_cast<T>(args)...}
  {
  }

  [[nodiscard]] constexpr iterator data() noexcept { return m_data; }
  [[nodiscard]] constexpr const_iterator data() const noexcept { return m_data; }

  constexpr reference operator[](size_type idx) noexcept
  {
    assert(idx < dim);
    return m_data[idx];
  }

  constexpr const_reference operator[](size_type idx) const noexcept
  {
    assert(idx < dim);
    return m_data[idx];
  }

  iterator begin() noexcept { return m_data; }
  iterator end() noexcept { return m_data + dim; }

  const_iterator begin() const noexcept { return m_data; }
  const_iterator end() const noexcept { return m_data + dim; }

  const_iterator cbegin() const noexcept { return m_data; }
  const_iterator cend() const noexcept { return m_data + dim; }

  /**
   * @brief Cross product of two vectors.
   *
   * @param lhs Left-hand side vector.
   * @param rhs Right-hand side vector.
   * @return Cross product of two vectors.
   */
  [[nodiscard]] LINAL_CONST constexpr vec cross(const vec& rhs) const noexcept
  {
    static_assert(dim == 3, "Cross product is only defined for 3D vectors.");
    return linal::cross(*this, rhs);
  }

  /**
   * @brief Dot product of two vectors.
   *
   * @param lhs Left-hand side vector.
   * @param rhs Right-hand side vector.
   * @return Dot product of two vectors.
   */
  [[nodiscard]] LINAL_CONST constexpr value_type dot(const vec& rhs) const noexcept { return linal::dot(*this, rhs); }

  /**
   * @brief Length of the vector.
   *
   * @return Length of the vector.
   */
  [[nodiscard]] LINAL_CONST constexpr value_type length() const noexcept { return linal::length(*this); }

  /**
   * @brief Squared length of the vector.
   *
   * @return Squared length of the vector.
   */
  [[nodiscard]] LINAL_CONST constexpr value_type length_squared() const noexcept { return linal::length_squared(*this); }

  /**
   * @brief Normalize this vector.
   *
   * @return Normalized vector.
   */
  [[nodiscard]] LINAL_CONST constexpr vec normalize() noexcept { return linal::normalize(*this); }

private:
  value_type m_data[static_cast<std::size_t>(dim)]{};
};

template <typename T>
using vec2 = vec<T, 2>;

template <typename T>
using vec3 = vec<T, 3>;

using int2 = vec2<int32_t>;
using int3 = vec3<int32_t>;

using uint2 = vec2<uint32_t>;
using uint3 = vec3<uint32_t>;

using long2 = vec2<int64_t>;
using long3 = vec3<int64_t>;

using ulong2 = vec2<uint64_t>;
using ulong3 = vec3<uint64_t>;

using float2 = vec2<float>;
using float3 = vec3<float>;

using double2 = vec2<double>;
using double3 = vec3<double>;

// clang-format off
constexpr inline int2     int2X     {1, 0};
constexpr inline int2     int2Y     {0, 1};
constexpr inline int3     int3X     {1, 0, 0};
constexpr inline int3     int3Y     {0, 1, 0};
constexpr inline uint2    uint2X    {1U, 0U};
constexpr inline uint2    uint2Y    {0U, 1U};
constexpr inline uint3    uint3X    {1U, 0U, 0U};
constexpr inline uint3    uint3Y    {0U, 1U, 0U};
constexpr inline long2    long2X    {1L, 0L};
constexpr inline long2    long2Y    {0L, 1L};
constexpr inline long3    long3X    {1L, 0L, 0L};
constexpr inline long3    long3Y    {0L, 1L, 0L};
constexpr inline ulong2   ulong2X   {1UL, 0UL};
constexpr inline ulong2   ulong2Y   {0UL, 1UL};
constexpr inline ulong3   ulong3X   {1UL, 0ul, 0UL};
constexpr inline ulong3   ulong3Y   {0UL, 1UL, 0UL};
constexpr inline double2  double2X  {1.0, 0.0};
constexpr inline double2  double2Y  {0.0, 1.0};
constexpr inline float2   float2X   {1.0f, 0.0f};
constexpr inline float2   float2Y   {0.0f, 1.0f};
constexpr inline double3  double3X  {1.0, 0.0, 0.0};
constexpr inline double3  double3Y  {0.0, 1.0, 0.0};
constexpr inline double3  double3Z  {0.0, 0.0, 1.0};
constexpr inline float3   float3X   {1.0f, 0.0f, 0.0f};
constexpr inline float3   float3Y   {0.0f, 1.0f, 0.0f};
constexpr inline float3   float3Z   {0.0f, 0.0f, 1.0f};
// clang-format on

template <typename T>
[[nodiscard]] constexpr vec3<T> cross(T lhs1, T lhs2, T lhs3, T rhs1, T rhs2, T rhs3) noexcept
{
  // clang-format off
    return vec3<T>{lhs2 * rhs3 - lhs3 * rhs2,
                   lhs3 * rhs1 - lhs1 * rhs3,
                   lhs1 * rhs2 - lhs2 * rhs1};
  // clang-format on
}

template <typename T>
[[nodiscard]] constexpr vec3<T> cross(const vec3<T>& lhs, const vec3<T>& rhs) noexcept
{
  return cross(lhs[0], lhs[1], lhs[2], rhs[0], rhs[1], rhs[2]);
}

template <typename T>
[[nodiscard]] constexpr T dot(T lhs1, T lhs2, T lhs3, T rhs1, T rhs2, T rhs3) noexcept
{
  return lhs1 * rhs1 + lhs2 * rhs2 + lhs3 * rhs3;
}

template <typename T, int D>
[[nodiscard]] LINAL_PURE constexpr T dot(const vec<T, D>& lhs, const vec<T, D>& rhs) noexcept
{
  T result{0};
  for (int i = 0; i < D; ++i)
  {
    result += lhs[i] * rhs[i];
  }
  return result;
}

template <typename T, int D>
[[nodiscard]] constexpr T length(const vec<T, D>& vector) noexcept
{
  return std::sqrt(linal::dot(vector, vector));
}

template <typename T, int D>
[[nodiscard]] constexpr T length_squared(const vec<T, D>& vector) noexcept
{
  return linal::dot(vector, vector);
}

template <typename T, int D>
[[nodiscard]] constexpr vec<T, D> normalize(const vec<T, D>& vector) noexcept
{
  return vector / linal::length(vector);
}

} // namespace linal

#endif // LINAL_EIGENLINEARALGEBRA_H
