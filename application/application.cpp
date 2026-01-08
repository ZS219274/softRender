#include"application.h"
#include "../platform/platform_factory.h"

Application* Application::mInstance = nullptr;
Application* Application::getInstance() {
	if (mInstance == nullptr) {
		mInstance = new Application();
	}

	return mInstance;
}

Application::Application() {}
Application::~Application() {
    if (mPlatformWindow) {
        mPlatformWindow->destroy();
        PlatformFactory::destroyPlatformWindow(mPlatformWindow);
        mPlatformWindow = nullptr;
    }
}

bool Application::initApplication(const uint32_t& width, const uint32_t& height) {
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
