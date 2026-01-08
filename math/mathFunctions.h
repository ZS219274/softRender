#pragma once

#include <cmath>

#include "matrix.h"
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

// matrix
/**
 * @brief Computes the transpose of a 3x3 matrix
 * @tparam T Data type of matrix elements
 * @param m Input 3x3 matrix
 * @return Transposed 3x3 matrix
 */
/*
 * m0 m3 m6
 * m1 m4 m7
 * m2 m5 m8
 */
template <typename T>
Matrix33<T> transpose(const Matrix33<T>& m) {
  Matrix33<T> result;
  auto dst = result.m;
  auto src = m.m;
  dst[0] = src[0];
  dst[3] = src[1];
  dst[6] = src[2];
  dst[1] = src[3];
  dst[4] = src[4];
  dst[7] = src[5];
  dst[2] = src[6];
  dst[5] = src[7];
  dst[8] = src[8];

  return result;
}

/**
 * @brief Computes the transpose of a 4x4 matrix
 * @tparam T Data type of matrix elements
 * @param m Input 4x4 matrix
 * @return Transposed 4x4 matrix
 */
/*
 * m0 m4 m8	m12
 * m1 m5 m9	m13
 * m2 m6 m10 m14
 * m3 m7 m11	m15
 */
template <typename T>
Matrix44<T> transpose(const Matrix44<T>& m) {
  Matrix44<T> result;
  auto dst = result.m;
  auto src = m.m;

  dst[0] = src[0];
  dst[4] = src[1];
  dst[8] = src[2];
  dst[12] = src[3];
  dst[1] = src[4];
  dst[5] = src[5];
  dst[9] = src[6];
  dst[13] = src[7];
  dst[2] = src[8];
  dst[6] = src[9];
  dst[10] = src[10];
  dst[14] = src[11];
  dst[3] = src[12];
  dst[7] = src[13];
  dst[11] = src[14];
  dst[15] = src[15];

  return result;
}

/**
 * @brief Overloads the multiplication operator for 3x3 matrices
 * @tparam T Data type of matrix elements
 * @param m1 Left operand matrix
 * @param m2 Right operand matrix
 * @return Product of two matrices
 */
template <typename T>
Matrix33<T> operator*(const Matrix33<T>& m1, const Matrix33<T>& m2) {
  auto m1Col0 = m1.getColum(0);
  auto m1Col1 = m1.getColum(1);
  auto m1Col2 = m1.getColum(2);

  auto m2Col0 = m2.getColum(0);
  auto m2Col1 = m2.getColum(1);
  auto m2Col2 = m2.getColum(2);

  Vector3<T> rCol0, rCol1, rCol2;
  rCol0 = m1Col0 * m2Col0[0] + m1Col1 * m2Col0[1] + m1Col2 * m2Col0[2];
  rCol1 = m1Col0 * m2Col1[0] + m1Col1 * m2Col1[1] + m1Col2 * m2Col1[2];
  rCol2 = m1Col0 * m2Col2[0] + m1Col1 * m2Col2[1] + m1Col2 * m2Col2[2];

  Matrix33<T> result;
  result.setColum(rCol0, 0);
  result.setColum(rCol1, 1);
  result.setColum(rCol2, 2);

  return result;
}

/**
 * @brief Overloads the multiplication operator for 4x4 matrices
 * @tparam T Data type of matrix elements
 * @param m1 Left operand matrix
 * @param m2 Right operand matrix
 * @return Product of two matrices
 */
template <typename T>
Matrix44<T> operator*(const Matrix44<T>& m1, const Matrix44<T>& m2) {
  auto m1Col0 = m1.getColum(0);
  auto m1Col1 = m1.getColum(1);
  auto m1Col2 = m1.getColum(2);
  auto m1Col3 = m1.getColum(3);

  auto m2Col0 = m2.getColum(0);
  auto m2Col1 = m2.getColum(1);
  auto m2Col2 = m2.getColum(2);
  auto m2Col3 = m2.getColum(3);

  Vector4<T> rCol0, rCol1, rCol2, rCol3;
  rCol0 = m1Col0 * m2Col0[0] + m1Col1 * m2Col0[1] + m1Col2 * m2Col0[2] +
          m1Col3 * m2Col0[3];
  rCol1 = m1Col0 * m2Col1[0] + m1Col1 * m2Col1[1] + m1Col2 * m2Col1[2] +
          m1Col3 * m2Col1[3];
  rCol2 = m1Col0 * m2Col2[0] + m1Col1 * m2Col2[1] + m1Col2 * m2Col2[2] +
          m1Col3 * m2Col2[3];
  rCol3 = m1Col0 * m2Col3[0] + m1Col1 * m2Col3[1] + m1Col2 * m2Col3[2] +
          m1Col3 * m2Col3[3];

  Matrix44<T> result;
  result.setColum(rCol0, 0);
  result.setColum(rCol1, 1);
  result.setColum(rCol2, 2);
  result.setColum(rCol3, 3);

  return result;
}

