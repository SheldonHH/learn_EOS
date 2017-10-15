# CMake的最低的版本要求
cmake_minimum_required(VERSION 2.8)

# 项目信息 （生成项目名称 Demo1）
project(Demo1)

# 生成目标 (将源文件编译生成可执行的二进制文件 Demo)
add_executable(Demo main.cpp) 

# CMake的最低的版本要求
cmake_minimum_required (VERSION 2.6)
project (Tutorial)


# 设置版本号
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
 
# 设置头文件把CMake的设置放入源代码
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )
 
# 给查寻路线添加binary tree，这样我们就能更轻易的找到TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")
 
# 添加executable 文件
add_executable(Tutorial tutorial.cxx)