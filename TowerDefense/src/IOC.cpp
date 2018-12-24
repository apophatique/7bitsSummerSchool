#include <string>

#include "../include/IOC.h"

IOC *IOC::p_instance = nullptr;

IOCDestroyer IOC::destroyer;

IOCDestroyer::~IOCDestroyer() {
    delete p_instance;
}

void IOCDestroyer::execute(IOC *p) {
    p_instance = p;
}

IOC &IOC::getInstance() {
    if (p_instance == nullptr) {
        p_instance = new IOC();
        destroyer.execute(p_instance);
    }

    return *p_instance;
}

void IOC::remove(const std::string &id) {
    container.erase(id);
}

bool IOC::contains(const std::string &id) {
    auto buffer = container.find(id);
    return buffer != container.end();
}
