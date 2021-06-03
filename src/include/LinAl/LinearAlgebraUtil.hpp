#ifndef GLFWTESTAPP_LINEARALGEBRAUTIL_HPP
#define GLFWTESTAPP_LINEARALGEBRAUTIL_HPP

#include "LinearAlgebra.hpp"
#include <cstddef>

namespace LinAl
{

template <std::size_t D>
Vec<float_t, D> dToF(const Vec<double_t, D>& vec)
{
    return static_cast<Vec<float_t, D>>(vec);
}

template <std::size_t D>
Vec<double_t, D> fToD(Vec<float_t, D>& vec)
{
    return static_cast<Vec<double_t, D>>(vec);
}

} // namespace LinAl

#endif // GLFWTESTAPP_LINEARALGEBRAUTIL_HPP
