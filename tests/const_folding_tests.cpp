#include "gtest/gtest.h"

#include "simple_programming_language.h"

/// CONST_FOLDING TESTS
TEST(ConstFoldingTests, SimpleExpression) {
    std::string program = R"(
    double x = --1 + 56 * 34.7 - 'c';
    print(x);
    )";
    testing::internal::CaptureStdout();
    InterpreteCode(program, true, false, false);
    std::string output_without_folding = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    InterpreteCode(program, true, false, true);
    std::string output_with_folding = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output_without_folding, output_with_folding);
}

TEST(ConstFoldingTests, ExpressionWithFunctionCall) {
    std::string program = R"(
    func int f() {
        return 42;
    }
    int x = --1 + f() * 34.7 - 'c';
    print(x);
    )";
    testing::internal::CaptureStdout();
    InterpreteCode(program, true, false, false);
    std::string output_without_folding = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    InterpreteCode(program, true, false, true);
    std::string output_with_folding = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output_without_folding, output_with_folding);
}

TEST(ConstFoldingTests, WhileLoop) {
    std::string program = R"(
    int x = 12;
        while (x > --10 + 0.5) {
    print(x);
    x = x - 1;
}
    )";
    testing::internal::CaptureStdout();
    InterpreteCode(program, true, false, false);
    std::string output_without_folding = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    InterpreteCode(program, true, false, true);
    std::string output_with_folding = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output_without_folding, output_with_folding);
}

TEST(ConstFoldingTests, IfConditions) {
    std::string program = R"(
    bool x = 3245 - 8.34 * 'a' > 34 || 1231 > 1;
    double y = 3245 - 8.34 * 'a' > 34 || 1231 > 1;
    if(x)
        print(x);
    else
        print(y);
    print(x+y);
}
    )";
    testing::internal::CaptureStdout();
    InterpreteCode(program, true, false, false);
    std::string output_without_folding = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    InterpreteCode(program, true, false, true);
    std::string output_with_folding = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output_without_folding, output_with_folding);
}

TEST(ConstFoldingTests, MultipleLoopsIfs) {
    std::string program = R"(
        int x = --2;
        while (x > --7) {
            print(x);
            print('\n');
            x = x - 1;
            if (x <= --4) {
                int y = x - 1;
                while (y >= --8) {
                    print(y);
                    print('\n');
                    y = y -1;
                    int i = 0;
                    while (i < 10) {
                        print(i % (5 - 3 / 2));
                        i = i + 1;
                    }
                }
            } elif (x == --3) {
                    print(34 +56 /0.9 - 'g' * x);
                    print('a');
                    print('\n');
            } else
                    print('o');
        }

    )";
    testing::internal::CaptureStdout();
    InterpreteCode(program, true, false, false);
    std::string output_without_folding = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    InterpreteCode(program, true, false, true);
    std::string output_with_folding = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output_without_folding, output_with_folding);
}