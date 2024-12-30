cmake_minimum_required(VERSION 3.10)
project(Parser)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCES
        src/SmplangLexer.cpp
        src/SmplangParser.cpp
        src/SmplangBaseVisitor.cpp
        src/SmplangVisitor.cpp
        src/SmplangBaseListener.cpp
        src/SmplangListener.cpp
)

set(HEADERS
        include/SmplangLexer.h
        include/SmplangParser.h
        include/SmplangBaseVisitor.h
        include/SmplangVisitor.h
        include/SmplangBaseListener.h
        include/SmplangListener.h
)

# Создаем статическую библиотеку
add_library(Parser STATIC ${SOURCES} ${HEADERS})

target_link_libraries(Parser ${CMAKE_SOURCE_DIR}/libs/libantlr4-runtime.a)  # Указываем, где искать заголовочные файлы

target_include_directories(Parser PUBLIC include)
target_include_directories(Parser PUBLIC ${CMAKE_SOURCE_DIR}/include/antlr4-runtime)

# main.cpp для тестирования
add_executable(ParserTest main.cpp)
target_link_libraries(ParserTest Parser)