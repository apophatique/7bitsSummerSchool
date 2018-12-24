//
// Created by gaziz on 13.09.18.
//

#ifndef FIRSTTRY_ENEMYENTITY_H
#define FIRSTTRY_ENEMYENTITY_H
#include <memory>

class EnemyEntity {

    public:
    virtual std::shared_ptr<EnemyEntity> clone() = 0;
    virtual ~EnemyEntity() = default;

    char getEntityModel();
    void entityMove() {};
protected:
    char entityModel {};
};


#endif //FIRSTTRY_ENEMYENTITY_H
