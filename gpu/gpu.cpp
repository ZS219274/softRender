#include "gpu.h"

#include <mutex>

std::unique_ptr<GPU> GPU::mInstance = nullptr;

GPU* GPU::getInstance() {
  static std::once_flag sFlag;
  std::call_once(sFlag, []() { mInstance = std::make_unique<GPU>(); });

  return mInstance.get();
}

GPU::GPU() {}

GPU::~GPU() {
  if (mFrameBuffer) {
    delete mFrameBuffer;
    mFrameBuffer = nullptr;
  }
}

void GPU::initSurface(const uint32_t& width, const uint32_t& height,
                      void* buffer) {
  // 在创建新的FrameBuffer之前，先释放旧的FrameBuffer
  if (mFrameBuffer) {
    delete mFrameBuffer;
    mFrameBuffer = nullptr;
  }

  mFrameBuffer = new FrameBuffer(width, height, buffer);
}

// 清屏
void GPU::clear() {
  size_t pixelSize =
      mFrameBuffer->mWidth * mFrameBuffer->mHeight;  // total number of pixels
  std::fill_n(mFrameBuffer->mColorBuffer, pixelSize, RGBA(0, 0, 0, 0));
}

// 点
void GPU::drawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color) {
  // coordinates start from bottom left corner
  uint32_t pixelPos =
      y * mFrameBuffer->mWidth + x;  // add x offset to the current row
  mFrameBuffer->mColorBuffer[pixelPos] = color;
}

// 线段
void GPU::drawLine(const Point& p1, const Point& p2) {
  std::vector<Point> pixels;
  Raster::rasterizeLine(pixels, p1, p2);

  for (auto p : pixels) {
    drawPoint(p.x, p.y, p.color);
  }
}

// 三角形
void GPU::drawTriangle(const Point& p1, const Point& p2, const Point& p3) {
	std::vector<Point> pixels;
	Raster::rasterizeTriangle(pixels, p1, p2, p3);

	for (auto p : pixels) {
		drawPoint(p.x, p.y, p.color);
	}
}
