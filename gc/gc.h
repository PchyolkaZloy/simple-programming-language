#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

namespace gc {

class BaseObject;

template<typename T>
class Ref {
public:
    Ref(std::unordered_set<BaseObject*>* root = nullptr, T* obj = nullptr)
        : _object(obj)
        , _root(root) {
        if (_root != nullptr && _root->find(_object) == _root->end()) {
            _root->insert(_object);
            _is_rooted = true;
        }
    }

    Ref(const gc::Ref<T>& obj)
        : _object(obj._object)
        , _root(obj._root) {
        if (_root != nullptr && _root->find(_object) == _root->end()) {
            _root->insert(_object);
            _is_rooted = true;
        }
    }

    template<typename U>
    Ref(const Ref<U>& other)
        : _object(reinterpret_cast<T*>(&other.object()))
        , _root(other.scope()) {
        if (_root != nullptr && _root->find(_object) == _root->end()) {
            _root->insert(_object);
            _is_rooted = true;
        }
    }

    Ref& operator=(const Ref<T>& obj) {
        _object = obj._object;
        _root = obj._root;
        if (_root != nullptr && _root->find(_object) == _root->end()) {
            _root->insert(_object);
            _is_rooted = true;
        }

        return *this;
    }

    ~Ref() {
        if (_root != nullptr && _is_rooted) {
            _root->erase(_object);
        }
    }

    T& object() const {
        return *_object;
    }

    std::unordered_set<BaseObject*>* scope() const {
        return _root;
    }
private:
    T* _object = nullptr;
    bool _is_rooted = false;
    std::unordered_set<BaseObject*>* _root;
};

class BaseObject {
public:
    virtual std::vector<Ref<BaseObject>> getChildren();
};

template<typename T>
class LeafObject : public BaseObject {
public:
    LeafObject(const T& value = nullptr) : _value(value) {}

    LeafObject(LeafObject<T>& obj) : _value(obj.get()) {}

    T get() {
        return _value;
    }

    void set(T value) {
        _value = value;
    }

    std::vector<Ref<BaseObject>> getChildren() override {
        return {};
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

    T get(size_t index) {
        return _fields[index].object();
    }

    void set(size_t index, Ref<T> ref) {
        _fields[index] = ref;
        _is_present[index] = true;
    }

    size_t size() {
        return _size;
    }

    std::vector<Ref<BaseObject>> getChildren() override {
        std::vector<Ref<BaseObject>> result;
        for (const auto& field : _fields) {
            result.push_back(static_cast<Ref<BaseObject>>(field));
        }

        return result;
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

    void set(const std::string& name, const Ref<BaseObject>& value);
    template<typename T>
    Ref<T> get(const std::string& name);
    std::vector<Ref<BaseObject>> getChildren() override;
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
    void mark(BaseObject& obj);
    void sweep();

    std::unordered_set<BaseObject*> _root;
    std::unordered_set<BaseObject*> _marked;
    std::unordered_set<BaseObject*> _objects;
};

}
