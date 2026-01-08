#pragma once
#include <assert.h>

#include <iostream>

namespace math {
template <typename T>
class Vector3;

template <typename T>
class Vector4;

/** @brief 2D vector class, represents a vector with x and y components */
template <typename T>
class Vector2 {
 public:
  /** Default constructor, initializes x and y components to 0 */
  Vector2() { x = y = 0; }

  /** Constructor with given x and y values
   * @param x The x component value
   * @param y The y component value
   */
  Vector2(T x, T y) : x(x), y(y) {}

  /** Copy constructor
   * @param v Vector2 object to copy from
   */
  Vector2(const Vector2<T>& v) : x(v.x), y(v.y) {}

  /** Constructor from Vector3, taking x and y components
   * @param v Vector3 object to convert from
   */
  Vector2(const Vector3<T>& v) : x(v.x), y(v.y) {}

  /** Constructor from Vector4, taking x and y components
   * @param v Vector4 object to convert from
   */
  Vector2(const Vector4<T>& v) : x(v.x), y(v.y) {}

  /** Get component value at specified index
   * @param i Component index (0 for x, 1 for y)
   * @return The component value at the specified index
   */
  T operator[](int i) const {
    assert(i >= 0 && i < 2);

    if (i == 0) return x;

    return y;
  }

  /** Get reference to component at specified index
   * @param i Component index (0 for x, 1 for y)
   * @return Reference to the component at the specified index
   */
  T& operator[](int i) {
    assert(i >= 0 && i < 2);

    if (i == 0) return x;

    return y;
  }

  /** Assign Vector3 to Vector2, taking only x and y components
   * @param v Vector3 object to assign from
   * @return The assigned Vector2 object
   */
  Vector2<T> operator=(const Vector3<T>& v) {
    x = v.x;
    y = v.y;
    return *this;
  }

  /** Assign Vector4 to Vector2, taking only x and y components
   * @param v Vector4 object to assign from
   * @return The assigned Vector2 object
   */
  Vector2<T> operator=(const Vector4<T>& v) {
    x = v.x;
    y = v.y;
    return *this;
  }

  /** Vector addition operator overload
   * @param v Vector to add
   * @return The resulting vector after addition
   */
  Vector2<T> operator+(const Vector2<T>& v) const {
    return Vector2(x + v.x, y + v.y);
  }

  /** Vector self-addition operator overload
   * @param v Vector to self-add
   * @return The self-added vector
   */
  Vector2<T> operator+=(const Vector2<T>& v) {
    x += v.x;
    y += v.y;
    return *this;
  }

  /** Vector-scalar multiplication operator overload
   * @param s Scalar value to multiply
   * @return The resulting vector after multiplication
   */
  Vector2<T> operator*(T s) const { return Vector2(x * s, y * s); }

  /** Vector-scalar self-multiplication operator overload
   * @param s Scalar value to self-multiply
   * @return The self-multiplied vector
   */
  Vector2<T> operator*=(T s) {
    x *= s;
    y *= s;
    return *this;
  }

  /** Vector division by scalar operator overload
   * @param f Scalar value to divide by
   * @return The resulting vector after division
   */
  Vector2<T> operator/(T f) const {
    assert(f != 0);
    float inv = static_cast<T>(1) / f;
    return Vector2(x * inv, y * inv);
  }

  /** Vector division by scalar self-operator overload
   * @param f Scalar value to divide by
   * @return The resulting vector after division
   */
  Vector2<T> operator/=(T f) {
    assert(f != 0);
    float inv = static_cast<T>(1) / f;
    x *= inv;
    y *= inv;
    return *this;
  }

  /** Unary negation operator overload
   * @return The negated vector
   */
  Vector2<T> operator-() { return Vector2(-x, -y); }

  /** Print the vector values to console */
  void print() {
    std::cout << "Vector2 is:" << std::endl;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << std::endl;
  }

 public:
  T x, y;
};

/** @brief 3D vector class, represents a vector with x, y and z components */
template <typename T>
class Vector3 {
 public:
  /** Default constructor, initializes x, y and z components to 0 */
  Vector3() { x = y = z = 0; }

  /** Constructor with given x, y and z values
   * @param x The x component value
   * @param y The y component value
   * @param z The z component value
   */
  Vector3(T x, T y, T z) : x(x), y(y), z(z) {}

