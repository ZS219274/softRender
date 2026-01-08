#include "gpu.h"

GPU* GPU::mInstance = nullptr;
GPU* GPU::getInstance() {
	if (!mInstance) {
		mInstance = new GPU();
	}

	return mInstance;
}

GPU::GPU() {}

GPU::~GPU() {
	if (mFrameBuffer) {
		delete mFrameBuffer;
	}
}

void GPU::initSurface(const uint32_t& width, const uint32_t& height, void* buffer) {
	mFrameBuffer = new FrameBuffer(width, height, buffer);
}

void GPU::clear() {
	size_t pixelSize = mFrameBuffer->mWidth * mFrameBuffer->mHeight; // total number of pixels
	std::fill_n(mFrameBuffer->mColorBuffer, pixelSize, RGBA(0, 0, 0, 0)); 
}

void GPU::drawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color) {
	// coordinates start from bottom left corner
	uint32_t pixelPos = y * mFrameBuffer->mWidth + x; // add x offset to the current row
	mFrameBuffer->mColorBuffer[pixelPos] = color;
}

