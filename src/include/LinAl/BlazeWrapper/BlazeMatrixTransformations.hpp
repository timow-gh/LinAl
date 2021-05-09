#ifndef LINAL_BLAZEMATRIXTRANSFORMATIONS_HPP
#define LINAL_BLAZEMATRIXTRANSFORMATIONS_HPP

#include "BlazeUtil.hpp"

namespace LinAl {
template <typename T> Matrix4<T> mat4XRot(T alpha) {
  auto [cos, sin] = calcCosSin(alpha);
  return Matrix4<T>{
      {1, 0, 0, 0}, {0, cos, -sin, 0}, {0, sin, cos, 0}, {0, 0, 0, 1}};
}
template <typename T> Matrix4<T> mat4YRot(T alpha) {
  auto [cos, sin] = calcCosSin(alpha);
  return Matrix4<T>{
      {cos, 0, -sin, 0}, {0, 1, 0, 0}, {sin, 0, cos, 0}, {0, 0, 0, 1}};
}
template <typename T> Matrix4<T> mat4ZRot(T alpha) {
  auto [cos, sin] = calcCosSin(alpha);
  return Matrix4<T>{
      {cos, -sin, 0, 0}, {sin, cos, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
}
template <typename T> Matrix3<T> mat3XRot(T alpha) {
  auto [cos, sin] = calcCosSin(alpha);
  return Matrix3<T>{{1, 0, 0}, {0, cos, -sin}, {0, sin, cos}};
}
template <typename T> Matrix3<T> mat3YRot(T alpha) {
  auto [cos, sin] = calcCosSin(alpha);
  return Matrix3<T>{{cos, 0, -sin}, {0, 1, 0}, {sin, 0, cos}};
}
template <typename T> Matrix3<T> mat3ZRot(T alpha) {
  auto [cos, sin] = calcCosSin(alpha);
  return Matrix3<T>{{cos, -sin, 0}, {sin, cos, 0}, {0, 0, 1}};
}
template <typename T>
Matrix3<T> createLcsTransformation(const Vec3<T> &lcsX, const Vec3<T> &lcsY,
                                   const Vec3<T> &lcsZ) {
  return Matrix3<T>{{lcsX[0], lcsY[0], lcsZ[0]},
                    {lcsX[1], lcsY[1], lcsZ[1]},
                    {lcsX[2], lcsY[2], lcsZ[2]}};
}
template <typename T, std::size_t N>
Matrix3<T> createLcsTransformation(const Vec3Array<T, N> &lcsVectors) {
  return createLcsTransformation(lcsVectors[0], lcsVectors[1], lcsVectors[2]);
}
} // namespace LinAl

#endif // LINAL_BLAZEMATRIXTRANSFORMATIONS_HPP
