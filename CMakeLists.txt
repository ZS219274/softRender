#需求的最低cmake程序版本
cmake_minimum_required(VERSION 3.12)

#本工程的名字
project(Graphic) 

#本工程支持的C++版本
set(CMAKE_CXX_STANDARD 17)

# 检测操作系统平台
if(WIN32)
    message(STATUS "Building for Windows")
    # Windows-specific settings
    set(PLATFORM_SOURCES
        platform/win_platform.cpp
        platform/win_platform.h
    )
elseif(UNIX)
    message(STATUS "Building for Unix/Linux")
    # Unix/Linux-specific settings
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED sdl2)
    
    # 设置SDL2相关变量
    set(PLATFORM_CFLAGS ${SDL2_CFLAGS_OTHER})
    set(PLATFORM_LIBRARIES ${SDL2_LIBRARIES})
    set(PLATFORM_DEFINITIONS -DUSE_SDL2)
    
    set(PLATFORM_SOURCES
        platform/linux_platform.cpp
        platform/linux_platform.h
    )
endif()

# 添加平台定义
add_definitions(${PLATFORM_DEFINITIONS})

add_subdirectory(application)
add_subdirectory(gpu)

#本工程所有cpp文件编译链接，生成exe
set(MAIN_SOURCES
    main.cpp
    platform/platform_factory.cpp
    platform/platform_factory.h
    global/platform.h
    ${PLATFORM_SOURCES}
)

add_executable(softRenderer ${MAIN_SOURCES})

# 链接库
if(UNIX)
    target_link_libraries(softRenderer applicationLib gpuLib ${PLATFORM_LIBRARIES})
    target_include_directories(softRenderer PRIVATE ${SDL2_INCLUDE_DIRS})
else()
    # Windows 平台链接
    target_link_libraries(softRenderer applicationLib gpuLib)
endif()