  /** Copy constructor
   * @param v Vector3 object to copy from
   */
  Vector3(const Vector3<T>& v) : x(v.x), y(v.y), z(v.z) {}

  /** Constructor from Vector4, taking x, y and z components
   * @param v Vector4 object to convert from
   */
  Vector3(const Vector4<T>& v) : x(v.x), y(v.y), z(v.z) {}

  /** Get component value at specified index
   * @param i Component index (0 for x, 1 for y, 2 for z)
   * @return The component value at the specified index
   */
  T operator[](int i) const {
    assert(i >= 0 && i <= 2);

    if (i == 0) return x;
    if (i == 1) return y;

    return z;
  }

  /** Get reference to component at specified index
   * @param i Component index (0 for x, 1 for y, 2 for z)
   * @return Reference to the component at the specified index
   */
  T& operator[](int i) {
    assert(i >= 0 && i <= 2);

    if (i == 0) return x;
    if (i == 1) return y;

    return z;
  }

  /** Assign Vector2 to Vector3, with z component defaulting to 0
   * @param v Vector2 object to assign from
   * @return The assigned Vector3 object
   */
  Vector3<T> operator=(const Vector2<T>& v) {
    x = v.x;
    y = v.y;
    return *this;
  }

  /** Assign Vector4 to Vector3, taking only x, y and z components
   * @param v Vector4 object to assign from
   * @return The assigned Vector3 object
   */
  Vector3<T> operator=(const Vector4<T>& v) {
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
  }

  /** Vector addition operator overload
   * @param v Vector to add
   * @return The resulting vector after addition
   */
  Vector3<T> operator+(const Vector3<T>& v) const {
    return Vector3<T>(x + v.x, y + v.y, z + v.z);
  }

  /** Vector self-addition operator overload
   * @param v Vector to self-add
   * @return The self-added vector
   */
  Vector3<T> operator+=(const Vector3<T>& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  /** Vector subtraction operator overload
   * @param v Vector to subtract
   * @return The resulting vector after subtraction
   */
  Vector3<T> operator-(const Vector3<T>& v) const {
    return Vector3(x - v.x, y - v.y, z - v.z);
  }

  /** Vector self-subtraction operator overload
   * @param v Vector to self-subtract
   * @return The self-subtracted vector
   */
  Vector3<T> operator-=(const Vector3<T>& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
  }

  /** Vector-scalar multiplication operator overload
   * @param s Scalar value to multiply
   * @return The resulting vector after multiplication
   */
  Vector3<T> operator*(T s) const { return Vector3(x * s, y * s, z * s); }

  /** Vector-scalar self-multiplication operator overload
   * @param s Scalar value to self-multiply
   * @return The self-multiplied vector
   */
  Vector3<T> operator*=(T s) {
    x *= s;
    y *= s;
    z *= s;
    return *this;
  }

  /** Vector division by scalar operator overload
   * @param f Scalar value to divide by
   * @return The resulting vector after division
   */
  Vector3<T> operator/(T f) const {
    assert(f != 0);
    float inv = 1.0 / f;
    return Vector3(x * inv, y * inv, z * inv);
  }

  /** Vector division by scalar self-operator overload
   * @param f Scalar value to divide by
   * @return The resulting vector after division
   */
  Vector3<T> operator/=(T f) {
    assert(f != 0);
    float inv = 1.0 / f;
    x *= inv;
    y *= inv;
    z *= inv;
    return *this;
  }

  /** Unary negation operator overload
   * @return The negated vector
   */
  Vector3<T> operator-() const { return Vector3<T>(-x, -y, -z); }

  /** Print the vector values to console */
  void print() {
    std::cout << "Vector3 is:" << std::endl;
    std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
    std::cout << std::endl;
  }

 public:
  T x, y, z;
};

/** @brief 4D vector class, represents a vector with x, y, z and w components */
template <typename T>
class Vector4 {
 public:
  /** Default constructor, initializes x, y, z and w components to 0 */
  Vector4() { x = y = z = w = 0; }

  /** Constructor with given x, y, z and w values
   * @param x The x component value
   * @param y The y component value
   * @param z The z component value
   * @param w The w component value
   */
  Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

