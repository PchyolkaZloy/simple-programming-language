cmake_minimum_required(VERSION 3.10)
project(OtherProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем parser библиотеку
add_library(Parser STATIC IMPORTED)
set_target_properties(Parser PROPERTIES
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../parser/libs/libParser.a
)

add_executable(OtherProject main.cpp)

target_link_libraries(OtherProject Parser)
target_link_libraries(OtherProject Parser ${CMAKE_SOURCE_DIR}/../parser/libs/libantlr4-runtime.a)

# Указываем, где искать заголовочные файлы
include_directories(${CMAKE_SOURCE_DIR}/../parser/include)
include_directories(${CMAKE_SOURCE_DIR}/../parser/include/antlr4-runtime)

