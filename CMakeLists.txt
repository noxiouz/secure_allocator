cmake_minimum_required(VERSION 3.0)
project(safe_allocator)

add_compile_options(
    -std=c++1y
    -Wall
    -Wpedantic
)
add_executable(main main.cpp)

find_library(SODIUM NAMES libsodium)
target_link_libraries(main ${SODIUM})
