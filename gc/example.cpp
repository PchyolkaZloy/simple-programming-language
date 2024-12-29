#include <iostream>
#include "gc.cpp"

void example_1() {
    // Base example
    GarbageCollector gc;

    auto a = gc.createLeafObject<int>(1);
    auto b = a;

    gc.showObjects();
}

void example_2() {
    // Struct example

    GarbageCollector gc;

    auto a = gc.createStruct({"one", "two", "name"});
    a.object().set("one", gc.createLeafObject(1));
    a.object().set("two", gc.createLeafObject(true));
    {
        auto arr = gc.createArray<LeafObject<char>>(3);
        arr.object().set(0, gc.createLeafObject('d'));
        arr.object().set(1, gc.createLeafObject('b'));
        arr.object().set(2, gc.createLeafObject('c'));
        arr.object().set(0, gc.createLeafObject('a'));
        a.object().set("name", arr);
        gc.showObjects();
    }
    gc.collect();
    std::cout << a.object().get<LeafObject<int>>("one").object().value() << " "
        << a.object().get<LeafObject<bool>>("two").object().value() << " ";
    std::cout << a.object().get<Array<LeafObject<char>>>("name").object().get(0).value()
        << a.object().get<Array<LeafObject<char>>>("name").object().get(1).value()
        << a.object().get<Array<LeafObject<char>>>("name").object().get(2).value() << std::endl;

    gc.showObjects();
}

void example_3() {
    // Array example

    GarbageCollector gc;

    auto a = gc.createArray<LeafObject<int>>(5);
    for (int i = 0; i < 5; i++)
        a.object().set(i, gc.createLeafObject(i + 1));
    gc.showObjects();

    for (int i = 0; i < 5; i++)
        std::cout << a.object().get(i).value() << ", ";
    std::cout << std::endl;
    // 1, 2, 3, 4, 5

    a.object().set(0, gc.createLeafObject(6));

    gc.showObjects();
    gc.collect();
    gc.showObjects();
}

void example_4() {
    // String example

    GarbageCollector gc;

    std::string hello = "Hello, world!";

    auto a = gc.createArray<LeafObject<char>>(hello.length());
    for (int i = 0; i < hello.length(); i++)
        a.object().set(i, gc.createLeafObject(hello[i]));
    gc.showObjects();

    for (int i = 0; i < a.object().size(); i++)
        std::cout << a.object().get(i).value();
    std::cout << std::endl;
    // Hello, world!
}

void example_5() {
    GarbageCollector gc;

    {
        auto first = gc.createStruct({"next"});
        gc.showObjects();
        first.object().set("next", first);
        gc.showObjects();
    }
    gc.collect();
    gc.showObjects();
    // don't change anything, memory leak
}

int main() {
    std::cout << "Example 1:";
    example_1();
    std::cout << "Example 2:";
    example_2();
    std::cout << "Example 3:";
    example_3();
    std::cout << "Example 4:";
    example_4();
    std::cout << "Example 5:";
    example_5();

    return 0;
}
