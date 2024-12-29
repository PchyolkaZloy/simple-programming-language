#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <unordered_map>

class BaseObject {
public:
    BaseObject() {
        _counter = 0;
    }

    void increment() {
        _counter++;
    }

    void decrement() {
        _counter--;
    }

    size_t counter() {
        return _counter;
    }

    BaseObject(BaseObject& obj) {
        obj.increment();
    }

    BaseObject& operator=(BaseObject& obj) {
        obj.increment();

        return *this;
    }

    ~BaseObject() {
        decrement();
    }
private:
    size_t _counter{};
};

template<typename T>
class Ref {
public:
    Ref() : _object(nullptr) {}

    Ref(T* obj) : _object(obj) {
        if (_object)
            _object->increment();
    }

    Ref(Ref<T>& obj) : _object(obj._object) {
        if (_object)
            _object->increment();
    }

    template<typename U>
    Ref(const Ref<U>& other) : _object(dynamic_cast<T*>(other.get())) {
        if (_object)
            _object->increment();
    }

    Ref& operator=(const Ref<T>& obj) {
        _object = obj._object;
        if (_object)
            _object->increment();

        return *this;
    }

    ~Ref() {
        if (_object)
            _object->decrement();
    }

    T& object() const {
        return *_object;
    }

    T* get() const {
        return _object;
    }
private:
    T* _object;
};

template<typename T>
class LeafObject : public BaseObject {
public:
    LeafObject(const T& value = NULL) : _value(value) { }

    LeafObject(LeafObject<T>& obj) : _value(obj.value()) { }

    T value() {
        return _value;
    }
private:
    T _value;
};

template<typename T>
class Array : public BaseObject {
public:
    Array(size_t size)
        : _size(size)
        , _fields(size) {}

    ~Array() {
        for (size_t i = 0; i < _size; i++)
            _fields[i].object().decrement();
    }

    T get(size_t index) {
        return _fields[index].object();
    }

    void set(size_t index, Ref<T> ref) {
        if (_fields[index].get() != nullptr)
            _fields[index].object().decrement();

        _fields[index] = ref;
    }

    size_t size() {
        return _size;
    }

    //DEBUG
    void showArray() {
        std::cout << "Objects in Array\n";
        for (size_t i = 0; i < _size; i++) {
            std::cout << i << " " << _fields[i]->counter() << std::endl;
        }
        std::cout << "-------------\n";
    }
private:
    size_t _size;
    std::vector<Ref<T>> _fields;
};

class Struct : public BaseObject {
public:
    Struct(const std::vector<std::string>& names) {
        for (const std::string& name : names) {
            _data[name] = nullptr;
            _is_present[name] = false;
        }
    }

    ~Struct() {
        for (auto& it : _is_present)
            if (it.second)
                _data[it.first].object().decrement();
    }

    void set(const std::string& name, const Ref<BaseObject>& value) {
        if (_data[name].get() != nullptr)
            _data[name].object().decrement();

        _data[name] = value;
    }

    template<typename T>
    Ref<T> get(const std::string& name) {
        return Ref<T>(reinterpret_cast<T*>(_data[name].get()));
    }
private:
    std::unordered_map<std::string, bool> _is_present;
    std::unordered_map<std::string, Ref<BaseObject>> _data;
};

class GarbageCollector {
public:
    GarbageCollector() : _objects() {}

    template<typename T>
    Ref<LeafObject<T>> createLeafObject(const T& value) {
        auto obj = new LeafObject<T>(value);
        _objects.push_back(obj);

        return Ref(obj);
    }

    template<typename T>
    Ref<Array<T>> createArray(size_t size) {
        auto obj = new Array<T>(size);
        _objects.push_back(obj);

        return Ref(obj);
    }

    Ref<Struct> createStruct(const std::vector<std::string>& names) {
        auto obj = new Struct(names);
        _objects.push_back(obj);

        return Ref(obj);
    }

    void collect() {
        auto it = _objects.begin();
        while (it != _objects.end()) {
            BaseObject* obj = *it;
            if (obj->counter() == 0) {
                it = _objects.erase(it);
            } else {
                it++;
            }
        }
    }

    //DEBUG
    void showObjects() {
        std::cout << "Objects in GC\n";
        for (BaseObject* obj : _objects) {
            std::cout << obj << " " << obj->counter() << std::endl;
        }
        std::cout << "-------------\n";
    }
private:
    std::list<BaseObject*> _objects;
};

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
    // gc.createRef - for all fundamental types, such as int, long, char,
    // gc.createArray - for arrays, structures
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