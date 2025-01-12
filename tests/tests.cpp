#include "gtest/gtest.h"

#include "simple_programming_language.h"

/// TEMPLATE TESTS
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
    while (x > --10) {
        print(x);
        x = x - 1;
    }
    )";
    InterpreteCode(program);

    std::stringstream expected;
    int x = 12;
    while (x > -10) {
        expected << x;
        x--;
    }
    ASSERT_EQ(expected.str(), testing::internal::GetCapturedStdout());
}

////////////////////////////////////////////////////////////////////////////////////
/// PRIMITIVE TESTS
/// INTEGER
TEST(PrimitiveTests, IntDecl) {
    const std::string program = R"(
    int x;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, IntDeclWithValue) {
    const std::string program = R"(
    int x = 123;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

// bytecode::ASTException , bytecode::ValidatorException
TEST(PrimitiveTests, IntDeclWithParserException) {
    const std::string program = R"(
    int x = ;
    )";

    EXPECT_THROW({
                 InterpreteCode(program);
                 }, bytecode::ParserException);
}


TEST(PrimitiveTests, IntDeclWithBoolValue) {
    const std::string program = R"(
    int x = true;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, IntDeclWithCharValue) {
    const std::string program = R"(
    int x = '1';
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, IntDeclWithDoubleValue) {
    const std::string program = R"(
    int x = 1.;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

////////////////////////////////////////////////////////////////////////////////////
/// DOUBLE
TEST(PrimitiveTests, DoubleDecl) {
    const std::string program = R"(
    double x;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, DoubleDeclWithValue) {
    const std::string program = R"(
    double x = 123.123;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, DoubleDeclWithParserException) {
    const std::string program = R"(
    double x = ;
    )";

    EXPECT_THROW({
                 InterpreteCode(program);
                 }, bytecode::ParserException);
}

TEST(PrimitiveTests, DoubleDeclWithBoolValue) {
    const std::string program = R"(
    double x = true;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, DoubleDeclWithCharValue) {
    const std::string program = R"(
    double x = '1';
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, DoubleDeclWithIntValue) {
    const std::string program = R"(
    double x = 1;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

////////////////////////////////////////////////////////////////////////////////////
/// BOOLEAN
TEST(PrimitiveTests, BoolDecl) {
    const std::string program = R"(
    bool x;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, BoolDeclWithValue) {
    const std::string program = R"(
    bool x = false;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, BoolDeclWithParserException) {
    const std::string program = R"(
    bool x = ;
    )";

    EXPECT_THROW({
                 InterpreteCode(program);
                 }, bytecode::ParserException);
}

TEST(PrimitiveTests, BoolDeclWithIntValue) {
    const std::string program = R"(
    bool x = 123;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, BoolDeclWithCharValue) {
    const std::string program = R"(
    bool x = '1';
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, BoolDeclWithDoubleValue) {
    const std::string program = R"(
    bool x = 1.123;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

////////////////////////////////////////////////////////////////////////////////////
/// CHAR
TEST(PrimitiveTests, CharDecl) {
    const std::string program = R"(
    char x;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, CharDeclWithValue) {
    const std::string program = R"(
    char x = 'x';
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, CharDeclWithParserException) {
    const std::string program = R"(
    char x = ;
    )";

    EXPECT_THROW({
                 InterpreteCode(program);
                 }, bytecode::ParserException);
}

