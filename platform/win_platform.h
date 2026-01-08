#pragma once
#include "../global/platform.h"
#include <Windows.h>

class WinPlatformWindow : public PlatformWindow {
public:
    WinPlatformWindow();
    ~WinPlatformWindow();

    bool initialize(uint32_t width = 800, uint32_t height = 600) override;
    bool processMessages() override;
    void present(void* buffer) override;
    void destroy() override;
    void* getNativeHandle() override;

private:
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    bool createWindow();
    ATOM registerWindowClass();

private:
    HINSTANCE mWindowInst = nullptr;
    WCHAR mWindowClassName[100] = L"SoftRendererWindow";
    HWND mHwnd = nullptr;

    HDC mhDC = nullptr;      // 主窗口的DC
    HDC mCanvasDC = nullptr; // 用于绘图的内存DC
    HBITMAP mhBmp = nullptr; // 位图句柄
};