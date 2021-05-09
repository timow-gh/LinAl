#ifndef LINAL_BLAZEMATRIXOPERATIONS_HPP
#define LINAL_BLAZEMATRIXOPERATIONS_HPP

namespace LinAl {
template <typename Matrix> void invert(Matrix &matrix) {
  blaze::invert(matrix);
}
} // namespace LinAl

#endif // LINAL_BLAZEMATRIXOPERATIONS_HPP
