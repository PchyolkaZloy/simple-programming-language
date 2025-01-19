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
    Ref(T* obj = nullptr, std::unordered_map<BaseObject*, std::unordered_map<BaseObject*, size_t >>* ref_data = nullptr, BaseObject* parent = nullptr)
        : _object(obj)
        , _ref_data(ref_data)
        , _parent(parent) {
        if (_ref_data == nullptr) {
            return;
        }
        if ((*_ref_data)[parent].contains(_object)) {
            (*_ref_data)[parent][_object]++;
        } else {
            (*_ref_data)[parent][_object] = 1;
        }
    }

    Ref(const gc::Ref<T>& obj)
        : _object(obj._object)
        , _ref_data(obj._ref_data)
        , _parent(obj._parent) {
        if (_ref_data == nullptr) {
            return;
        }
        if ((*_ref_data)[_parent].contains(_object)) {
            (*_ref_data)[_parent][_object]++;
        } else {
            (*_ref_data)[_parent][_object] = 1;
        }
    }

    Ref(const gc::Ref<T>&& obj)
        : _object(obj._object)
        , _ref_data(obj._ref_data)
        , _parent(obj._parent) {
        if (_ref_data == nullptr) {
            return;
        }
        if ((*_ref_data)[_parent].contains(_object)) {
            (*_ref_data)[_parent][_object]++;
        } else {
            (*_ref_data)[_parent][_object] = 1;
        }
    }

    template<typename U>
    Ref(const Ref<U>& other)
        : _object(reinterpret_cast<T*>(&other.object()))
        , _ref_data(other.scope())
        , _parent(other.parent()) {
        if (_ref_data == nullptr) {
            return;
        }
        if ((*_ref_data)[_parent].contains(_object)) {
            (*_ref_data)[_parent][_object]++;
        } else {
            (*_ref_data)[_parent][_object] = 1;
        }
    }

    template<typename U>
    Ref(const Ref<U>&& other)
        : _object(reinterpret_cast<T*>(&other.object()))
        , _ref_data(other.scope())
        , _parent(other.parent()) {
        if (_ref_data == nullptr) {
            return;
        }
        if ((*_ref_data)[_parent].contains(_object)) {
            (*_ref_data)[_parent][_object]++;
        } else {
            (*_ref_data)[_parent][_object] = 1;
        }
    }

    Ref& operator=(const Ref<T>& obj) {
        _object = obj._object;
        _ref_data = obj._ref_data;
        _parent = obj._parent;

        if ((*_ref_data)[_parent].contains(_object)) {
            (*_ref_data)[_parent][_object]++;
        } else {
            (*_ref_data)[_parent][_object] = 1;
        }

        return *this;
    }

    ~Ref() {
        if (_ref_data == nullptr) {
            return;
        }
        if ((*_ref_data)[_parent].contains(_object)) {
            (*_ref_data)[_parent][_object]--;
        }
    }

    T& object() const {
        return *_object;
    }

    std::unordered_map<BaseObject*, std::unordered_map<BaseObject*, size_t >>* scope() const {
        return _ref_data;
    }

    BaseObject* parent() const {
        return _parent;
    }

    void setParent(BaseObject* parent) {
        if (_ref_data == nullptr) {
            return;
        }
        if ((*_ref_data)[_parent].contains(_object)) {
            (*_ref_data)[_parent][_object]--;
        }
        _parent = parent;
        if ((*_ref_data)[_parent].contains(_object)) {
            (*_ref_data)[_parent][_object]++;
        } else {
            (*_ref_data)[_parent][_object] = 1;
        }
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

    bool operator==(const Ref<T>& other) const {
        return this->_object == other._object;
    }

    struct HashFunction
    {
        size_t operator()(const Ref<T>& obj) const
        {
            // TODO: better hash function, now there is many collisions
            size_t hash_object = std::hash<T*>()(obj._object);
            size_t hash_parent = std::hash<BaseObject*>()(obj._parent);

            return hash_object ^ (hash_parent << 1);
        }
    };

    BaseObject* _parent = nullptr;
    T* _object = nullptr;
    std::unordered_map<BaseObject*, std::unordered_map<BaseObject*, size_t >>* _ref_data;
};

class BaseObject {
public:
    virtual std::unordered_set<Ref<BaseObject>, Ref<BaseObject>::HashFunction> getChildren() = 0;
    virtual ~BaseObject() = default;

    bool operator==(const BaseObject& other) const {
        return this == &other;
    }
};

class RootObject : public BaseObject {
public:
    std::unordered_set<Ref<BaseObject>, Ref<BaseObject>::HashFunction> getChildren() {
        return {};
    };
};

class GarbageCollector {
public:
    GarbageCollector(bool verbose = false);
    ~GarbageCollector();

    template<typename T>
    Ref<T> create(T* obj) {
        _objects.insert(obj);
        ++_statistic;

        return Ref<T>(obj, _ref_data, _root);
    }

    template<typename T>
    Ref<T> create(T obj) {
        _objects.insert(&obj);
        ++_statistic;

        return Ref<T>(obj, _ref_data, _root);
    }

    void collect();

    //DEBUG
    void showObjects();
private:
    void mark(BaseObject* obj);
    void sweep();

    size_t _statistic = 0;
    /*
     * magic constant X
     * when X object was allocated then perform collect
     * now like in python 700
     */
    const size_t _limit = 700;

    bool _verbose = false;
    BaseObject* _root = new RootObject();
    std::unordered_map<BaseObject*, std::unordered_map<BaseObject*, size_t >>* _ref_data =
            new std::unordered_map<BaseObject*, std::unordered_map<BaseObject*, size_t >>();
    std::unordered_set<BaseObject*> _marked;
    std::unordered_set<BaseObject*> _objects;
};

extern GarbageCollector gc;

}
