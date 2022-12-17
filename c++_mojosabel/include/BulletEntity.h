#ifndef BULLET_ENTITY_H
#define BULLET_ENTITY_H

#include "Entity.h"
#include "PlayerEntity.h"

namespace mojosabel {

    class BulletEntity  : public Entity
    {
    public:
        PlayerEntity *player;
        BulletEntity() : BulletEntity(0, 0, 0, 0, 1) {}
        BulletEntity(float xVal, float yVal, float dxVal, float dyVal, int healthVal) : Entity(xVal, yVal, dxVal, dyVal, healthVal) {}
        void update();
        void move();
    };
}

#endif