#include "vm.h"

#include <boost/multiprecision/cpp_int.hpp>

#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

using cpp_int = boost::multiprecision::cpp_int;

void LoadInt(std::ofstream& f, const cpp_int& exported) {
    f << static_cast<char>(ByteCodes::LoadInt);
    std::string v;
    boost::multiprecision::export_bits(exported, std::back_inserter(v), 7);
    int len = v.size();
    if (exported < 0) {
        len = -len;
    }
    f.write(reinterpret_cast<char*>(&len), 4);
    f.write(v.c_str(), v.size());
}

void LoadString(std::ofstream& f, std::string_view s) {
    f << static_cast<char>(ByteCodes::LoadString);
    int len = s.size();
    f.write(reinterpret_cast<char*>(&len), 4);
    f << s;
}

void LoadDouble(std::ofstream& f, double d) {
    f << static_cast<char>(ByteCodes::LoadDouble);
    f.write(reinterpret_cast<char*>(&d), 8);
}

void LoadChar(std::ofstream& f, char c) {
    f << static_cast<char>(ByteCodes::LoadChar);
    f.write(&c, 1);
}

// int a = 123;
void Example0(std::ofstream& f) {
    cpp_int a = 123;
    LoadInt(f, a);
    LoadString(f, "a");
    f << static_cast<char>(ByteCodes::StoreName);
}

/*
int a = 3;
int b = 7;
int c = a + b;
*/
void Example1(std::ofstream& f) {
    cpp_int a = 3;
    cpp_int b = 7;
    // store a = 3
    LoadInt(f, a);
    LoadString(f, "a");
    f << static_cast<char>(ByteCodes::StoreName);
    // store b = 7
    LoadInt(f, b);
    LoadString(f, "b");
    f << static_cast<char>(ByteCodes::StoreName);
    // load 3, 7 onto the stack
    LoadString(f, "a");
    f << static_cast<char>(ByteCodes::LoadName);
    LoadString(f, "b");
    f << static_cast<char>(ByteCodes::LoadName);
    // compute a + b
    f << static_cast<char>(ByteCodes::BinaryOp);
    f << static_cast<char>(BinaryOps::Add);
    // store to c
    LoadString(f, "c");
    f << static_cast<char>(ByteCodes::StoreName);
}

/*
(тут ! это не оператор и такое не должно компилироваться. Это простой пример для проверки что работает длинная арифметика)
int xyz = 100!;
Print(xyz);
*/
void Example2(std::ofstream& f) {
    cpp_int xyz = -1;
    for (int i = 1; i <= 100; ++i) {
        xyz *= i;
    }

    cout << xyz;

    LoadInt(f, xyz);
    LoadString(f, "xyz");
    f << static_cast<char>(ByteCodes::StoreName);

    LoadString(f, "xyz");
    f << static_cast<char>(ByteCodes::LoadName);

    // on stack 100!
    LoadString(f, "Print");
    f << static_cast<char>(ByteCodes::Call);
}

/*
int a = 3;
while (a > 0) {
    Print(a);
    a = a - 1;
}
*/
void Example3(std::ofstream& f) {
    int offset = 0;
    LoadInt(f, 3);
    LoadString(f, "a");
    f << static_cast<char>(ByteCodes::StoreName);

    // a > 0
    LoadString(f, "a");                          // -15
    f << static_cast<char>(ByteCodes::LoadName); // -14
    LoadInt(f, 0);                               // -13
    f << static_cast<char>(ByteCodes::BinaryOp); // -12
    f << static_cast<char>(BinaryOps::Gr);

    offset = 12;
    // после каждой строки с операцией написано сколько нужно прыгнуть,
    // чтобы попасть на эту операцию в формате `<offset для JumpIfFalse> ; <offset для Jump>`
    f << static_cast<char>(ByteCodes::JumpIfFalse); // 0 ; -11
    f.write(reinterpret_cast<char*>(&offset), 4);

    // while body
    //// Print(a)
    LoadString(f, "a");                          // 1 ; -10
    f << static_cast<char>(ByteCodes::LoadName); // 2 ; -9
    LoadString(f, "Print");                      // 3 ; -8
    f << static_cast<char>(ByteCodes::Call);     // 4 ; -7
    //// a = a - 1
    LoadString(f, "a");                          // 5 ; -6
    f << static_cast<char>(ByteCodes::LoadName); // 6 ; -5
    LoadInt(f, 1);                               // 7 ; -4
    f << static_cast<char>(ByteCodes::BinaryOp); // 8 ; -3
    f << static_cast<char>(BinaryOps::Sub);
    LoadString(f, "a");                           // 9 ; -2
    f << static_cast<char>(ByteCodes::StoreName); // 10 ; -1
    // jump to
    f << static_cast<char>(ByteCodes::Jump); // 11 ; 0
    offset = -15;
    f.write(reinterpret_cast<char*>(&offset), 4);
}

