//
// Created by gaziz on 10.09.18.
//

#ifndef FIRSTTRY_PROTOTYPE_H
#define FIRSTTRY_PROTOTYPE_H

#include "IStaticEntity.h"
#include <map>
#include <string>
#include <memory>
#include <utility>

class PrototypeFactory {
 public:
    std::map<std::string, std::shared_ptr<IStaticEntity>> PrototypeDictionary;

    void put(const std::string &id, std::shared_ptr<IStaticEntity> objectPtr) {
        PrototypeDictionary[id] = std::move(objectPtr);
    }

    void put(const char &id, const std::shared_ptr<IStaticEntity> &objectPtr) {
        std::string buffer;
        buffer.push_back(id);

        PrototypeDictionary[buffer] = objectPtr;
    }

    std::shared_ptr<IStaticEntity> get(const std::string &id) {
        return PrototypeDictionary[id]->clone();
    }

    std::shared_ptr<IStaticEntity> get(const char &id) {
        std::string buffer;
        buffer.push_back(id);

        return PrototypeDictionary[buffer]->clone();
    }
};


#endif //FIRSTTRY_PROTOTYPE_H
