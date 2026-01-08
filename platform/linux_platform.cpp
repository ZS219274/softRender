#ifdef USE_SDL2
#include "linux_platform.h"
#include <SDL2/SDL.h>

LinuxPlatformWindow::LinuxPlatformWindow() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // 在实际应用中，这里应该记录错误
        return;
    }
}

LinuxPlatformWindow::~LinuxPlatformWindow() {
    destroy();
    SDL_Quit();
}

bool LinuxPlatformWindow::initialize(uint32_t width, uint32_t height) {
    mWidth = width;
    mHeight = height;

    mWindow = SDL_CreateWindow("Soft Renderer",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              mWidth, mHeight,
                              SDL_WINDOW_SHOWN);
    if (!mWindow) {
        return false;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!mRenderer) {
        return false;
    }

    mTexture = SDL_CreateTexture(mRenderer,
                                SDL_PIXELFORMAT_ARGB8888,
                                SDL_TEXTUREACCESS_STREAMING,
                                mWidth, mHeight);
    if (!mTexture) {
        return false;
    }

    mPixelBuffer = new uint32_t[mWidth * mHeight];
    mCanvasBuffer = mPixelBuffer;

    return true;
}

bool LinuxPlatformWindow::processMessages() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

void LinuxPlatformWindow::present(void* buffer) {
    if (buffer) {
        // 将RGBA数据复制到SDL纹理
        SDL_UpdateTexture(mTexture, nullptr, buffer, mWidth * sizeof(Uint32));
        SDL_RenderCopy(mRenderer, mTexture, nullptr, nullptr);
        SDL_RenderPresent(mRenderer);
    }
}

void LinuxPlatformWindow::destroy() {
    if (mPixelBuffer) {
        delete[] mPixelBuffer;
        mPixelBuffer = nullptr;
        mCanvasBuffer = nullptr;
    }
    if (mTexture) {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
    }
    if (mRenderer) {
        SDL_DestroyRenderer(mRenderer);
        mRenderer = nullptr;
    }
    if (mWindow) {
        SDL_DestroyWindow(mWindow);
        mWindow = nullptr;
    }
}

void* LinuxPlatformWindow::getNativeHandle() {
    return mWindow;
}

#endif