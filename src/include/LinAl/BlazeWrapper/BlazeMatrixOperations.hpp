#ifndef LINAL_BLAZEMATRIXOPERATIONS_HPP
#define LINAL_BLAZEMATRIXOPERATIONS_HPP

#include "LinAl/BlazeWrapper/BlazeHMatrix.hpp"
#include "blaze/math/Submatrix.h"

#include <iostream>

namespace LinAl {
template <typename T, std::size_t M, std::size_t N>
void invert(Matrix<T, M, N> &matrix) {
  blaze::invert(matrix);
}
} // namespace LinAl

#endif // LINAL_BLAZEMATRIXOPERATIONS_HPP
