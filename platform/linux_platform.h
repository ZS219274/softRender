#pragma once
#include "../global/platform.h"

// 在Linux上使用SDL2作为跨平台窗口库
#ifdef USE_SDL2
#include <SDL2/SDL.h>

class LinuxPlatformWindow : public PlatformWindow {
 public:
  LinuxPlatformWindow();
  ~LinuxPlatformWindow();

  bool initialize(uint32_t width = 800, uint32_t height = 600) override;
  bool processMessages() override;
  void present(void* buffer) override;
  void destroy() override;
  void* getNativeHandle() override;

 private:
  SDL_Window* mWindow = nullptr;
  SDL_Renderer* mRenderer = nullptr;
  SDL_Texture* mTexture = nullptr;
  uint32_t* mPixelBuffer = nullptr;

  bool mSDLInitialized = false;  // 记录SDL是否成功初始化
};

#else
// 如果不使用SDL2，则创建一个基于X11的简单实现
// 这里我们使用SDL2作为跨平台解决方案
#error \
    "For Linux support, please install SDL2 development libraries and compile with -DUSE_SDL2"
#endif