TEST(PrimitiveTests, CharDeclWithIntValue) {
    const std::string program = R"(
    char x = 64;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, CharDeclWithBoolValue) {
    const std::string program = R"(
    char x = false;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(PrimitiveTests, CharDeclWithDoubleValue) {
    const std::string program = R"(
    char x = 1.123;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

////////////////////////////////////////////////////////////////////////////////////
/// OPERATION (BIN)
TEST(BinaryOperationsTests, MultOperations) {
    const std::string program = R"(
    int a = 10;
    int b = 3;

    print(a * b); // 30
    print(a / b); // 3
    print(a % b); // 1
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("30\n3\n1", testing::internal::GetCapturedStdout());
}

TEST(BinaryOperationsTests, AddOperations) {
    const std::string program = R"(
    int a = 10;
    int b = 3;

    print(a + b); // 13
    print(a - b); // 7
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("13\n7", testing::internal::GetCapturedStdout());
}

TEST(BinaryOperationsTests, CompOperations) {
    const std::string program = R"(
    int a = 10;
    int b = 3;

    print(a == b); // false
    print(a != b); // true
    print(a < b);  // false
    print(a > b);  // true
    print(a <= b); // false
    print(a >= b); // true
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("false\ntrue\nfalse\ntrue\nfalse\ntrue", testing::internal::GetCapturedStdout());
}

TEST(BinaryOperationsTests, AndOperation) {
    const std::string program = R"(
    bool a = true;
    bool b = false;

    print(a && a); // true
    print(a && b); // false
    print(b && b); // false
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("true\nfalse\nfalse", testing::internal::GetCapturedStdout());
}

TEST(BinaryOperationsTests, OrOperation) {
    const std::string program = R"(
    bool a = true;
    bool b = false;

    print(a || a); // true
    print(a || b); // true
    print(b || b); // false
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("true\ntrue\nfalse", testing::internal::GetCapturedStdout());
}

TEST(BinaryOperationsTests, CombinedOperations) {
    const std::string program = R"(
    int a = 10;
    int b = 3;
    int c = 5;

    print((a + b) * c); // 65
    print(a > b && b < c); // true
    print(a == b || b != c); // true
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("65\ntrue\ntrue", testing::internal::GetCapturedStdout());
}

TEST(BinaryOperationsTests, DoubleOperations) {
    const std::string program = R"(
    double a = 10.5;
    double b = 3.2;

    print(a + b); // 13.7
    print(a - b); // 7.3
    print(a * b); // 33.6
    print(a / b); // 3.28125
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("13.7\n7.3\n33.6\n3.28125", testing::internal::GetCapturedStdout());
}

TEST(BinaryOperationsTests, CharOperations) {
    const std::string program = R"(
    char a = 'A';
    char b = 'B';

    print(a == b); // false
    print(a != b); // true
    print(a < b);  // true
    print(a > b);  // false
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("false\ntrue\ntrue\nfalse", testing::internal::GetCapturedStdout());
}

TEST(BinaryOperationsTests, BoolOperations) {
    const std::string program = R"(
    bool a = true;
    bool b = false;

    print(a == b); // false
    print(a != b); // true
    print(a && b); // false
    print(a || b); // true
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("false\ntrue\nfalse\ntrue", testing::internal::GetCapturedStdout());
}

////////////////////////////////////////////////////////////////////////////////////
/// OPERATION (UNARY)
TEST(UnaryOperationsTests, NegInt) {
    const std::string program = R"(
    int a = 10;
    int b = --a;
    print(b);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("-10", testing::internal::GetCapturedStdout());
}

TEST(UnaryOperationsTests, NegDouble) {
    const std::string program = R"(
    double a = 3.14;
    double b = --a;
    print(b);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("-3.14", testing::internal::GetCapturedStdout());
}

TEST(UnaryOperationsTests, NotBool) {
    const std::string program = R"(
    bool a = true;
    bool b = !a;
    print(b);

    bool c = false;
    bool d = !c;
    print(d);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("false\ntrue", testing::internal::GetCapturedStdout());
}

TEST(UnaryOperationsTests, CombinedUnaryOperations) {
    const std::string program = R"(
    int a = 10;
    int b = --a;
    bool c = !(b > 0);
    print(c);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("true", testing::internal::GetCapturedStdout());
}

TEST(UnaryOperationsTests, NegInExpression) {
    const std::string program = R"(
    int a = 5;
    int b = 3;
    int c = --a + b;
    print(c);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("2", testing::internal::GetCapturedStdout());
}

TEST(UnaryOperationsTests, NotInCondition) {
    const std::string program = R"(
    bool a = true;
    if (!a) {
        print("A is false");
    } else {
        print("A is true");
    }
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("A is true", testing::internal::GetCapturedStdout());
}

TEST(UnaryOperationsTests, NegChar) {
    const std::string program = R"(
    char a = 'A';
    int b = --a;
    print(b);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("-65\n", testing::internal::GetCapturedStdout()); // ASCII-код 'A' равен 65
}

////////////////////////////////////////////////////////////////////////////////////
/// ARRAY
TEST(ArrayTests, IntArrDecl) {
    const std::string program = R"(
    int[] arr;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, BoolArrDecl) {
    const std::string program = R"(
    bool[] arr;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, DoubleArrDecl) {
    const std::string program = R"(
    double[] arr;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, CharArrDecl) {
    const std::string program = R"(
    char[] arr;
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, IntArrAppend) {
    const std::string program = R"(
    int[] arr;

    append(arr, 1);
    append(arr, 2);
    append(arr, 3);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, CharArrAppend) {
    const std::string program = R"(
    char[] arr;

    append(arr, 'a');
    append(arr, 'b');
    append(arr, 'c');
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, DoubleArrAppend) {
    const std::string program = R"(
    double[] arr;

    append(arr, 1.5);
    append(arr, 2.75);
    append(arr, 3.125);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, BoolArrAppend) {
    const std::string program = R"(
    bool[] arr;

    append(arr, true);
    append(arr, false);
    append(arr, true);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, IntArrAppendWithOutput) {
    const std::string program = R"(
    int[] arr;

    append(arr, 1);
    append(arr, 2);
    append(arr, 3);

    print(arr);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("{1, 2, 3}", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, CharArrAppendWithOutput) {
    const std::string program = R"(
    char[] arr;

    append(arr, 'a');
    append(arr, 'b');
    append(arr, 'c');

    print(arr);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("{a, b, c}", output);
}

TEST(ArrayTests, DoubleArrAppendWithOutput) {
    const std::string program = R"(
    double[] arr;

    append(arr, 1.5);
    append(arr, 2.75);
    append(arr, 3.125);

    print(arr);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("{1.5, 2.75, 3.125}", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, BoolArrAppendWithOutput) {
    const std::string program = R"(
    bool[] arr;

    append(arr, true);
    append(arr, false);
    append(arr, true);

    print(arr);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("{true, false, true}", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, IntArrAppendAndChangeWithOutput) {
    const std::string program = R"(
    int[] arr;

    append(arr, 1);
    append(arr, 2);
    append(arr, 3);

    arr[0] = 2;
    arr[1] = 3;

    print(arr);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("{2, 3, 3}", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, CharArrAppendAndChangeWithOutput) {
    const std::string program = R"(
    char[] arr;

    append(arr, 'a');
    append(arr, 'b');
    append(arr, 'c');

    arr[0] = 'x';
    arr[1] = 'y';

    print(arr);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("{x, y, c}", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, DoubleArrAppendAndChangeWithOutput) {
    const std::string program = R"(
    double[] arr;

    append(arr, 1.5);
    append(arr, 2.75);
    append(arr, 3.125);

    arr[0] = 10.1;
    arr[1] = 20.2;

    print(arr);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("{10.1, 20.2, 3.125}", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, BoolArrAppendAndChangeWithOutput) {
    const std::string program = R"(
    bool[] arr;

    append(arr, true);
    append(arr, false);
    append(arr, true);

    arr[0] = false;
    arr[1] = true;

    print(arr);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("{false, true, true}", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, IntArrAtIndexPrint) {
    const std::string program = R"(
    int[] arr;

    append(arr, 1);
    append(arr, 2);
    append(arr, 3);

    print(arr[0]);
    print(arr[1]);
    print(arr[2]);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("1\n2\n3\n", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, CharArrAtIndexPrint) {
    const std::string program = R"(
    char[] arr;

    append(arr, 'a');
    append(arr, 'b');
    append(arr, 'c');

    print(arr[0]);
    print(arr[1]);
    print(arr[2]);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("a\nb\nc\n", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, DoubleArrAtIndexPrint) {
    const std::string program = R"(
    double[] arr;

    append(arr, 1.5);
    append(arr, 2.75);
    append(arr, 3.125);

    print(arr[0]);
    print(arr[1]);
    print(arr[2]);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("1.5\n2.75\n3.125\n", testing::internal::GetCapturedStdout());
}

TEST(ArrayTests, BoolArrAtIndexPrint) {
    const std::string program = R"(
    bool[] arr;

    append(arr, true);
    append(arr, false);
    append(arr, true);

    print(arr[0]);
    print(arr[1]);
    print(arr[2]);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("true\nfalse\ntrue\n", testing::internal::GetCapturedStdout());
}

////////////////////////////////////////////////////////////////////////////////////
/// STRUCT
TEST(StructTests, StructDefEmpty) {
    const std::string program = R"(
    struct Test { };
    )";

    testing::internal::CaptureStdout();

    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(StructTests, StructDef) {
    const std::string program = R"(
    struct Test {
        int x;
    };
    )";

    testing::internal::CaptureStdout();

    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(StructTests, StructDefWithAnotherStruct) {
    const std::string program = R"(
    struct Inner { };

    struct Test {
        Inner inner;
    };
    )";

    testing::internal::CaptureStdout();

    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(StructTests, StructDefWithAllTypes) {
    const std::string program = R"(
    struct Inner { };

    struct Test {
        int x;
        double y;
        bool flag;
        char symbol;
        Inner parent;
        Inner[] children;
    };
    )";

    testing::internal::CaptureStdout();

    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(StructTests, StructDeclEmpty) {
    const std::string program = R"(
    struct Test { };

    Test t;
    )";

    testing::internal::CaptureStdout();

    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(StructTests, StructDecl) {
    const std::string program = R"(
    struct Test {
        int x;
    };

    Test t;
    t.x = 1;
    )";

    testing::internal::CaptureStdout();

    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(StructTests, StructDeclWithAnotherStruct) {
    const std::string program = R"(
    struct Inner {
        int x;
    };

    struct Test {
        Inner inner;
    };

    Test t;
    t.inner.x = 1;
    )";

    testing::internal::CaptureStdout();

    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

TEST(StructTests, StructDeclWithAllTypes) {
    const std::string program = R"(
    struct Inner {
        int x;
    };

    struct Test {
        int x;
        double y;
        bool flag;
        char symbol;
        Inner parent;
        Inner[] children;
    };

    Inner i;
    i.x = 239;

    Inner[] inners;
    append(inners, i);

    Test t;
    t.x = 1;
    t.y = 2.0;
    t.flag = true;
    t.symbol = 'a';
    t.parent = i;
    t.children = inners;
    )";

    testing::internal::CaptureStdout();

    InterpreteCode(program);

    ASSERT_EQ("", testing::internal::GetCapturedStdout());
}

////////////////////////////////////////////////////////////////////////////////////
/// WHILE
TEST(WhileLoopTests, SimpleIntCondition) {
    const std::string program = R"(
    int x = 5;
    while (x > 0) {
        print(x);
        x = x - 1;
    }
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("5\n4\n3\n2\n1", testing::internal::GetCapturedStdout());
}

TEST(WhileLoopTests, BoolCondition) {
    const std::string program = R"(
    bool flag = true;
    int count = 0;
    while (flag) {
        count = count + 1;
        if (count == 3) {
            flag = false;
        }
        print(count);
    }
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("1\n2\n3", testing::internal::GetCapturedStdout());
}

TEST(WhileLoopTests, ArrayModification) {
    const std::string program = R"(
    int[] arr;
    append(arr, 1);
    append(arr, 2);
    append(arr, 3);
    append(arr, 4);
    append(arr, 5);

    int i = 0;
    while (i < 5) {
        arr[i] = arr[i] * 2;
        print(arr[i]);
        i = i + 1;
    }
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("2\n4\n6\n8\n10", testing::internal::GetCapturedStdout());
}

TEST(WhileLoopTests, NestedWhileLoops) {
    const std::string program = R"(
    int i = 0;
    while (i < 3) {
        int j = 0;
        while (j < 2) {
            print(i, j);
            j = j + 1;
        }
        i = i + 1;
    }
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("0 0\n0 1\n1 0\n1 1\n2 0\n2 1", testing::internal::GetCapturedStdout());
}

TEST(WhileLoopTests, DoubleCondition) {
    const std::string program = R"(
    double x = 1.5;
    while (x > 0) {
        print(x);
        x = x - 0.5;
    }
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("1.5\n1.0\n0.5", testing::internal::GetCapturedStdout());
}

TEST(WhileLoopTests, StructCondition) {
    const std::string program = R"(
    struct Counter {
        int value;
    }

    Counter c;
    c.value = 3;
    while (c.value > 0) {
        print(c.value);
        c.value = c.value - 1;
    }
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("3\n2\n1", testing::internal::GetCapturedStdout());
}

TEST(WhileLoopTests, LogicalOperatorsInCondition) {
    const std::string program = R"(
    int x = 0;
    int y = 5;
    while (x < 3 && y > 0) {
        print(x, y);
        x = x + 1;
        y = y - 1;
    }
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("0 5\n1 4\n2 3", testing::internal::GetCapturedStdout());
}

TEST(WhileLoopTests, ModifyConditionInsideLoop) {
    const std::string program = R"(
    int x = 5;
    while (x > 0) {
        print(x);
        if (x == 3) {
            x = 0; // Прерываем цикл
        } else {
            x = x - 1;
        }
    }
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("5\n4\n3", testing::internal::GetCapturedStdout());
}

////////////////////////////////////////////////////////////////////////////////////
/// FUNCTION
TEST(FunctionTests, VoidEmpty) {
    const std::string program = R"(
    func void foo() { }

    foo();
    print(foo());
    )";

    testing::internal::CaptureStdout();

    InterpreteCode(program);

    ASSERT_EQ("42", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, VoidReturnNoParams) {
    const std::string program = R"(
    func void printHello() {
        print("Hello, World!");
    }

    printHello();
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("Hello, World!", testing::internal::GetCapturedStdout());
}


TEST(FunctionTests, IntReturnNoParams) {
    const std::string program = R"(
    func int getNumber() {
        return 42;
    }

    print(getNumber());
    )";

    testing::internal::CaptureStdout();

    InterpreteCode(program);

    ASSERT_EQ("42", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, CharReturnNoParams) {
    const std::string program = R"(
    func char getChar() {
        return 'A';
    }

    print(getChar());
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("A", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, DoubleReturnNoParams) {
    const std::string program = R"(
    func double getDouble() {
        return 3.14;
    }

    print(getDouble());
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("3.14", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, BoolReturnNoParams) {
    const std::string program = R"(
    func bool isTrue() {
        return true;
    }

    print(isTrue());
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("true", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, IntReturnWithIntParam) {
    const std::string program = R"(
    func int square(int x) {
        return x * x;
    }

    print(square(5));
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("25", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, DoubleReturnWithIntAndDoubleParams) {
    const std::string program = R"(
    func double multiply(int x, double y) {
        return x * y;
    }

    print(multiply(3, 2.5));
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("7.5", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, IntReturnWithIntArrayParam) {
    const std::string program = R"(
    func int first(int[] arr) {
        return arr[0];
    }

    int[] arr;
    append(arr, 1);
    append(arr, 2);
    append(arr, 3);

    print(first(arr));
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("1", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, BoolReturnWithMixedParams) {
    const std::string program = R"(
    func bool checkValues(int x, char c, bool b) {
        return x == 10 && c == 'X' && b == true;
    }

    print(checkValues(10, 'X', true));
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("true", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, MixedParamsIntCharBool) {
    const std::string program = R"(
    func int mixedParams(int x, char c, bool b) {
        if (b) {
            return x + c;
        } else {
            return x - c;
        }
    }

    print(mixedParams(10, 'A', true));
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("75", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, MixedParamsDoubleBoolInt) {
    const std::string program = R"(
    func double mixedParams(double x, bool b, int y) {
        if (b) {
            return x + y;
        } else {
            return x - y;
        }
    }

    print(mixedParams(3.14, true, 2));
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("5.14", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, StructWithArithmetic) {
    const std::string program = R"(
    struct Point {
        int x;
        int y;
    }

    func int sumCoordinates(Point p) {
        return p.x + p.y;
    }

    Point p;
    p.x = 3;
    p.y = 5;
    print(sumCoordinates(p));
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("8", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, ModifyStructInFunction) {
    const std::string program = R"(
    struct Point {
        int x;
        int y;
    }

    func void movePoint(Point p, int dx, int dy) {
        p.x += dx;
        p.y += dy;

        print(p.x);
        print(p.y);
    }

    Point p;
    p.x = 2;
    p.y = 3;
    movePoint(p, 1, 2);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("3\n5", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, ReturnStructFromFunction) {
    const std::string program = R"(
    struct Point {
        int x;
        int y;
    }

    func Point createPoint(int x, int y) {
        Point p;
        p.x = x;
        p.y = y;
        return p;
    }

    Point p = createPoint(10, 20);
    print(p.x);
    print(p.y);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("10\n20", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, ArrayOfStructs) {
    const std::string program = R"(
    struct Point {
        int x;
        int y;
    }

    func Point createPoint(int x, int y) {
        Point p;
        p.x = x;
        p.y = y;
        return p;
    }

    func int sumPoints(Point[] points, int size) {
        int sum = 0;
        int i = 0;

        while (i < size) {
            sum = sum + (points[i].x + points[i].y);
            i = i + 1;
        }

        return sum;
    }

    Point[] points;
    append(points, createPoint(1, 1));
    append(points, createPoint(2, 2));
    append(points, createPoint(3, 3));

    print(sumPoints(points, 3));
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("12", testing::internal::GetCapturedStdout());
}

TEST(FunctionTests, NestedStructs) {
    const std::string program = R"(
    struct Address {
        int houseNumber;
        char street;
    }

    struct Person {
        int id;
        Address addr;
    }

    func void printPerson(Person p) {
        print(p.id, p.addr.houseNumber, p.addr.street);
    }

    Person p;
    p.id = 1;
    p.addr.houseNumber = 123;
    p.addr.street = 'A';

    printPerson(p);
    )";

    testing::internal::CaptureStdout();
    InterpreteCode(program);

    ASSERT_EQ("1 123 A", testing::internal::GetCapturedStdout());
}
