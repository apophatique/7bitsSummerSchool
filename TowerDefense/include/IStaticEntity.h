//
// Created by gaziz on 11.09.18.
//

#ifndef FIRSTTRY_ENTITY_H
#define FIRSTTRY_ENTITY_H
#include <memory>

class IStaticEntity {
 public:
    virtual std::shared_ptr<IStaticEntity> clone() = 0;
    virtual ~IStaticEntity() = default;
    char getEntityModel() {
        return entityModel;
    }

protected:
    char entityModel {};
};



#endif //FIRSTTRY_ENTITY_H
