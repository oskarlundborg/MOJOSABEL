#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include <vector>
#include "Entity.h"
#include "BulletEntity.h"


namespace mojosabel {

    class PlayerEntity  : public Entity
    {
    public:
        int speed;
        int reload;
        std::vector<BulletEntity*> bullets;
        PlayerEntity() : PlayerEntity(0, 0, 0, 0, 1, 1, 1) {}
        PlayerEntity(float xVal, float yVal, float dxVal, float dyVal, int healthVal, int speedVal, int reloadVal) : Entity(xVal, yVal, dxVal, dyVal, healthVal), speed{speedVal}, reload{reloadVal} {}
        void move();
        void moveUp(int speed);
        void moveDown (int speed);
        void moveLeft(int speed);
        void moveRight(int speed);
        void fire();
        void update();
        void destroyBullet(BulletEntity*);
    };
}

#endif