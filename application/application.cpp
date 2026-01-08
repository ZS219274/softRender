#include "application.h"

#include <mutex>

#include "../platform/platform_factory.h"

std::unique_ptr<Application> Application::mInstance = nullptr;

Application* Application::getInstance() {
  static std::once_flag sFlag;
  std::call_once(sFlag, []() { mInstance = std::make_unique<Application>(); });

  return mInstance.get();
}

Application::Application() {}
Application::~Application() {
  if (mPlatformWindow) {
    mPlatformWindow->destroy();
    PlatformFactory::destroyPlatformWindow(mPlatformWindow);
  }
}

bool Application::initApplication(const uint32_t& width,
                                  const uint32_t& height) {
  mPlatformWindow = PlatformFactory::createPlatformWindow();
  if (!mPlatformWindow) {
    return false;
  }

  return mPlatformWindow->initialize(width, height);
}

bool Application::peekMessage() {
  if (mPlatformWindow) {
    mAlive = mPlatformWindow->processMessages();
  }
  return mAlive;
}

void Application::show() {
  if (mPlatformWindow) {
    mPlatformWindow->present(mPlatformWindow->getCanvas());
  }
}
