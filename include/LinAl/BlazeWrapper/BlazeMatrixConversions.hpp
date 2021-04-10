#ifndef LINAL_BLAZEMATRIXCONVERSIONS_HPP
#define LINAL_BLAZEMATRIXCONVERSIONS_HPP

namespace LinAl {
template <typename T> Matrix4<T> mat3ToMat4(const Matrix3<T> &matrix) {
  return Matrix4<T>{{matrix(0, 0), matrix(0, 1), matrix(0, 2), 0},
                    {matrix(1, 0), matrix(1, 1), matrix(1, 2), 0},
                    {matrix(2, 0), matrix(2, 1), matrix(2, 2), 0},
                    {0, 0, 0, 1}};
}
} // namespace LinAl

#endif // LINAL_BLAZEMATRIXCONVERSIONS_HPP
