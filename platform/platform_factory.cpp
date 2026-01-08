#include "platform_factory.h"

#ifdef _WIN32
#include "win_platform.h"
typedef WinPlatformWindow PlatformWindowImpl;
#elif defined(__linux__) || defined(__unix__)
#include "linux_platform.h"
typedef LinuxPlatformWindow PlatformWindowImpl;
#else
#error "Unsupported platform"
#endif

PlatformWindow* PlatformFactory::createPlatformWindow() {
  return new PlatformWindowImpl();
}

void PlatformFactory::destroyPlatformWindow(PlatformWindow* window) {
  delete window;
}