#include "gtest/gtest.h"

#include "simple_programming_language.h"

TEST(BasicTests, Variables) {
    testing::internal::CaptureStdout();
    std::string program = R"(
    int x = 123;
    )";
    InterpreteCode(program);
    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(BasicTests, Print) {
    testing::internal::CaptureStdout();
    std::string program = R"(
    int x = 123;
    print(x);
    )";
    InterpreteCode(program);
    ASSERT_EQ("123", testing::internal::GetCapturedStdout());
}

TEST(BasicTests, While) {
    testing::internal::CaptureStdout();
    std::string program = R"(
    int x = 12;
    while (x > -10) {
        print(x);
    }
    )";
    InterpreteCode(program);
    
    std::stringstream expected;
    int x = 12;
    while (x > -10) {
        expected << x;
    }
    ASSERT_EQ(expected.str(), testing::internal::GetCapturedStdout());
}
