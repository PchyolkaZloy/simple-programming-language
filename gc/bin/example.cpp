#include <iostream>
#include "gc.h"

void example_1() {
    // Base example
    auto a = gc::gc.createLeafObject<int>(1);
    auto b = a;

    gc::gc.showObjects();
}

void example_2() {
    // Struct example
    auto a = gc::gc.createStruct({"one", "two", "name"});
    a.object().set("one", gc::gc.createLeafObject(1));
    a.object().set("two", gc::gc.createLeafObject(true));
    {
        auto arr = gc::gc.createArray<gc::LeafObject<char>>(3);
        arr.object().set(0, gc::gc.createLeafObject('d'));
        arr.object().set(1, gc::gc.createLeafObject('b'));
        arr.object().set(2, gc::gc.createLeafObject('c'));
        arr.object().set(0, gc::gc.createLeafObject('a'));
        a.object().set("name", arr);
        gc::gc.showObjects();
    }
    gc::gc.collect();
    std::cout << a.object().get<gc::LeafObject<int>>("one").object().get() << " "
        << a.object().get<gc::LeafObject<bool>>("two").object().get() << " ";
    std::cout << a.object().get<gc::Array<gc::LeafObject<char>>>("name").object().get(0).get()
        << a.object().get<gc::Array<gc::LeafObject<char>>>("name").object().get(1).get()
        << a.object().get<gc::Array<gc::LeafObject<char>>>("name").object().get(2).get() << std::endl;

    gc::gc.showObjects();
}

void example_3() {
    // Array example
    auto a = gc::gc.createArray<gc::LeafObject<int>>(5);
    {
        auto i = gc::gc.createLeafObject(0);
        while (*i.object().get() < a.object().size()) {
            a.object().set(*i.object().get(), gc::gc.createLeafObject(i.object().get() + 1));
            i.object().set(i.object().get() + 1);
        }
    }
    gc::gc.showObjects();

    {
        auto i = gc::gc.createLeafObject(0);
        while (*i.object().get() < a.object().size()) {
            std::cout << a.object().get(*i.object().get()).get() << ", ";
            i.object().set(i.object().get() + 1);
        }
    }
    std::cout << std::endl;
    // 1, 2, 3, 4, 5

    a.object().set(0, gc::gc.createLeafObject(6));

    gc::gc.showObjects();
    gc::gc.collect();
    gc::gc.showObjects();
}

void example_4() {
    // String example
    std::string hello = "Hello, world!";

    auto a = gc::gc.createArray<gc::LeafObject<char>>(hello.length());
    {
        auto i = gc::gc.createLeafObject(0);
        while (*i.object().get() < hello.length()) {
            a.object().set(*i.object().get(), gc::gc.createLeafObject(hello[*i.object().get()]));
            i.object().set(i.object().get() + 1);
        }
    }
    gc::gc.showObjects();

    {
        auto i = gc::gc.createLeafObject(0);
        while (*i.object().get() < a.object().size()) {
            std::cout << a.object().get(*i.object().get()).get();
            i.object().set(i.object().get() + 1);
        }
    }
    std::cout << std::endl;
    // Hello, world!
}

void example_5() {
    {
        auto first = gc::gc.createStruct({"next"});
        gc::gc.showObjects();
        first.object().set("next", first);
        gc::gc.showObjects();
    }
    gc::gc.collect();
    gc::gc.showObjects();
    // delete cycle referencing
}

void example_6() {
    auto arr = gc::gc.createArray<gc::LeafObject<int>>(2);
    {
        auto one = gc::gc.createLeafObject(1);
        auto two = gc::gc.createLeafObject(2);
        gc::gc.showObjects();
        arr.object().set(0, one);
        arr.object().set(1, two);
        gc::gc.showObjects();
    }
    gc::gc.showObjects();
    {
        arr.object().set(0, gc::gc.createLeafObject(3));
    }
    gc::gc.showObjects();
    gc::gc.collect();
    gc::gc.showObjects();
}

void example_7() {
    // Example from chat
    for (int i = 0; i < 1000000; i++) {
        auto first = gc::gc.createStruct({"next"});
        auto second = gc::gc.createStruct({"next"});
        first.object().set("next", second);
        second.object().set("next", first);
        gc::gc.collect();
    }
    gc::gc.collect();
    gc::gc.showObjects();
}

int main() {
    std::cout << "Example 1:" << std::endl;
    example_1();
    std::cout << "Example 2:" << std::endl;
    example_2();
    std::cout << "Example 3:" << std::endl;
    example_3();
    std::cout << "Example 4:" << std::endl;
    example_4();
    std::cout << "Example 5:" << std::endl;
    example_5();
    std::cout << "Example 6:" << std::endl;
    example_6();
    std::cout << "Example 7:" << std::endl;
    example_7();

    return 0;
}
