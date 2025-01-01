#include <iostream>
#include "gc.cpp"

void example_1() {
    // Base example
    gc::GarbageCollector gc;

    auto a = gc.createLeafObject<int>(1);
    auto b = a;

    gc.showObjects();
}

void example_2() {
    // Struct example
    gc::GarbageCollector gc;

    auto a = gc.createStruct({"one", "two", "name"});
    a.object().set("one", gc.createLeafObject(1));
    a.object().set("two", gc.createLeafObject(true));
    {
        auto arr = gc.createArray<gc::LeafObject<char>>(3);
        arr.object().set(0, gc.createLeafObject('d'));
        arr.object().set(1, gc.createLeafObject('b'));
        arr.object().set(2, gc.createLeafObject('c'));
        arr.object().set(0, gc.createLeafObject('a'));
        a.object().set("name", arr);
        gc.showObjects();
    }
    gc.collect();
    std::cout << a.object().get<gc::LeafObject<int>>("one").object().get() << " "
        << a.object().get<gc::LeafObject<bool>>("two").object().get() << " ";
    std::cout << a.object().get<gc::Array<gc::LeafObject<char>>>("name").object().get(0).get()
        << a.object().get<gc::Array<gc::LeafObject<char>>>("name").object().get(1).get()
        << a.object().get<gc::Array<gc::LeafObject<char>>>("name").object().get(2).get() << std::endl;

    gc.showObjects();
}

void example_3() {
    // Array example
    gc::GarbageCollector gc;

    auto a = gc.createArray<gc::LeafObject<int>>(5);
    {
        auto i = gc.createLeafObject(0);
        while (i.object().get() < a.object().size()) {
            a.object().set(i.object().get(), gc.createLeafObject(i.object().get() + 1));
            i.object().set(i.object().get() + 1);
        }
    }
    gc.showObjects();

    {
        auto i = gc.createLeafObject(0);
        while (i.object().get() < a.object().size()) {
            std::cout << a.object().get(i.object().get()).get() << ", ";
            i.object().set(i.object().get() + 1);
        }
    }
    std::cout << std::endl;
    // 1, 2, 3, 4, 5

    a.object().set(0, gc.createLeafObject(6));

    gc.showObjects();
    gc.collect();
    gc.showObjects();
}

void example_4() {
    // String example
    gc::GarbageCollector gc;

    std::string hello = "Hello, world!";

    auto a = gc.createArray<gc::LeafObject<char>>(hello.length());
    {
        auto i = gc.createLeafObject(0);
        while (i.object().get() < hello.length()) {
            a.object().set(i.object().get(), gc.createLeafObject(hello[i.object().get()]));
            i.object().set(i.object().get() + 1);
        }
    }
    gc.showObjects();

    {
        auto i = gc.createLeafObject(0);
        while (i.object().get() < a.object().size()) {
            std::cout << a.object().get(i.object().get()).get();
            i.object().set(i.object().get() + 1);
        }
    }
    std::cout << std::endl;
    // Hello, world!
}

void example_5() {
    gc::GarbageCollector gc;

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

void example_6() {
    gc::GarbageCollector gc;

    auto arr = gc.createArray<gc::LeafObject<int>>(2);
    {
        auto one = gc.createLeafObject(1);
        auto two = gc.createLeafObject(2);
        gc.showObjects();
        arr.object().set(0, one);
        arr.object().set(1, two);
        gc.showObjects();
    }
    gc.showObjects();
    {
        arr.object().set(0, gc.createLeafObject(3));
    }
    gc.showObjects();
    gc.collect();
    gc.showObjects();
}

int main() {
    std::cout << "Example 1:\n";
    example_1();
    std::cout << "Example 2:\n";
    example_2();
    std::cout << "Example 3:\n";
    example_3();
    std::cout << "Example 4:\n";
    example_4();
    std::cout << "Example 5:\n";
    example_5();
    std::cout << "Example 6:\n";
    example_6();

    return 0;
}
