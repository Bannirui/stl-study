cmake_minimum_required(VERSION 3.20)
project(stl_study LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# debug flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -Wextra")

message(STATUS "System: ${CMAKE_SYSTEM_NAME}")

# 根据平台选择STL实现
if(APPLE)
    message(STATUS "Using libc++ (macOS)")
    set(STL_PATH ${CMAKE_SOURCE_DIR}/stl/libcxx)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Using libstdc++ (Linux)")
    set(STL_PATH ${CMAKE_SOURCE_DIR}/stl/libstdcxx)
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

# 全局include路径
include_directories(${STL_PATH})

add_subdirectory(test)