#include "gc.h"

std::vector<gc::Ref<gc::BaseObject>> gc::BaseObject::getChildren() {
    return {};
}

gc::GarbageCollector::GarbageCollector() {
    std::cout << "654678" << std::endl;
};

gc::GarbageCollector::~GarbageCollector() {
    for (BaseObject* obj : *_root) {
        delete obj;
    }
    delete _root;
}

void gc::GarbageCollector::collect() {
    _marked.clear();
    for (auto obj : *_root) {
        mark(obj);
    }
    sweep();
}

void gc::GarbageCollector::mark(gc::BaseObject* obj) {
    if (_marked.find(obj) != _marked.end()) {
        return;
    }

    _marked.insert(obj);

    // auto temp = *obj;

    std::cout << obj->getChildren().size() << std::endl;

    for (const auto& child : obj->getChildren()) {
        mark(child._object);
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
    std::cout << _objects.size() << " " << _root->size() << "\n";
    std::cout << "-------------" << std::endl;
}
