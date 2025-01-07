cmake_minimum_required(VERSION 3.10)
project(Bytecode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
        src/SmplangLexer.cpp
        src/SmplangParser.cpp
        src/SmplangBaseVisitor.cpp
        src/SmplangVisitor.cpp
        src/SmplangBaseListener.cpp
        src/SmplangListener.cpp
        src/SmplangThrowingErrorListener.cpp
)

set(HEADERS
        include/SmplangLexer.h
        include/SmplangParser.h
        include/SmplangBaseVisitor.h
        include/SmplangVisitor.h
        include/SmplangBaseListener.h
        include/SmplangListener.h
        include/SmplangThrowingErrorListener.h
        include/smplang_common.h
        include/variables_util.h
        include/type_inference.h
        include/operators.h
)

add_subdirectory(multiprecision-1.79)

# Ищем ANTLR4 runtime (с conan находим)
find_package(antlr4-runtime REQUIRED)

# Создаем статическую библиотеку
add_library(Bytecode STATIC ${SOURCES} ${HEADERS})

# Подключаем ANTLR runtime к библиотеке
target_link_libraries(Bytecode PUBLIC antlr4_static boost_multiprecision)
# Указываем, где искать заголовочные файлы
target_include_directories(Bytecode PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# main.cpp для тестирования
add_executable(SmplangParserTest main.cpp)
target_link_libraries(SmplangParserTest Bytecode)
target_link_libraries(SmplangParserTest antlr4_static)
