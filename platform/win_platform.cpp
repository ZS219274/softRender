#include "win_platform.h"

WinPlatformWindow::WinPlatformWindow() {
  mWindowInst = GetModuleHandle(nullptr);
}

WinPlatformWindow::~WinPlatformWindow() { destroy(); }

LRESULT CALLBACK WinPlatformWindow::WndProc(HWND hWnd, UINT message,
                                            WPARAM wParam, LPARAM lParam) {
  WinPlatformWindow* window = reinterpret_cast<WinPlatformWindow*>(
      GetWindowLongPtr(hWnd, GWLP_USERDATA));

  switch (message) {
    case WM_CLOSE:
      DestroyWindow(hWnd);
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      // Don't set mCanvasBuffer to nullptr here since destroy method will
      // handle it
      break;
    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(hWnd, &ps);
      EndPaint(hWnd, &ps);
      break;
    }
    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}

bool WinPlatformWindow::initialize(uint32_t width, uint32_t height) {
  mWidth = width;
  mHeight = height;

  registerWindowClass();

  if (!createWindow()) {
    return false;
  }

  // Set window pointer to window data so the callback function can use it
  SetWindowLongPtr(mHwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

  // Initialize device context
  mhDC = GetDC(mHwnd);
  mCanvasDC = CreateCompatibleDC(mhDC);

  BITMAPINFO bmpInfo{};
  bmpInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
  bmpInfo.bmiHeader.biWidth = mWidth;
  bmpInfo.bmiHeader.biHeight = mHeight;
  bmpInfo.bmiHeader.biPlanes = 1;
  bmpInfo.bmiHeader.biBitCount = 32;
  bmpInfo.bmiHeader.biCompression = BI_RGB;

  mhBmp = CreateDIBSection(mCanvasDC, &bmpInfo, DIB_RGB_COLORS, &mCanvasBuffer,
                           0, 0);
  if (!mhBmp) {
    // If DIB creation fails, clean up allocated resources
    if (mCanvasDC) {
      DeleteDC(mCanvasDC);
      mCanvasDC = nullptr;
    }
    if (mhDC) {
      ReleaseDC(mHwnd, mhDC);
      mhDC = nullptr;
    }
    return false;
  }
  SelectObject(mCanvasDC, mhBmp);

  memset(mCanvasBuffer, 0, mWidth * mHeight * 4);

  return true;
}

ATOM WinPlatformWindow::registerWindowClass() {
  WNDCLASSEXW wndClass;

  wndClass.cbSize = sizeof(WNDCLASSEX);
  wndClass.style = CS_HREDRAW | CS_VREDRAW;
  wndClass.lpfnWndProc = WndProc;
  wndClass.cbClsExtra = 0;
  wndClass.cbWndExtra = 0;
  wndClass.hInstance = mWindowInst;
  wndClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
  wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
  wndClass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
  wndClass.lpszMenuName = nullptr;
  wndClass.lpszClassName = mWindowClassName;
  wndClass.hIconSm = LoadIcon(nullptr, IDI_WINLOGO);

  return RegisterClassExW(&wndClass);
}

bool WinPlatformWindow::createWindow() {
  auto dwExStyle = WS_EX_APPWINDOW;
  auto dwStyle = WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

  RECT windowRect;
  windowRect.left = 0L;
  windowRect.top = 0L;
  windowRect.right = static_cast<long>(mWidth);
  windowRect.bottom = static_cast<long>(mHeight);
  AdjustWindowRectEx(&windowRect, dwStyle, FALSE, dwExStyle);

  mHwnd = CreateWindowW(mWindowClassName, L"Soft Renderer", dwStyle,
                        CW_USEDEFAULT, CW_USEDEFAULT,  // position
                        windowRect.right - windowRect.left,
                        windowRect.bottom - windowRect.top, nullptr, nullptr,
                        mWindowInst, nullptr);

  if (!mHwnd) {
    return FALSE;
  }

  ShowWindow(mHwnd, SW_SHOW);
  UpdateWindow(mHwnd);

  return TRUE;
}

bool WinPlatformWindow::processMessages() {
  MSG msg;
  if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
    return (msg.message != WM_QUIT);
  }
  return true;
}

void WinPlatformWindow::present(void* buffer) {
  if (buffer && mCanvasBuffer) {
    // Copy input buffer data to CanvasBuffer
    memcpy(mCanvasBuffer, buffer, mWidth * mHeight * sizeof(uint32_t));
    // Copy memory DC content to screen DC
    BitBlt(mhDC, 0, 0, mWidth, mHeight, mCanvasDC, 0, 0, SRCCOPY);
  }
}

void WinPlatformWindow::destroy() {
  if (mhBmp) {
    DeleteObject(mhBmp);
    mhBmp = nullptr;
    mCanvasBuffer =
        nullptr;  // mCanvasBuffer becomes invalid after mhBmp is deleted
  }
  if (mCanvasDC) {
    DeleteDC(mCanvasDC);
    mCanvasDC = nullptr;
  }
  if (mhDC) {
    ReleaseDC(mHwnd, mhDC);  // Only release when obtained with GetDC
    mhDC = nullptr;
  }
  if (mHwnd) {
    DestroyWindow(mHwnd);
    mHwnd = nullptr;
  }
}

void* WinPlatformWindow::getNativeHandle() { return mHwnd; }