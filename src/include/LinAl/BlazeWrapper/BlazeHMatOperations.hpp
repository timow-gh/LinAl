#ifndef LINAL_BLAZEHMATOPERATIONS_HPP
#define LINAL_BLAZEHMATOPERATIONS_HPP

#include "LinAl/BlazeWrapper/BlazeHMat.hpp"
#include "LinAl/BlazeWrapper/BlazeMatOperations.hpp"
#include "LinAl/BlazeWrapper/BlazeUtil.hpp"
#include "LinAl/BlazeWrapper/BlazeVecOperations.hpp"
#include "blaze/math/Submatrix.h"

namespace LinAl
{

template <typename T>
HMatrix<T> createIdentityHMatrix()
{
    HMatrix<T> result;
    for (std::size_t i{0}; i < 4; ++i)
        result(i, i) = 1.0;
    return result;
}

template <typename T>
HMatrix<T> createTranslation(const HVec<T>& vec)
{
    HMatrix<T> result = createIdentityHMatrix<T>();
    result(0, 3) = vec[0];
    result(1, 3) = vec[1];
    result(2, 3) = vec[2];
    return result;
}

template <typename T>
HMatrix<T> createTranslation(T x, T y, T z)
{
    HMatrix<T> result = createIdentityHMatrix<T>();
    result(0, 3) = x;
    result(1, 3) = y;
    result(2, 3) = z;
    return result;
}

//! alpha in radians
template <typename T>
HMatrix<T> hMatXRot(T alpha)
{
    auto [cos, sin] = calcCosSin(alpha);
    // clang-format off
  return HMatrix<T>{
      {1, 0,    0,    0},
      {0, cos,  -sin, 0},
      {0, sin,  cos,  0},
      {0, 0,    0,    1}};
    // clang-format on
}

//! alpha in radians
template <typename T>
HMatrix<T> hMatYRot(T alpha)
{
    auto [cos, sin] = calcCosSin(alpha);
    // clang-format off
  return HMatrix<T>{
      {cos,   0,  sin,  0},
      {0,     1,  0,    0},
      {-sin,  0,  cos,  0},
      {0,     0,  0,    1}};
    // clang-format on
}

//! alpha in radians
template <typename T>
HMatrix<T> hMatZRot(T alpha)
{
    auto [cos, sin] = calcCosSin(alpha);
    // clang-format off
  return HMatrix<T>{
      {cos, -sin, 0, 0},
      {sin, cos,  0, 0},
      {0,   0,    1, 0},
      {0,   0,    0, 1}};
    // clang-format on
}

template <typename T>
HMatrix<T> hMatAxisAngleRot(const Vec3<T>& axis, double_t angle)
{
    HMatrix<T> result = createIdentityHMatrix<T>();
    auto R = blaze::submatrix<0UL, 0UL, 3UL, 3UL>(result);
    R = matAxisAngleRot(axis, angle);
    return result;
}

template <typename T>
HMatrix<T> inverse(const HMatrix<T>& matrix)
{
    HMatrix<T> result = matrix;

    auto R = blaze::submatrix<0UL, 0UL, 3UL, 3UL>(result);
    blaze::transpose(R);

    auto p = blaze::submatrix<0UL, 3UL, 3UL, 1UL>(result);
    p = -R * p;

    return result;
}

template <typename T>
void scaleTranslation(HMatrix<T>& matrix,
                      T scaleFactor,
                      T lowerLimit,
                      T upperLimit)
{
    auto translSubMatrix = blaze::submatrix<0UL, 3UL, 3UL, 1UL>(matrix);
    translSubMatrix = translSubMatrix * scaleFactor;

    Vec3<T> lengthVec{matrix(0, 3), matrix(1, 3), matrix(2, 3)};
    T length = LinAl::norm2(lengthVec);
    if (length < lowerLimit)
    {
        lengthVec = LinAl::normalize(lengthVec) * lowerLimit;
    }
    else if (length > upperLimit)
    {
        lengthVec = LinAl::normalize(lengthVec) * upperLimit;
    }
    else
        return;

    matrix(0, 3) = lengthVec[0];
    matrix(1, 3) = lengthVec[1];
    matrix(2, 3) = lengthVec[2];
}

} // namespace LinAl

#endif // LINAL_BLAZEHMATOPERATIONS_HPP
