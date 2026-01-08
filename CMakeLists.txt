#需求的最低cmake程序版本
cmake_minimum_required(VERSION 3.12)

#本工程的名字
project(Graphic) 

#本工程支持的C++版本
set(CMAKE_CXX_STANDARD 17)

file(GLOB copyResources "assets/*")
file(COPY ${copyResources} DESTINATION ${CMAKE_BINARY_DIR})

# 检测操作系统平台
if(WIN32)
    message(STATUS "Building for Windows")
    # Windows-specific settings
    set(PLATFORM_DEFINITIONS -DWIN32)
elseif(UNIX)
    message(STATUS "Building for Unix/Linux")
    # Unix/Linux-specific settings
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED sdl2)
    set(PLATFORM_DEFINITIONS -DUNIX)
endif()

# 添加平台定义
add_definitions(${PLATFORM_DEFINITIONS})

add_subdirectory(application)
add_subdirectory(gpu)
add_subdirectory(platform)

#本工程所有cpp文件编译链接，生成exe
set(MAIN_SOURCES
    main.cpp
)

add_executable(softRenderer ${MAIN_SOURCES})

# 链接库
if(UNIX)
    target_link_libraries(softRenderer applicationLib gpuLib platformLib ${SDL2_LIBRARIES})
    target_include_directories(softRenderer PRIVATE ${SDL2_INCLUDE_DIRS})
else()
    # Windows 平台链接
    target_link_libraries(softRenderer applicationLib gpuLib platformLib)
endif()