/**
 * @brief Computes the inverse of a 4x4 matrix
 * @tparam T Data type of matrix elements
 * @param src Input 4x4 matrix
 * @return Inverse matrix
 */
/*
 * m0 m4 m8	m12
 * m1 m5 m9	m13
 * m2 m6 m10 m14
 * m3 m7 m11	m15
 */
template <typename T>
Matrix44<T> inverse(const Matrix44<T>& src) {
  Matrix44<T> result(static_cast<T>(1));

  T D_22_33 = src.get(2, 2) * src.get(3, 3) - src.get(2, 3) * src.get(3, 2);

  T D_12_23 = src.get(1, 2) * src.get(2, 3) - src.get(1, 3) * src.get(2, 2);
  T D_12_33 = src.get(1, 2) * src.get(3, 3) - src.get(1, 3) * src.get(3, 2);

  T D_21_32 = src.get(2, 1) * src.get(3, 2) - src.get(2, 2) * src.get(3, 1);
  T D_21_33 = src.get(2, 1) * src.get(3, 3) - src.get(2, 3) * src.get(3, 1);

  T D_11_22 = src.get(1, 1) * src.get(2, 2) - src.get(1, 2) * src.get(2, 1);
  T D_11_23 = src.get(1, 1) * src.get(2, 3) - src.get(1, 3) * src.get(2, 1);
  T D_11_32 = src.get(1, 1) * src.get(3, 2) - src.get(1, 2) * src.get(3, 1);
  T D_11_33 = src.get(1, 1) * src.get(3, 3) - src.get(1, 3) * src.get(3, 1);

  T D_02_13 = src.get(0, 2) * src.get(1, 3) - src.get(0, 3) * src.get(1, 2);
  T D_02_23 = src.get(0, 2) * src.get(2, 3) - src.get(0, 3) * src.get(2, 2);
  T D_02_33 = src.get(0, 2) * src.get(3, 3) - src.get(0, 3) * src.get(3, 2);

  T D_01_12 = src.get(0, 1) * src.get(1, 2) - src.get(0, 2) * src.get(1, 1);
  T D_01_13 = src.get(0, 1) * src.get(1, 3) - src.get(0, 3) * src.get(1, 1);
  T D_01_22 = src.get(0, 1) * src.get(2, 2) - src.get(0, 2) * src.get(2, 1);
  T D_01_23 = src.get(0, 1) * src.get(2, 3) - src.get(0, 3) * src.get(2, 1);
  T D_01_32 = src.get(0, 1) * src.get(3, 2) - src.get(0, 2) * src.get(3, 1);
  T D_01_33 = src.get(0, 1) * src.get(3, 3) - src.get(0, 3) * src.get(3, 1);

  Vector4<T> col0, col1, col2, col3;

  /*
   *
   * m5 m9	 m13
   * m6 m10 m14
   * m7 m11 m15
   */
  col0.x = src.get(1, 1) * D_22_33 - src.get(2, 1) * D_12_33 +
           src.get(3, 1) * D_12_23;
  col0.y = -(src.get(1, 0) * D_22_33 - src.get(2, 0) * D_12_33 +
             src.get(3, 0) * D_12_23);
  col0.z = src.get(1, 0) * D_21_33 - src.get(2, 0) * D_11_33 +
           src.get(3, 0) * D_11_23;
  col0.w = -(src.get(1, 0) * D_21_32 - src.get(2, 0) * D_11_32 +
             src.get(3, 0) * D_11_22);

  col1.x = -(src.get(0, 1) * D_22_33 - src.get(2, 1) * D_02_33 +
             src.get(3, 1) * D_02_23);
  col1.y = src.get(0, 0) * D_22_33 - src.get(2, 0) * D_02_33 +
           src.get(3, 0) * D_02_23;
  col1.z = -(src.get(0, 0) * D_21_33 - src.get(2, 0) * D_01_33 +
             src.get(3, 0) * D_01_23);
  col1.w = src.get(0, 0) * D_21_32 - src.get(2, 0) * D_01_32 +
           src.get(3, 0) * D_01_22;

  col2.x = src.get(0, 1) * D_12_33 - src.get(1, 1) * D_02_33 +
           src.get(3, 1) * D_02_13;
  col2.y = -(src.get(0, 0) * D_12_33 - src.get(1, 0) * D_02_33 +
             src.get(3, 0) * D_02_13);
  col2.z = src.get(0, 0) * D_11_33 - src.get(1, 0) * D_01_33 +
           src.get(3, 0) * D_01_13;
  col2.w = -(src.get(0, 0) * D_11_32 - src.get(1, 0) * D_01_32 +
             src.get(3, 0) * D_01_12);

  col3.x = -(src.get(0, 1) * D_12_23 - src.get(1, 1) * D_02_23 +
             src.get(2, 1) * D_02_13);
  col3.y = src.get(0, 0) * D_12_23 - src.get(1, 0) * D_02_23 +
           src.get(2, 0) * D_02_13;
  col3.z = -(src.get(0, 0) * D_11_23 - src.get(1, 0) * D_01_23 +
             src.get(2, 0) * D_01_13);
  col3.w = src.get(0, 0) * D_11_22 - src.get(1, 0) * D_01_22 +
           src.get(2, 0) * D_01_12;

  result.setColum(col0, 0);
  result.setColum(col1, 1);
  result.setColum(col2, 2);
  result.setColum(col3, 3);

  Vector4<T> row0(result.get(0, 0), result.get(0, 1), result.get(0, 2),
                  result.get(0, 3));
  Vector4<T> colum0 = src.getColum(0);
  T determinant = dot(row0, colum0);

  assert(determinant != 0);

  T oneOverDeterminant = static_cast<T>(1) / determinant;
  return result * oneOverDeterminant;
}

