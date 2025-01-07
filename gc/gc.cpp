#include <iostream>
#include <list>
#include <vector>
#include "gc.h"


std::vector<gc::Ref<gc::BaseObject>> gc::BaseObject::getChildren() {
    return {};
}

gc::Struct::Struct(const std::vector<std::string>& names) {
    for (const std::string& name : names) {
        _data[name] = gc::Ref<LeafObject<int>>();
        _is_present[name] = false;
    }
}

void gc::Struct::set(const std::string& name, const Ref<BaseObject>& value) {
    _data[name] = value;
    _is_present[name] = true;
}

template<typename T>
gc::Ref<T> gc::Struct::get(const std::string& name) {
    return *reinterpret_cast<Ref<T>*>(&_data[name]);
}

std::vector<gc::Ref<gc::BaseObject>> gc::Struct::getChildren() {
    std::vector<gc::Ref<gc::BaseObject>> keys;
    for (auto it : _data) {
        if (_is_present[it.first]) {
            keys.push_back(it.second);
        }
    }

    return keys;
}

gc::GarbageCollector::GarbageCollector() = default;

gc::GarbageCollector::~GarbageCollector() {
    for (BaseObject* obj : _root) {
        delete obj;
    }
}

template<typename T>
gc::Ref<gc::LeafObject<T>> gc::GarbageCollector::createLeafObject(const T& value) {
    auto obj = new LeafObject<T>(value);
    _objects.insert(obj);

    return gc::Ref(&_root, obj);
}

template<typename T>
gc::Ref<gc::Array<T>> gc::GarbageCollector::createArray(size_t size) {
    auto obj = new gc::Array<T>(size);
    _objects.insert(obj);

    return gc::Ref(&_root, obj);
}

gc::Ref<gc::Struct> gc::GarbageCollector::createStruct(const std::vector<std::string>& names) {
    auto obj = new gc::Struct(names);
    _objects.insert(obj);

    return gc::Ref(&_root, obj);
}

void gc::GarbageCollector::collect() {
    _marked.clear();
    for (auto obj : _root) {
        mark(*obj);
    }
    sweep();
}

void gc::GarbageCollector::mark(gc::BaseObject& obj) {
    if (_marked.find(&obj) != _marked.end()) {
        return;
    }

    _marked.insert(&obj);

    for (const auto& child : obj.getChildren()) {
        mark(child.object());
    }
}

void gc::GarbageCollector::sweep() {
    for (auto it = _objects.begin(); it != _objects.end();) {
        if (_marked.find(*it) == _marked.end()) {
            delete *it;
            it = _objects.erase(it);
        } else {
            it++;
        }
    }
}

void gc::GarbageCollector::showObjects() {
    std::cout << "Objects in gc, root\n";
    std::cout << _objects.size() << " " << _root.size() << "\n";
    std::cout << "-------------" << std::endl;
}
