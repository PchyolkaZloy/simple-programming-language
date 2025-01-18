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
        if (_root != nullptr && _object != nullptr && _root->find(_object) == _root->end()) {
            _root->insert(_object);
            _is_rooted = true;
        }
    }

    Ref(const gc::Ref<T>& obj)
        : _object(obj._object)
        , _root(obj._root) {
        if (_root != nullptr && _object != nullptr && _root->find(_object) == _root->end()) {
            _root->insert(_object);
            _is_rooted = true;
        }
    }

    template<typename U>
    Ref(const Ref<U>& other)
        : _object(reinterpret_cast<T*>(&other.object()))
        , _root(other.scope()) {
        if (_root != nullptr && _object != nullptr && _root->find(_object) == _root->end()) {
            _root->insert(_object);
            _is_rooted = true;
        }
    }

    Ref& operator=(const Ref<T>& obj) {
        _object = obj._object;
        _root = obj._root;
        if (_root != nullptr && _object != nullptr && _root->find(_object) == _root->end()) {
            _root->insert(_object);
            _is_rooted = true;
        }

        return *this;
    }

    ~Ref() {
        if (_root != nullptr && _is_rooted && _object != nullptr) {
            _root->erase(_object);
        }
    }

    T& object() const {
        return *_object;
    }

    std::unordered_set<BaseObject*>* scope() const {
        return _root;
    }

    operator bool() const {
        return _object;
    }

    T& operator*() const {
        return *_object;
    }

    T* operator->() const {
        return _object;
    }

    T* _object = nullptr;
    bool _is_rooted = false;
    std::unordered_set<BaseObject*>* _root;
};

class BaseObject {
public:
    virtual std::vector<Ref<BaseObject>> getChildren() = 0;
};

class GarbageCollector {
public:
    GarbageCollector();
    ~GarbageCollector();

    template<typename T>
    Ref<T> create(T* obj) {
        _objects.insert(reinterpret_cast<BaseObject*>(obj));

        return Ref<T>(_root, obj);
    }

    void collect();

    //DEBUG
    void showObjects();
private:
    void mark(BaseObject* obj);
    void sweep();

    std::unordered_set<BaseObject*>* _root = new std::unordered_set<BaseObject*>({});
    std::unordered_set<BaseObject*> _marked;
    std::unordered_set<BaseObject*> _objects;
};

extern GarbageCollector gc;

}
