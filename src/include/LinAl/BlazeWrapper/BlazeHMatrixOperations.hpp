#ifndef LINAL_BLAZEHMATRIXOPERATIONS_HPP
#define LINAL_BLAZEHMATRIXOPERATIONS_HPP

#include "LinAl/BlazeWrapper/BlazeHMatrix.hpp"
#include "LinAl/BlazeWrapper/BlazeUtil.hpp"
#include "blaze/math/Submatrix.h"

namespace LinAl {

template <typename T> HMatrix<T> createIdentityHMatrix() {
  HMatrix<T> result;
  for (std::size_t i{0}; i < 4; ++i)
    result(i, i) = 1.0;
  return result;
}

template <typename T> HMatrix<T> createTranslation(const HVec<T> &vec) {
  HMatrix<T> result = createIdentityHMatrix<T>();
  result(0, 3) = vec[0];
  result(1, 3) = vec[1];
  result(2, 3) = vec[2];
  return result;
}

//! alpha in radians
template <typename T> HMatrix<T> hMatXRot(T alpha) {
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
template <typename T> HMatrix<T> hMatYRot(T alpha) {
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
template <typename T> HMatrix<T> hMatZRot(T alpha) {
  auto [cos, sin] = calcCosSin(alpha);
  // clang-format off
  return HMatrix<T>{
      {cos, -sin, 0, 0},
      {sin, cos,  0, 0},
      {0,   0,    1, 0},
      {0,   0,    0, 1}};
  // clang-format on
}

template <typename T> HMatrix<T> inverse(const HMatrix<T> &matrix) {
  HMatrix<T> result = matrix;

  auto R = blaze::submatrix<0UL, 0UL, 3UL, 3UL>(result);
  blaze::transpose(R);

  auto p = blaze::submatrix<0UL, 3UL, 3UL, 1UL>(result);
  p = -R * p;

  return result;
}

} // namespace LinAl

#endif // LINAL_BLAZEHMATRIXOPERATIONS_HPP
