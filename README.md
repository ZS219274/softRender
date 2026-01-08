# 跨平台软件渲染器

这是一个跨平台的软件渲染器项目，支持Windows和Linux平台。

## 功能特性

- 软件方式实现图形渲染（softRenderer）
- 跨平台支持（Windows和Linux）
- 帧缓冲（Frame Buffer）管理与像素级绘图
- 图形设备接口抽象

## 构建要求

### Windows平台
- CMake 3.12+
- 支持C++17的编译器（如MSVC、MinGW等）
- Windows SDK

### Linux平台
- CMake 3.12+
- 支持C++17的编译器（g++ 7+, clang++）
- SDL2开发库

## Linux平台安装SDL2

Ubuntu/Debian:
```bash
sudo apt-get install libsdl2-dev
```

CentOS/RHEL/Fedora:
```bash
sudo dnf install SDL2-devel
# 或者在较旧的系统上
sudo yum install SDL2-devel
```

## 构建说明

### Windows平台
```bash
cd /home/ubuntu/wxx/lectureCodes02-GDI  # 或项目所在路径
mkdir build && cd build
cmake ..
cmake --build .
```

### Linux平台
```bash
cd /home/ubuntu/wxx/lectureCodes02-GDI
mkdir build && cd build
cmake ..
make
```

## 项目架构

```
main.cpp → softRenderer (exe)
   ↓
applicationLib ←→ gpuLib
   ↓
Platform Abstraction Layer
   ├ Windows Implementation (WinPlatformWindow)
   └ Linux Implementation (LinuxPlatformWindow)
```

## 设计模式

- 分层架构模式：应用层（application）与设备层（gpu）分离
- 抽象工厂模式：用于创建平台相关的窗口对象
- 单例模式：Application和GPU类

## 技术栈

- C++17
- SDL2（Linux平台）
- Windows API（Windows平台）
- CMake构建系统