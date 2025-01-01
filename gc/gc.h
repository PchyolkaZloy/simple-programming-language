#pragma once
#include <list>
#include <vector>
#include <unordered_map>

namespace gc {

class BaseObject {
public:
    BaseObject();
    BaseObject(BaseObject& obj);
    BaseObject& operator=(BaseObject& obj);
    ~BaseObject();

    void increment();
    void decrement();
    size_t counter();
private:
    size_t _counter{};
};

template<typename T>
class Ref {
public:
    Ref(T* obj = nullptr) : _object(obj) {
        if (_object) {
            _object->increment();
        }
    }

    Ref(gc::Ref<T>& obj) : _object(obj._object) {
        if (_object) {
            _object->increment();
        }
    }

    template<typename U>
    Ref(const Ref<U>& other) : _object(reinterpret_cast<T*>(&other.object())) {
        if (_object) {
            _object->increment();
        }
    }

    Ref& operator=(const Ref<T>& obj) {
        _object = obj._object;
        if (_object) {
            _object->increment();
        }

        return *this;
    }

    ~Ref() {
        if (_object) {
            _object->decrement();
        }
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
    LeafObject(const T& value = nullptr) : _value(value) {}

    LeafObject(LeafObject<T>& obj) : _value(obj.get()) {}

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
        for (size_t i = 0; i < _size; i++) {
            if (_is_present[i]) {
                _fields[i].object().decrement();
            }
        }
    }

    T get(size_t index) {
        return _fields[index].object();
    }

    void set(size_t index, Ref<T> ref) {
        if (_is_present[index]) {
            _fields[index].object().decrement();
        }

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
    Struct(const std::vector<std::string>& names);
    ~Struct();

    void set(const std::string& name, const Ref<BaseObject>& value);
    template<typename T>
    Ref<T> get(const std::string& name);
private:
    std::unordered_map<std::string, bool> _is_present;
    std::unordered_map<std::string, Ref<BaseObject>> _data;
};

class GarbageCollector {
public:
    GarbageCollector();
    ~GarbageCollector();

    template<typename T>
    Ref<LeafObject<T>> createLeafObject(const T& value);
    template<typename T>
    Ref<Array<T>> createArray(size_t size);
    Ref<Struct> createStruct(const std::vector<std::string>& names);
    void collect();

    //DEBUG
    void showObjects();
private:
    std::list<BaseObject*> _objects;
};

}