/**
 * @brief Computes the inverse of a 3x3 matrix
 * @tparam T The data type of the matrix elements
 * @param src The input 3x3 matrix to invert
 * @return The inverse of the input matrix
 * @throws assertion if the determinant is zero (matrix is singular)
 *
 * Uses the adjugate method to compute the inverse. First computes the matrix of
 * minors, then applies appropriate signs to get the cofactor matrix, transposes
 * it to get the adjugate matrix, and finally divides by the determinant.
 *
 * Matrix layout:
 * @code
 * m0 m3 m6
 * m1 m4 m7
 * m2 m5 m8
 * @endcode
 *
 * @note The matrix must be non-singular (determinant ≠ 0) for inversion to be
 * possible.
 */
template <typename T>
Matrix33<T> inverse(const Matrix33<T>& src) {
  Matrix33<T> result(static_cast<T>(1));

  // Calculate sub-determinants for cofactors
  T D_11_22 = src.get(1, 1) * src.get(2, 2) - src.get(1, 2) * src.get(2, 1);
  T D_12_23 = src.get(1, 2) * src.get(2, 0) - src.get(1, 0) * src.get(2, 2);
  T D_11_23 = src.get(1, 1) * src.get(2, 0) - src.get(1, 0) * src.get(2, 1);

  T D_01_12 = src.get(0, 1) * src.get(1, 2) - src.get(0, 2) * src.get(1, 1);
  T D_02_13 = src.get(0, 2) * src.get(1, 1) - src.get(0, 1) * src.get(1, 2);
  T D_01_22 = src.get(0, 1) * src.get(2, 2) - src.get(0, 2) * src.get(2, 1);

  T D_01_23 = src.get(0, 1) * src.get(2, 0) - src.get(0, 0) * src.get(2, 1);
  T D_02_23 = src.get(0, 2) * src.get(2, 1) - src.get(0, 1) * src.get(2, 2);
  T D_01_13 = src.get(0, 1) * src.get(1, 0) - src.get(0, 0) * src.get(1, 1);

  Vector3<T> col0, col1, col2;
  /*
   * Calculate the cofactor matrix transposed (adjugate matrix)
   *
   * Original matrix:
   * | 0,0  0,1  0,2 |
   * | 1,0  1,1  1,2 |
   * | 2,0  2,1  2,2 |
   *
   * Adjugate matrix:
   * | A00  A01  A02 |   | +D_11_22  -D_01_22  +D_01_12 |
   * | A10  A11  A12 | = | -D_12_23  +D_02_23  -D_01_13 |
   * | A20  A21  A22 |   | +D_11_23  -D_01_23  +D_01_12 |
   */

  col0.x = D_11_22;   // + (cofactor of element at [0,0])
  col0.y = -D_12_23;  // - (cofactor of element at [0,1])
  col0.z = D_11_23;   // + (cofactor of element at [0,2])

  col1.x = -D_01_22;  // - (cofactor of element at [1,0])
  col1.y = D_02_23;   // + (cofactor of element at [1,1])
  col1.z = -D_01_23;  // - (cofactor of element at [1,2])

  col2.x = D_01_12;   // + (cofactor of element at [2,0])
  col2.y = -D_02_13;  // - (cofactor of element at [2,1])
  col2.z = D_01_13;   // + (cofactor of element at [2,2])

  result.setColum(col0, 0);
  result.setColum(col1, 1);
  result.setColum(col2, 2);

  // Calculate determinant using first row of original matrix and first column
  // of cofactor matrix
  Vector3<T> row0(src.get(0, 0), src.get(0, 1), src.get(0, 2));
  Vector3<T> cofact0 = result.getColum(0);
  T determinant = dot(row0, cofact0);

  assert(determinant != 0);
  T oneOverDeterminant = static_cast<T>(1) / determinant;
  return result * oneOverDeterminant;
}

