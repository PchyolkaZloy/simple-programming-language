cmake_minimum_required(VERSION 3.10)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE GTest::gtest_main boost_multiprecision Bytecode vm)
target_include_directories(tests PUBLIC ${PROJECT_SOURCE_DIR}/include)

include(GoogleTest)

gtest_discover_tests(tests)