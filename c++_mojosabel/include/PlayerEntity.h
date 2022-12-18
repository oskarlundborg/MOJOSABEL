#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include "Entity.h"


namespace mojosabel {

    class PlayerEntity  : public Entity
    {
    public:
        int reload;
        PlayerEntity() : PlayerEntity(0, 0, 0, 0, 1, 1) {}
        PlayerEntity(float xVal, float yVal, float dxVal, float dyVal, int healthVal, int reloadVal) : Entity(xVal, yVal, dxVal, dyVal, healthVal), reload{reloadVal} {}
        void move();
        void moveUp(int speed);
        void moveDown (int speed);
        void moveLeft(int speed);
        void moveRight(int speed);
        void fire();
        void update();
    };
}

#endif