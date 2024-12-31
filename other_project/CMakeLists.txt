cmake_minimum_required(VERSION 3.10)
project(OtherProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(antlr4-runtime REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/../parser/include)

file(GLOB PARSER_SOURCES ${CMAKE_SOURCE_DIR}/../parser/src/*.cpp)

add_executable(OtherProject main.cpp ${PARSER_SOURCES})

# Подключаем antlr4-runtime
target_link_libraries(OtherProject antlr4_static)