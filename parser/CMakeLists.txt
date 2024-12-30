cmake_minimum_required(VERSION 3.10)
project(Parser)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(antlr4-runtime REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Автоматически добавляем все .cpp файлы из папки src/
file(GLOB PARSER_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Создаем библиотеку
add_library(Parser ${PARSER_SOURCES})

# Подключаем antlr4-runtime через Conan
target_link_libraries(Parser antlr4_static)

# Указываем, где искать заголовочные файлы
target_include_directories(Parser PUBLIC include)

# main.cpp для тестирования
add_executable(ParserTest main.cpp)
target_link_libraries(ParserTest Parser)