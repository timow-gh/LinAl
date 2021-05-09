#ifndef LINAL_BLAZEUTIL_HPP
#define LINAL_BLAZEUTIL_HPP

namespace LinAl {
template <typename T> auto calcCosSin(T alpha) {
  return std::make_pair(std::cos(alpha), std::sin(alpha));
}
} // namespace LinAl

#endif // LINAL_BLAZEUTIL_HPP
