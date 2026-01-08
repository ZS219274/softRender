file(GLOB_RECURSE GPU ./  *.cpp)

add_library(gpuLib  ${GPU})

# 包含必要的头文件目录
target_include_directories(gpuLib PUBLIC ../)