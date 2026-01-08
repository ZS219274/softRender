#pragma once

#include "base.h"
#include <functional>

class PlatformWindow {
public:
    using MessageCallback = std::function<void(void* message)>;

    virtual ~PlatformWindow() = default;

    virtual bool initialize(uint32_t width = 800, uint32_t height = 600) = 0;
    virtual bool processMessages() = 0;
    virtual void present(void* buffer) = 0;
    virtual void destroy() = 0;
    virtual void* getNativeHandle() = 0;

    uint32_t getWidth() const { return mWidth; }
    uint32_t getHeight() const { return mHeight; }
    void* getCanvas() const { return mCanvasBuffer; }

protected:
    uint32_t mWidth = 800;
    uint32_t mHeight = 600;
    void* mCanvasBuffer = nullptr;
};