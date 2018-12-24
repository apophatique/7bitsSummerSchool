//
// Created by gaziz on 18.09.18.
//

#ifndef FIRSTTRY_FLOOR_H
#define FIRSTTRY_FLOOR_H


#include "IStaticEntity.h"

class Floor : public IStaticEntity {
public:
    std::shared_ptr<IStaticEntity> clone() override {
        return std::make_shared<Floor>(Floor(*this));
    }
    Floor() {
        entityModel = '.';
    }
};


#endif //FIRSTTRY_FLOOR_H
