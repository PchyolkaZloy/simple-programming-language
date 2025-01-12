add_executable(compiler_examples compiler_examples.cpp)
target_link_libraries(compiler_examples boost_multiprecision)

add_library(vm vm.h types.h vm.cpp types.cpp)
