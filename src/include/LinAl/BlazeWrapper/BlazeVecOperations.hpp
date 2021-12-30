#ifndef GLFWTESTAPP_VECTOROPERATIONS_H
#define GLFWTESTAPP_VECTOROPERATIONS_H

#include "BlazeVec.hpp"
#include "Core/Math/Eps.hpp"
#include <cmath>
#include <numeric>

namespace LinAl
{

template <typename T, std::size_t D>
[[nodiscard]] constexpr T dot(const Vec<T, D>& lhs, const Vec<T, D>& rhs)
{
    return blaze::dot(lhs, rhs);
}

template <typename T>
[[nodiscard]] constexpr Vec3<T> cross(const Vec3<T>& lhs, const Vec3<T>& rhs)
{
    return blaze::cross(lhs, rhs);
}

template <typename T, std::size_t D>
[[nodiscard]] constexpr T norm2Squared(const Vec<T, D>& vector)
{
    T sum{0};
    for (const T& value: vector)
        sum += value * value;
    return sum;
}

template <typename T, std::size_t D>
[[nodiscard]] constexpr T norm2(const Vec<T, D>& vector)
{
    return blaze::norm(vector);
}

template <typename T>
[[nodiscard]] constexpr T norm2(const HVec<T>& hVec)
{
    return blaze::norm(hVecToVec3(hVec));
}

template <typename T, std::size_t D>
[[nodiscard]] constexpr Vec<T, D> normalize(const Vec<T, D>& vector)
{
    return Vec<T, D>{blaze::normalize(vector)};
}

template <typename T, std::size_t D>
[[nodiscard]] constexpr Vec<T, D> projection(const Vec<T, D>& source, const Vec<T, D>& target)
{
    return target * (dot(source, target)) / (dot(target, target));
}

template <typename T, std::size_t D>
[[nodiscard]] constexpr Vec<T, D> rejection(const Vec<T, D>& source, const Vec<T, D>& target)
{
    return source - projection(source, target);
}

template <typename T, std::size_t D>
[[nodiscard]] constexpr bool collinear(const Vec<T, D>& source, const Vec<T, D>& target)
{
    return Core::isZero(T(1) -
                        std::abs(LinAl::dot(LinAl::normalize(source), LinAl::normalize(target))));
}

// clang-format off
struct isNormalized{};
// clang-format on

template <typename T, std::size_t D>
[[nodiscard]] constexpr bool
collinear(const Vec<T, D>& source, const Vec<T, D>& target, isNormalized)
{
    return Core::isZero(T(1) - std::abs(LinAl::dot(source, target)));
}

} // namespace LinAl

#endif // GLFWTESTAPP_VECTOROPERATIONS_H
