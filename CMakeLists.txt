cmake_minimum_required(VERSION 3.10)
project(SimpleLanguage)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(parser)
#add_subdirectory(compiler)
add_subdirectory(gc)
