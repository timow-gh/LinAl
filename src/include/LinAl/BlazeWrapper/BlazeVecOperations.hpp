#ifndef GLFWTESTAPP_VECTOROPERATIONS_H
#define GLFWTESTAPP_VECTOROPERATIONS_H

#include "BlazeVec.hpp"
#include "Core/Math/Eps.hpp"
#include <cmath>
#include <numeric>

namespace LinAl
{

template <typename T, std::size_t D>
[[nodiscard]] T dot(const Vec<T, D>& lhs, const Vec<T, D>& rhs)
{
    return blaze::dot(lhs, rhs);
}

template <typename T>
[[nodiscard]] Vec3<T> cross(const Vec3<T>& lhs, const Vec3<T>& rhs)
{
    return blaze::cross(lhs, rhs);
}

template <typename T, std::size_t D>
[[nodiscard]] T norm2Squared(const Vec<T, D>& vector)
{
    T sum{0};
    for (const T& value: vector)
        sum += value * value;
    return sum;
}

template <typename T, std::size_t D>
[[nodiscard]] T norm2(const Vec<T, D>& vector)
{
    return blaze::norm(vector);
}

template <typename T, std::size_t D>
[[nodiscard]] Vec<T, D> normalize(const Vec<T, D>& vector)
{
    return Vec<T, D>{blaze::normalize(vector)};
}

template <typename T, std::size_t D>
[[nodiscard]] Vec<T, D> projection(const Vec<T, D>& source,
                                   const Vec<T, D>& target)
{
    return target * (dot(source, target)) / (dot(target, target));
}

template <typename T, std::size_t D>
[[nodiscard]] Vec<T, D> rejection(const Vec<T, D>& source,
                                  const Vec<T, D>& target)
{
    return source - projection(source, target);
}

template <typename T, std::size_t D>
[[nodiscard]] bool collinear(const Vec<T, D>& source,
                                  const Vec<T, D>& target)
{
    return Core::isZero(std::abs(LinAl::dot(source, target)));
}

} // namespace LinAl

#endif // GLFWTESTAPP_VECTOROPERATIONS_H
