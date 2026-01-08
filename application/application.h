#pragma once
#include <memory>

#include "../global/base.h"
#include "../global/platform.h"

#define app Application::getInstance()

class Application {
 public:
  static Application* getInstance();
  Application();
  ~Application();

  // Initialize the application
  bool initApplication(const uint32_t& width = 800,
                       const uint32_t& height = 600);

  // Called each frame/loop, used to handle message system
  bool peekMessage();

  void show();

  // Start application main loop

  uint32_t getWidth() const { return mPlatformWindow->getWidth(); }
  uint32_t getHeight() const { return mPlatformWindow->getHeight(); }
  void* getCanvas() const { return mPlatformWindow->getCanvas(); }

 private:
  static std::unique_ptr<Application> mInstance;

  PlatformWindow* mPlatformWindow = nullptr;

  // true means the program is still running, indicating the loop should
  // continue false means the program has exited, indicating the loop should
  // exit
  bool mAlive{true};
};