/**
 * @brief Applies scaling transformation to a 4x4 matrix
 * @tparam T Data type of matrix elements
 * @tparam V Data type of scaling factors
 * @param src Source 4x4 matrix to be scaled
 * @param x Scaling factor along X-axis
 * @param y Scaling factor along Y-axis
 * @param z Scaling factor along Z-axis
 * @return New matrix with scaling transformation applied
 */
template <typename T, typename V>
Matrix44<T> scale(const Matrix44<T>& src, V x, V y, V z) {
  Matrix44<T> result;

  auto col0 = src.getColum(0);
  auto col1 = src.getColum(1);
  auto col2 = src.getColum(2);
  auto col3 = src.getColum(3);

  col0 *= x;
  col1 *= y;
  col2 *= z;

  result.setColum(col0, 0);
  result.setColum(col1, 1);
  result.setColum(col2, 2);
  result.setColum(col3, 3);

  return result;
}

/**
 * @brief Applies translation transformation to a 4x4 matrix
 * @tparam T Data type of matrix elements
 * @tparam V Data type of translation components
 * @param src Source 4x4 matrix to be translated
 * @param x Translation along X-axis
 * @param y Translation along Y-axis
 * @param z Translation along Z-axis
 * @return New matrix with translation transformation applied
 */
template <typename T, typename V>
Matrix44<T> translate(const Matrix44<T>& src, V x, V y, V z) {
  Matrix44<T> result(src);
  auto col0 = src.getColum(0);
  auto col1 = src.getColum(1);
  auto col2 = src.getColum(2);
  auto col3 = src.getColum(3);

  Vector4<T> dstCol3 = col0 * x + col1 * y + col2 * z + col3;
  result.setColum(dstCol3, 3);

  return result;
}

/**
 * @brief Applies translation transformation to a 4x4 matrix using a 3D vector
 * @tparam T Data type of matrix elements
 * @tparam V Data type of translation vector components
 * @param src Source 4x4 matrix to be translated
 * @param v 3D vector containing translation components (x, y, z)
 * @return New matrix with translation transformation applied
 */
template <typename T, typename V>
Matrix44<T> translate(const Matrix44<T>& src, const Vector3<V>& v) {
  return translate(src, v.x, v.y, v.z);
}

/**
 * @brief Applies rotation transformation to a 4x4 matrix
 * @tparam T Data type of matrix elements
 * @param src Source 4x4 matrix to be rotated
 * @param angle Rotation angle in radians
 * @param v Axis of rotation as a 3D vector
 * @return New matrix with rotation transformation applied
 */
