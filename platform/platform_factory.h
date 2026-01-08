#pragma once
#include "../global/platform.h"

class PlatformFactory {
 public:
  static PlatformWindow* createPlatformWindow();
  static void destroyPlatformWindow(PlatformWindow* window);
};