cmake_minimum_required(VERSION 3.10)
project(SimpleLanguage)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# for release
# set(CMAKE_CXX_FLAGS "-O2")
# set(CMAKE_BUILD_TYPE, "Release")
# set(CMAKE_CXX_FLAGS "-fno-rtti")

find_package(antlr4-runtime REQUIRED)
include_directories(/opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.2/include/antlr4-runtime)
include_directories(libs/multiprecision-1.79/include)
include_directories(bytecode/include)
include_directories(vm)

add_subdirectory(libs)

add_subdirectory(bytecode)
#add_subdirectory(compiler)
add_subdirectory(gc)
add_subdirectory(vm)

add_executable(main main.cpp)
target_link_libraries(main boost_multiprecision)
target_link_libraries(main antlr4_static)
