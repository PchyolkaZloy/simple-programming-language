cmake_minimum_required(VERSION 3.10)
project(Bytecode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ищем ANTLR4 runtime
# Не ищем, всё равно не найдём 😭
#find_package(ANTLR REQUIRED)

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

set(DLL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/antlr4-cpp-runtime-vs2022/lib/vs-2022/x64/Release DLL/antlr4-runtime.dll")
set(LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/antlr4-cpp-runtime-vs2022/lib/vs-2022/x64/Release DLL/antlr4-runtime.lib")
# Создаем статическую библиотеку
add_library(Bytecode STATIC ${SOURCES} ${HEADERS})
add_library(antlr4-runtime STATIC IMPORTED)
set_target_properties(antlr4-runtime PROPERTIES
        IMPORTED_LOCATION "${LIB_PATH}"
)
configure_file("${DLL_PATH}" "${CMAKE_BINARY_DIR}/antlr4-runtime.dll" COPYONLY)

# Подключаем ANTLR runtime к библиотеке
target_link_libraries(Bytecode antlr4-runtime)
# Указываем, где искать заголовочные файлы
target_include_directories(Bytecode PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# Добавляем путь к ANTLR4
target_include_directories(Bytecode PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-cpp-runtime-vs2022/antlr4-runtime)

# main.cpp для тестирования
add_executable(SmplangParserTest main.cpp)
target_link_libraries(SmplangParserTest Bytecode)
target_link_libraries(SmplangParserTest antlr4-runtime)
