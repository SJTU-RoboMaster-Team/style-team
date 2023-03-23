cmake_minimum_required(VERSION 3.14)

project(example_01)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
add_compile_options(-Wall)

include_directories(.)

add_subdirectory(event_loop)

add_executable(example cpp_example.cpp)
