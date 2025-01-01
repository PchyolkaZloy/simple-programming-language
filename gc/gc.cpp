#include <iostream>
#include <list>
#include <vector>
#include "gc.h"


gc::BaseObject::BaseObject() {
    _counter = 0;
}

void gc::BaseObject::increment() {
    _counter++;
}

void gc::BaseObject::decrement() {
    _counter--;
}

size_t gc::BaseObject::counter() {
    return _counter;
}

gc::BaseObject::BaseObject(BaseObject& obj) {
    obj.increment();
}

gc::BaseObject& gc::BaseObject::operator=(gc::BaseObject& obj) {
    obj.increment();

    return *this;
}

gc::BaseObject::~BaseObject() {
    decrement();
}

gc::Struct::Struct(const std::vector<std::string>& names) {
    for (const std::string& name : names) {
        _data[name] = gc::Ref<LeafObject<int>>();
        _is_present[name] = false;
    }
}

gc::Struct::~Struct() {
    for (auto& it : _is_present) {
        if (it.second) {
            _data[it.first].object().decrement();
        }
    }
}

void gc::Struct::set(const std::string& name, const Ref<BaseObject>& value) {
    if (_is_present[name]) {
        _data[name].object().decrement();
    }

    _data[name] = value;
    _is_present[name] = true;
}

template<typename T>
gc::Ref<T> gc::Struct::get(const std::string& name) {
    return *reinterpret_cast<Ref<T>*>(&_data[name]);
}

gc::GarbageCollector::GarbageCollector() : _objects() {}

gc::GarbageCollector::~GarbageCollector() {
    for (BaseObject* obj : _objects) {
        delete obj;
    }
}

template<typename T>
gc::Ref<gc::LeafObject<T>> gc::GarbageCollector::createLeafObject(const T& value) {
    auto obj = new LeafObject<T>(value);
    _objects.push_back(obj);

    return Ref(obj);
}

template<typename T>
gc::Ref<gc::Array<T>> gc::GarbageCollector::createArray(size_t size) {
    auto obj = new gc::Array<T>(size);
    _objects.push_back(obj);

    return Ref(obj);
}

gc::Ref<gc::Struct> gc::GarbageCollector::createStruct(const std::vector<std::string>& names) {
    auto obj = new gc::Struct(names);
    _objects.push_back(obj);

    return gc::Ref(obj);
}

void gc::GarbageCollector::collect() {
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

void gc::GarbageCollector::showObjects() {
    std::cout << "Objects in GC\n";
    for (BaseObject* obj : _objects) {
        std::cout << obj << " " << obj->counter() << std::endl;
    }
    std::cout << "-------------\n";
}
