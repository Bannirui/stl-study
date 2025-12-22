cmake_minimum_required(VERSION 3.20)
project(stl_study LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message(STATUS "System: ${CMAKE_SYSTEM_NAME}")

# 根据平台选择STL实现
if(APPLE)
    message(STATUS "Using libc++ (macOS)")
    include_directories(
            ${CMAKE_SOURCE_DIR}/stl/libcxx
    )
elseif(UNIX)
    message(STATUS "Using libstdc++ (Linux)")
    include_directories(
            ${CMAKE_SOURCE_DIR}/stl/libstdcxx
    )
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

add_subdirectory(test)