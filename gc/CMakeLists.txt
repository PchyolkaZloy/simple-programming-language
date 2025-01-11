cmake_minimum_required(VERSION 3.12)

project(
    garbage_collector
    VERSION 1.0
    DESCRIPTION "gc"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)
add_subdirectory(bin)
