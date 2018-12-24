//
// Created by gaziz on 11.09.18.
//

#ifndef FIRSTTRY_WALL_H
#define FIRSTTRY_WALL_H
#include "IStaticEntity.h"
#include <iostream>

class Wall: public IStaticEntity {
 public:
    std::shared_ptr<IStaticEntity> clone() override {
        return std::make_shared<Wall>(Wall(*this));
    }
    Wall() {
        entityModel = '#';
    }
};


#endif //FIRSTTRY_WALL_H
