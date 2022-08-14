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
    typename Vec<T, D>::value_type sum{0};
    for (const auto& value: vector)
        sum += value * value;
    return sum;
}

template <typename T, std::size_t D>
CORE_NODISCARD CORE_CONSTEXPR typename Vec<T, D>::value_type norm2(Vec<T, D> vec)
{
    return blaze::norm(vec);
}

template <typename T>
CORE_NODISCARD CORE_CONSTEXPR T norm2(const HVec<T>& hVec)
{
    return blaze::norm(hVecToVec3(hVec));
}

template <typename T, std::size_t D>
CORE_NODISCARD CORE_CONSTEXPR Vec<T, D> normalize(Vec<T, D> vector)
{
    return Vec<T, D>{blaze::normalize(vector)};
}

template <typename T, std::size_t D>
CORE_NODISCARD CORE_CONSTEXPR Vec<T, D> projection(Vec<T, D> source, Vec<T, D> target)
{
    return target * (dot(source, target)) / (dot(target, target));
}

template <typename T, std::size_t D>
CORE_NODISCARD CORE_CONSTEXPR Vec<T, D> rejection(Vec<T, D> source, Vec<T, D> target)
{
    return source - projection(source, target);
}

template <typename T, std::size_t D>
CORE_NODISCARD CORE_CONSTEXPR bool collinear(Vec<T, D> source, Vec<T, D> target)
{
    return Core::isZero(typename Vec<T, D>::value_type(1) -
                        std::abs(LinAl::dot(LinAl::normalize(source), LinAl::normalize(target))));
}

// clang-format off
struct isNormalized{};
// clang-format on

template <typename T, std::size_t D>
CORE_NODISCARD CORE_CONSTEXPR bool collinear(Vec<T, D> source, Vec<T, D> target, isNormalized)
{
    return Core::isZero(typename Vec<T, D>::value_type(1) - std::abs(LinAl::dot(source, target)));
}

} // namespace LinAl

#endif // GLFWTESTAPP_VECTOROPERATIONS_H
