cmake_minimum_required(VERSION 3.20)
project(LearnCpp)

set(CMAKE_CXX_STANDARD 20)

include(CMake/common.cmake)

add_subdirectory(thread)
add_subdirectory(design_pattern)
add_subdirectory(c++20)
add_subdirectory(tests)