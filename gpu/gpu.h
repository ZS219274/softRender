#pragma once
#include <memory>

#include "../application/application.h"
#include "../application/image.h"
#include "../global/base.h"
#include "Raster.h"
#include "frameBuffer.h"

#define sgl GPU::getInstance()

class GPU {
 public:
  static GPU* getInstance();
  GPU();

  ~GPU();

  void initSurface(const uint32_t& width, const uint32_t& height,
                   void* buffer = nullptr);

  void clear();

  void drawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color);

  void drawLine(const Point& p1, const Point& p2);

  void drawTriangle(const Point& p1, const Point& p2, const Point& p3);

  void drawImage(const Image* image);

  void drawImageWidthAlpha(const Image* image, const uint32_t& alpha);

  void setBlending(bool enable);

  void setTexture(Image* image) { mImage = image; }
  void setBilinear(bool enable) { mEnableBilinear = enable; }

  void setWrapMode(int32_t mode) { mWrapMode = mode; }

 private:
  RGBA sampleNearest(const math::vec2f& uv);
  RGBA sampleBilinear(const math::vec2f& uv);

  void checkWrap(float& n);

  static std::unique_ptr<GPU> mInstance;
  bool mEnableBlending{false};
  bool mEnableBilinear{false};

  int32_t mWrapMode{TEXTURE_WRAP_REPEAT};
  FrameBuffer* mFrameBuffer{nullptr};
  Image* mImage{nullptr};
};