//
// Created by gaziz on 18.09.18.
//

#ifndef FIRSTTRY_ROAD_H
#define FIRSTTRY_ROAD_H


#include "IStaticEntity.h"

class Road : public IStaticEntity {
public:
    std::shared_ptr<IStaticEntity> clone() override {
        return std::make_shared<Road>(Road(*this));
    }
    Road() {
        entityModel = ' ';
    }
};


#endif //FIRSTTRY_ROAD_H
