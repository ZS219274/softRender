#pragma once

#include "vector.h"

namespace math {

/** Scalar-Vector2 multiplication operator, supports scalar on the left side
 * @param s Scalar value
 * @param v Vector2 vector
 * @return The multiplied Vector2 vector
 */
template <typename T, typename S>
inline Vector2<T> operator*(S s, const Vector2<T>& v) {
  return v * s;
}

/** Scalar-Vector3 multiplication operator, supports scalar on the left side
 * @param s Scalar value
 * @param v Vector3 vector
 * @return The multiplied Vector3 vector
 */
template <typename T, typename S>
inline Vector3<T> operator*(S s, const Vector3<T>& v) {
  return v * s;
}

/** Scalar-Vector4 multiplication operator, supports scalar on the left side
 * @param s Scalar value
 * @param v Vector4 vector
 * @return The multiplied Vector4 vector
 */
template <typename T, typename S>
inline Vector4<T> operator*(S s, const Vector4<T>& v) {
  return v * s;
}

/** Component-wise multiplication operator for two Vector2 vectors
 * @param v0 First Vector2 vector
 * @param v1 Second Vector2 vector
 * @return Component-wise multiplied Vector2 vector
 */
template <typename T>
inline Vector2<T> operator*(const Vector2<T>& v0, const Vector2<T>& v1) {
  return Vector2<T>(v0.x * v1.x, v0.y * v1.y);
}

/** Component-wise multiplication operator for two Vector3 vectors
 * @param v0 First Vector3 vector
 * @param v1 Second Vector3 vector
 * @return Component-wise multiplied Vector3 vector
 */
template <typename T>
inline Vector3<T> operator*(const Vector3<T>& v0, const Vector3<T>& v1) {
  return Vector3<T>(v0.x * v1.x, v0.y * v1.y, v0.z * v1.z);
}

/** Component-wise multiplication operator for two Vector4 vectors
 * @param v0 First Vector4 vector
 * @param v1 Second Vector4 vector
 * @return Component-wise multiplied Vector4 vector
 */
template <typename T>
inline Vector4<T> operator*(const Vector4<T>& v0, const Vector4<T>& v1) {
  return Vector4<T>(v0.x * v1.x, v0.y * v1.y, v0.z * v1.z, v0.w * v1.w);
}

/** Calculate absolute values of Vector2 vector components
 * @param v Input Vector2 vector
 * @return Vector2 vector with absolute values of components
 */
template <typename T>
inline Vector2<T> abs(const Vector2<T>& v) {
  return Vector2<T>(std::abs(v.x), std::abs(v.y));
}

/** Calculate absolute values of Vector3 vector components
 * @param v Input Vector3 vector
 * @return Vector3 vector with absolute values of components
 */
template <typename T>
inline Vector3<T> abs(const Vector3<T>& v) {
  return Vector3<T>(std::abs(v.x), std::abs(v.y), std::abs(v.z));
}

/** Calculate absolute values of Vector4 vector components
 * @param v Input Vector4 vector
 * @return Vector4 vector with absolute values of components
 */
template <typename T>
inline Vector4<T> abs(const Vector4<T>& v) {
  return Vector4<T>(std::abs(v.x), std::abs(v.y), std::abs(v.z), std::abs(v.w));
}

/** Calculate the dot product (inner product) of two Vector2 vectors
 * @param v1 First Vector2 vector
 * @param v2 Second Vector2 vector
 * @return Dot product value of the two vectors
 */
template <typename T>
inline T dot(const Vector2<T>& v1, const Vector2<T>& v2) {
  return v1.x * v2.x + v1.y * v2.y;
}

/** Calculate the dot product (inner product) of two Vector3 vectors
 * @param v1 First Vector3 vector
 * @param v2 Second Vector3 vector
 * @return Dot product value of the two vectors
 */
template <typename T>
inline T dot(const Vector3<T>& v1, const Vector3<T>& v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

/** Calculate the dot product (inner product) of two Vector4 vectors
 * @param v1 First Vector4 vector
 * @param v2 Second Vector4 vector
 * @return Dot product value of the two vectors
 */
template <typename T>
inline T dot(const Vector4<T>& v1, const Vector4<T>& v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

/** Calculate the cross product (outer product) of two Vector2 vectors
 * @param v1 First Vector2 vector
 * @param v2 Second Vector2 vector
 * @return Cross product value (scalar)
 */
template <typename T>
inline T cross(const Vector2<T>& v1, const Vector2<T>& v2) {
  return v1.x * v2.y - v1.y * v2.x;
}

/** Calculate the cross product (outer product) of two Vector3 vectors
 * @param v1 First Vector3 vector
 * @param v2 Second Vector3 vector
 * @return Cross product value (Vector3 vector)
 */
template <typename T>
inline Vector3<T> cross(const Vector3<T>& v1, const Vector3<T>& v2) {
  double v1x = v1.x, v1y = v1.y, v1z = v1.z;
  double v2x = v2.x, v2y = v2.y, v2z = v2.z;

  return Vector3<T>(v1y * v2z - v1z * v2y, v1z * v2x - v1x * v2z,
                    v1x * v2y - v1y * v2x);
}

/** Calculate the squared length of a Vector2 vector
 * @param v Input Vector2 vector
 * @return Squared length value of the vector
 */
template <typename T>
inline float lengthSquared(const Vector2<T>& v) {
  return v.x * v.x + v.y * v.y;
}

/** Calculate the squared length of a Vector3 vector
 * @param v Input Vector3 vector
 * @return Squared length value of the vector
 */
template <typename T>
inline float lengthSquared(const Vector3<T>& v) {
  return v.x * v.x + v.y * v.y + v.z * v.z;
}

/** Calculate the squared length of a Vector4 vector
 * @param v Input Vector4 vector
 * @return Squared length value of the vector
 */
template <typename T>
inline float lengthSquared(const Vector4<T>& v) {
  return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

/** Calculate the length (magnitude) of a Vector2 vector
 * @param v Input Vector2 vector
 * @return Length value of the vector
 */
template <typename T>
inline T length(const Vector2<T>& v) {
  return std::sqrt(lengthSquared(v));
}

/** Calculate the length (magnitude) of a Vector3 vector
 * @param v Input Vector3 vector
 * @return Length value of the vector
 */
template <typename T>
inline T length(const Vector3<T>& v) {
  return std::sqrt(lengthSquared(v));
}

/** Calculate the length (magnitude) of a Vector4 vector
 * @param v Input Vector4 vector
 * @return Length value of the vector
 */
template <typename T>
inline T length(const Vector4<T>& v) {
  return std::sqrt(lengthSquared(v));
}

/** Normalize a Vector2 vector (unit vector)
 * @param v Input Vector2 vector
 * @return Normalized Vector2 unit vector
 */
template <typename T>
inline Vector2<T> normalize(const Vector2<T>& v) {
  return v / length(v);
}

/** Normalize a Vector3 vector (unit vector)
 * @param v Input Vector3 vector
 * @return Normalized Vector3 unit vector
 */
template <typename T>
inline Vector3<T> normalize(const Vector3<T>& v) {
  return v / length(v);
}

/** Normalize a Vector4 vector (unit vector)
 * @param v Input Vector4 vector
 * @return Normalized Vector4 unit vector
 */
template <typename T>
inline Vector4<T> normalize(const Vector4<T>& v) {
  return v / length(v);
}

}  // namespace math