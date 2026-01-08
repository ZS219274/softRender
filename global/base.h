#pragma once

#include <assert.h>

#include <cmath>
#include <iostream>
#include <map>
#include <vector>

#include "../math/math.h"

#define PI 3.14159265358979323  // Pi constant
#define DEG2RAD(theta) \
  (0.01745329251994329 * (theta))     // Degrees to radians conversion
#define FRACTION(v) ((v) - (int)(v))  // Get fractional part

using byte = unsigned char;

struct RGBA {
  byte mB;
  byte mG;
  byte mR;
  byte mA;

  RGBA(byte r = 255, byte g = 255, byte b = 255, byte a = 255) {
    mR = r;
    mG = g;
    mB = b;
    mA = a;
  }
};

struct Point {
  Point(int32_t x = 0, int32_t y = 0, RGBA color = RGBA()) {
    this->x = x;
    this->y = y;
    this->color = color;
  }

  int32_t x;
  int32_t y;
  RGBA color;
  math::vec2f uv;
};

#define TEXTURE_WRAP_REPEAT 0
#define TEXTURE_WRAP_MIRROR 1