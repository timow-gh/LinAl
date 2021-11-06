#ifndef LINAL_BLAZEMATRIXOPERATIONS_HPP
#define LINAL_BLAZEMATRIXOPERATIONS_HPP

#include "LinAl/BlazeWrapper/BlazeHMatrix.hpp"
#include "blaze/math/Submatrix.h"
#include <iostream>

namespace LinAl
{
template <typename T, std::size_t M, std::size_t N>
void transpose(Matrix<T, M, N>& matrix)
{
    blaze::transpose(matrix);
}

template <typename T, std::size_t M, std::size_t N>
void invert(Matrix<T, M, N>& matrix)
{
    blaze::invert(matrix);
}


//! Input Vectors are not normalized in this function.
//! Make sure the input vectors are normalized if scaling is not desired.
// a: source vector
// b: target vector
template <typename T>
Matrix3<T> rotationAlign(const Vec3<T>& a, const Vec3<T>& b)
{
    // clang-format off
    https://iquilezles.org/www/articles/noacos/noacos.htm
    /*
        v * v^T     (  c,     v.z, -v.y)
    M = -------  +  ( -v.z,   c,    v.x)
         1+c        (  v.y,  -v.x,  c  )
    */
    // clang-format on
    const Vec3<T> v = cross(b, a);
    const float c = dot(b, a);
    const float k = 1.0f / (1.0f + c);

    return Matrix3<T>{
        {v[0] * v[0] * k + c, -v[1] * v[0] * k + v[2], -v[2] * v[0] * k - v[1]},
        {-v[0] * v[1] * k - v[2], v[1] * v[1] * k + c, -v[2] * v[1] * k + v[0]},
        {-v[0] * v[2] * k + v[1],
         -v[1] * v[2] * k - v[0],
         v[2] * v[2] * k + c}};
}
} // namespace LinAl

#endif // LINAL_BLAZEMATRIXOPERATIONS_HPP