/*
def function_name(int a, int b) {
    Print(a);
    Print(b);
    return 1;
}

int a = 213;
int b = 5678;
int c = function_name(a, b);
*/
void Example4(std::ofstream& f) {
    // создание функции
    LoadString(f, "a");
    LoadString(f, "b");
    LoadString(f, "function_name");
    f << static_cast<char>(ByteCodes::MakeFunction);
    uint8_t argc = 2;
    f.write(reinterpret_cast<char*>(&argc), 1);
    // тело функции
    LoadString(f, "a");
    f << static_cast<char>(ByteCodes::LoadName);
    LoadString(f, "b");
    f << static_cast<char>(ByteCodes::LoadName);
    LoadString(f, "Print");
    f << static_cast<char>(ByteCodes::Call);
    LoadInt(f, 1);
    f << static_cast<char>(ByteCodes::Return);
    f << static_cast<char>(ByteCodes::NullOp); // признак окончания тела функции

    // тело программы
    LoadInt(f, 213);
    LoadString(f, "a");
    f << static_cast<char>(ByteCodes::StoreName);

    LoadInt(f, 5678);
    LoadString(f, "b");
    f << static_cast<char>(ByteCodes::StoreName);

    LoadString(f, "a");
    f << static_cast<char>(ByteCodes::LoadName);
    LoadString(f, "b");
    f << static_cast<char>(ByteCodes::LoadName);
    LoadString(f, "function_name");
    f << static_cast<char>(ByteCodes::Call);
    // return value функции появится на стеке вызывающей стороны если функция что-то возвращает
    LoadString(f, "c");
    f << static_cast<char>(ByteCodes::StoreName);
}

/*
struct MyStruct {
    int x;
    double y;
};

func MyStruct f() {
    MyStruct str;
    str.x = 124;
    str.y = 23.51;
    return str;
}

MyStruct ghj = f();
*/

void Example5(std::ofstream& f) {
    // объявление структуры
    LoadString(f, "x");
    LoadString(f, "MyStruct");
    f << static_cast<char>(ByteCodes::DefineStruct);
    uint8_t fieldc = 2;
    f.write(reinterpret_cast<char*>(&fieldc), 1);

    // объявление функции
    LoadString(f, "f");
    f << static_cast<char>(ByteCodes::MakeFunction);
    uint8_t argc = 0;
    f.write(reinterpret_cast<char*>(&argc), 1);
    // тело функции
    //// MyStruct str;
    LoadString(f, "MyStruct");
    f << static_cast<char>(ByteCodes::BuildStruct);
    LoadString(f, "str");
    f << static_cast<char>(ByteCodes::StoreName);
    //// str.x = 124;
    LoadInt(f, 124);
    LoadString(f, "x");
    LoadString(f, "str");
    f << static_cast<char>(ByteCodes::LoadName);
    f << static_cast<char>(ByteCodes::StoreMember);
    //// str.y = 23.51;
    LoadDouble(f, 23.51);
    LoadString(f, "y");
    LoadString(f, "str");
    f << static_cast<char>(ByteCodes::LoadName);
    f << static_cast<char>(ByteCodes::StoreMember);
    //// return str;
    LoadString(f, "str");
    f << static_cast<char>(ByteCodes::LoadName);
    f << static_cast<char>(ByteCodes::Return);

    f << static_cast<char>(ByteCodes::NullOp); // признак окончания тела функции

    // MyStruct ghj = f();
    LoadString(f, "f");
    f << static_cast<char>(ByteCodes::Call);
    LoadString(f, "ghj");
    f << static_cast<char>(ByteCodes::StoreName);
}

/*
char[] str = {'a', 'b', 'b'};
str[2] = 'c';
Append(str, 'd');
Print(str);
*/

void Example6(std::ofstream& f) {
    // char[] str = {'a', 'b', 'b'};
    LoadChar(f, 'a');
    LoadChar(f, 'b');
    LoadChar(f, 'b');
    f << static_cast<char>(ByteCodes::BuildArray);
    int cnt = 3;
    f.write(reinterpret_cast<char*>(&cnt), 4);
    // str[2] = 'c';
    LoadChar(f, 'c');
    LoadInt(f, 2);
    LoadString(f, "str");
    f << static_cast<char>(ByteCodes::LoadName);
    f << static_cast<char>(ByteCodes::StoreSubscr);
    // Append(str, 'd');
    LoadString(f, "str");
    f << static_cast<char>(ByteCodes::LoadName);
    LoadChar(f, 'd');
    LoadString(f, "Append");
    f << static_cast<char>(ByteCodes::Call);
    // Print(str);
    LoadString(f, "str");
    f << static_cast<char>(ByteCodes::LoadName);
    LoadString(f, "Print");
    f << static_cast<char>(ByteCodes::Call);
}

int main() {
    ofstream f("basic_test.spl", std::ios::binary);
    Example2(f);
    return 0;
}
