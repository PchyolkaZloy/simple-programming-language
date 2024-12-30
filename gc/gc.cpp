#include <iostream>
#include <list>
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
    Ref(const Ref<U>& other) : _object(reinterpret_cast<T*>(&other.object())) {
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
private:
    T* _object;
};

template<typename T>
class LeafObject : public BaseObject {
public:
    LeafObject(const T& value = NULL) : _value(value) { }

    LeafObject(LeafObject<T>& obj) : _value(obj.get()) { }

    ~LeafObject() {
        decrement();
    }

    T get() {
        return _value;
    }

    void set(T value) {
        _value = value;
    }
private:
    T _value;
};

template<typename T>
class Array : public BaseObject {
public:
    Array(size_t size)
        : _size(size)
        , _fields(size)
        , _is_present(size, false) {}

    ~Array() {
        for (size_t i = 0; i < _size; i++)
            if (_is_present[i])
                _fields[i].object().decrement();
    }

    T get(size_t index) {
        return _fields[index].object();
    }

    void set(size_t index, Ref<T> ref) {
        if (_is_present[index])
            _fields[index].object().decrement();

        _fields[index] = ref;
        _is_present[index] = true;
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
    std::vector<bool> _is_present;
};

class Struct : public BaseObject {
public:
    Struct(const std::vector<std::string>& names) {
        for (const std::string& name : names) {
            _data[name] = Ref<LeafObject<int>>();
            _is_present[name] = false;
        }
    }

    ~Struct() {
        for (auto& it : _is_present)
            if (it.second)
                _data[it.first].object().decrement();
    }

    void set(const std::string& name, const Ref<BaseObject>& value) {
        if (_is_present[name])
            _data[name].object().decrement();

        _data[name] = value;
        _is_present[name] = true;
    }

    template<typename T>
    Ref<T> get(const std::string& name) {
        return *reinterpret_cast<Ref<T>*>(&_data[name]);
    }
private:
    std::unordered_map<std::string, bool> _is_present;
    std::unordered_map<std::string, Ref<BaseObject>> _data;
};

class GarbageCollector {
public:
    GarbageCollector() : _objects() {}

    ~GarbageCollector() {
        for (BaseObject* obj : _objects)
            delete obj;
    }

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