  /** Copy constructor
   * @param v Vector4 object to copy from
   */
  Vector4(const Vector4<T>& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

  /** Get component value at specified index
   * @param i Component index (0 for x, 1 for y, 2 for z, 3 for w)
   * @return The component value at the specified index
   */
  T operator[](int i) const {
    assert(i >= 0 && i <= 3);

    if (i == 0) return x;
    if (i == 1) return y;
    if (i == 2) return z;

    return w;
  }

  /** Get reference to component at specified index
   * @param i Component index (0 for x, 1 for y, 2 for z, 3 for w)
   * @return Reference to the component at the specified index
   */
  T& operator[](int i) {
    assert(i >= 0 && i <= 3);

    if (i == 0) return x;
    if (i == 1) return y;
    if (i == 2) return z;

    return w;
  }

  /** Assign Vector2 to Vector4, with z and w components defaulting to 0
   * @param v Vector2 object to assign from
   * @return The assigned Vector4 object
   */
  Vector4<T> operator=(const Vector2<T>& v) {
    x = v.x;
    y = v.y;
    ;
    return *this;
  }

  /** Assign Vector3 to Vector4, with w component defaulting to 0
   * @param v Vector3 object to assign from
   * @return The assigned Vector4 object
   */
  Vector4<T> operator=(const Vector3<T>& v) {
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
  }

  /** Vector addition operator overload
   * @param v Vector to add
   * @return The resulting vector after addition
   */
  Vector4<T> operator+(const Vector4<T>& v) const {
    return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
  }

  /** Vector self-addition operator overload
   * @param v Vector to self-add
   * @return The self-added vector
   */
  Vector4<T> operator+=(const Vector4<T>& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
  }

  /** Vector subtraction operator overload
   * @param v Vector to subtract
   * @return The resulting vector after subtraction
   */
  Vector4<T> operator-(const Vector4<T>& v) const {
    return Vector4<T>(x - v.x, y - v.y, z - v.z, w - v.w);
  }

  /** Vector self-subtraction operator overload
   * @param v Vector to self-subtract
   * @return The self-subtracted vector
   */
  Vector4<T> operator-=(const Vector4<T>& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
  }

  /** Vector-scalar multiplication operator overload
   * @param s Scalar value to multiply
   * @return The resulting vector after multiplication
   */
  Vector4<T> operator*(T s) const {
    return Vector4(x * s, y * s, z * s, w * s);
  }

  /** Vector-scalar self-multiplication operator overload
   * @param s Scalar value to self-multiply
   * @return The self-multiplied vector
   */
  Vector4<T> operator*=(T s) {
    x *= s;
    y *= s;
    z *= s;
    w *= s;
    return *this;
  }

  /** Vector-Vector3 multiplication operator overload, w component remains
   * unchanged
   * @param v Vector3 object to multiply with
   * @return The resulting vector after multiplication
   */
  Vector4<T> operator*=(const Vector3<T>& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
  }

  /** Vector division by scalar operator overload
   * @param f Scalar value to divide by
   * @return The resulting vector after division
   */
  Vector4<T> operator/(T f) const {
    assert(f != 0);
    float inv = 1.0 / f;
    return Vector4(x * inv, y * inv, z * inv, w * inv);
  }

  /** Vector division by scalar self-operator overload
   * @param f Scalar value to divide by
   * @return The resulting vector after division
   */
  Vector4<T> operator/=(T f) {
    assert(f != 0);
    float inv = 1.0 / f;
    x *= inv;
    y *= inv;
    z *= inv;
    w *= inv;
    return *this;
  }

  /** Unary negation operator overload
   * @return The negated vector
   */
  Vector4<T> operator-() const { return Vector3(-x, -y, -z, -w); }

  /** Print the vector values to console */
  void print() {
    std::cout << "Vector4 is:" << std::endl;
    std::cout << "x = " << x << ", y = " << y << ", z = " << z << ", w = " << w
              << std::endl;
    std::cout << std::endl;
  }

 public:
  T x, y, z, w;
};

/** Common vector type aliases */
using vec2f = Vector2<float>;  ///< 2D float vector
using vec2i = Vector2<int>;    ///< 2D int vector
using vec3f = Vector3<float>;  ///< 3D float vector
using vec3i = Vector3<int>;    ///< 3D int vector
using vec4f = Vector4<float>;  ///< 4D float vector
using vec4i = Vector4<int>;    ///< 4D int vector
}  // namespace math