template <typename T>
Matrix44<T> rotate(const Matrix44<T>& src, float angle, const Vector3<T>& v) {
  T const c = std::cos(angle);
  T const s = std::sin(angle);

  Vector3<T> axis = normalize(v);
  Vector3<T> temp((T(1) - c) * axis);

  Matrix44<T> Rotate;
  Rotate.set(0, 0, c + temp[0] * axis[0]);
  Rotate.set(1, 0, temp[0] * axis[1] + s * axis[2]);
  Rotate.set(2, 0, temp[0] * axis[2] - s * axis[1]);

  Rotate.set(0, 1, temp[1] * axis[0] - s * axis[2]);
  Rotate.set(1, 1, c + temp[1] * axis[1]);
  Rotate.set(2, 1, temp[1] * axis[2] + s * axis[0]);

  Rotate.set(0, 2, temp[2] * axis[0] + s * axis[1]);
  Rotate.set(1, 2, temp[2] * axis[1] - s * axis[0]);
  Rotate.set(2, 2, c + temp[2] * axis[2]);

  auto rCol0 = Rotate.getColum(0);
  auto rCol1 = Rotate.getColum(1);
  auto rCol2 = Rotate.getColum(2);
  auto rCol3 = Rotate.getColum(3);

  auto srcCol0 = src.getColum(0);
  auto srcCol1 = src.getColum(1);
  auto srcCol2 = src.getColum(2);
  auto srcCol3 = src.getColum(3);

  auto col0 = srcCol0 * rCol0[0] + srcCol1 * rCol0[1] + srcCol2 * rCol0[2];
  auto col1 = srcCol0 * rCol1[0] + srcCol1 * rCol1[1] + srcCol2 * rCol1[2];
  auto col2 = srcCol0 * rCol2[0] + srcCol1 * rCol2[1] + srcCol2 * rCol2[2];
  auto col3 = srcCol3;

  Matrix44<T> result(src);

  result.setColum(col0, 0);
  result.setColum(col1, 1);
  result.setColum(col2, 2);
  result.setColum(col3, 3);

  return result;
}

/**
 * @brief Creates an orthographic projection matrix
 * @tparam T Data type of matrix elements
 * @param left Coordinate of the left vertical clipping plane
 * @param right Coordinate of the right vertical clipping plane
 * @param bottom Coordinate of the bottom horizontal clipping plane
 * @param top Coordinate of the top horizontal clipping plane
 * @param near Distance to the near clipping plane
 * @param far Distance to the far clipping plane
 * @return Orthographic projection matrix
 */
template <typename T>
Matrix44<T> orthographic(T left, T right, T bottom, T top, T near, T far) {
  Matrix44<T> result(static_cast<T>(1));

  result.set(0, 0, static_cast<T>(2) / (right - left));
  result.set(0, 3, -(right + left) / (right - left));
  result.set(1, 1, static_cast<T>(2) / (top - bottom));
  result.set(1, 3, -(top + bottom) / (top - bottom));
  result.set(2, 2, -static_cast<T>(2) / (far - near));
  result.set(1, 3, -(far + near) / (far - near));

  return result;
}

/**
 * @brief Creates a perspective projection matrix
 * @tparam T Data type of matrix elements
 * @param fovy Field of view angle in the y direction (in degrees)
 * @param aspect Aspect ratio (width over height)
 * @param n Distance to the near clipping plane
 * @param f Distance to the far clipping plane
 * @return Perspective projection matrix
 */
template <typename T>
Matrix44<T> perspective(T fovy, T aspect, T n, T f) {
  T const tanHalfFovy = std::tan(DEG2RAD(fovy / static_cast<T>(2)));

  Matrix44<T> result(static_cast<T>(0));
  result.set(0, 0, static_cast<T>(1) / (aspect * tanHalfFovy));
  result.set(1, 1, static_cast<T>(1) / (tanHalfFovy));
  result.set(2, 2, -(f + n) / (f - n));
  result.set(2, 3, -static_cast<T>(2) * f * n / (f - n));
  result.set(3, 2, -static_cast<T>(1));

  return result;
}

/**
 * @brief Creates a screen space transformation matrix
 * @tparam T Data type of matrix elements
 * @param width Width of the screen/pixel space
 * @param height Height of the screen/pixel space
 * @return Screen space transformation matrix
 */
template <typename T>
Matrix44<T> screenMatrix(const uint32_t& width, const uint32_t& height) {
  Matrix44<T> result(static_cast<T>(1));

  // x
  result.set(0, 0, static_cast<T>(width) / static_cast<T>(2));
  result.set(0, 3, static_cast<T>(width) / static_cast<T>(2));

  // y
  result.set(1, 1, static_cast<T>(height) / static_cast<T>(2));
  result.set(1, 3, static_cast<T>(height) / static_cast<T>(2));

  // z
  result.set(2, 2, 0.5f);
  result.set(2, 3, 0.5f);

  return result;
}
}  // namespace math