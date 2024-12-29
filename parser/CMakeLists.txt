cmake_minimum_required(VERSION 3.10)
project(Parser)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ищем ANTLR4 runtime
find_package(antlr4-runtime REQUIRED)

set(SOURCES
        src/SimpleLanguageLexer.cpp
        src/SimpleLanguageParser.cpp
        src/SimpleLanguageBaseVisitor.cpp
        src/SimpleLanguageVisitor.cpp
)

set(HEADERS
        include/SimpleLanguageLexer.h
        include/SimpleLanguageParser.h
        include/SimpleLanguageBaseVisitor.h
        include/SimpleLanguageVisitor.h
)

# Создаем статическую библиотеку
add_library(Parser STATIC ${SOURCES} ${HEADERS})

# Подключаем ANTLR runtime к библиотеке
target_link_libraries(Parser antlr4-runtime)

# Указываем, где искать заголовочные файлы
target_include_directories(Parser PUBLIC include)
target_include_directories(Parser PUBLIC /usr/include/antlr4-runtime)  # Добавляем путь к ANTLR4

# main.cpp для тестирования
add_executable(SimpleLanguageParserTest main.cpp)
target_link_libraries(SimpleLanguageParserTest Parser)