#include "gc.h"

std::unordered_set<gc::Ref<gc::BaseObject>, gc::Ref<gc::BaseObject>::HashFunction> gc::BaseObject::getChildren() {
    return {};
}

gc::GarbageCollector::GarbageCollector(bool verbose) {
    _verbose = verbose;
}

gc::GarbageCollector::~GarbageCollector() {
    if (_verbose) {
        std::cout << "----------Left objects in gc------------" << std::endl;
        showObjects();
        _statistic = SIZE_MAX;
        std::cout << "----------Left objects after extra collect------------" << std::endl;
        gc::gc.collect();
        showObjects();
    }
    for (BaseObject* obj : _objects) {
        delete obj;
    }
}

void gc::GarbageCollector::collect() {
    if (_statistic < _limit) {
        return;
    }
    if (_verbose) {
        std::cout << "----------Begin collection------------" << std::endl;
        showObjects();
    }
    _statistic = 0;
    _marked.clear();
    mark(_root);
    sweep();
}

void gc::GarbageCollector::mark(gc::BaseObject* obj) {
    if (_marked.contains(obj)) {
        return;
    }

    _marked.insert(obj);

    for (auto it = (*_ref_data)[obj].begin(); it != (*_ref_data)[obj].end();) {
        if (it->second != 0) {
            mark(it->first);
            it++;
        } else {
            it = (*_ref_data)[obj].erase(it);
        }
    }
}

void gc::GarbageCollector::sweep() {
    size_t counter = 0;
    for (auto it = _objects.begin(); it != _objects.end();) {
        if (_marked.find(*it) == _marked.end()) {
            counter++;
            _ref_data->erase(*it);
            delete *it;
            it = _objects.erase(it);
        } else {
            it++;
        }
    }
    if (_verbose) {
        std::cout << "deleted obj count " << counter << std::endl;
    }
}

void gc::GarbageCollector::showObjects() {
    std::cout << "Objects in gc, in root\n";
    std::cout << _objects.size() << " " << (*_ref_data)[_root].size() << "\n";
    std::cout << "-------------" << std::endl;
}
