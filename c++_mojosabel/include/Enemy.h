#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

namespace mojosabel {

    class Enemy : public GameObject
    {
    public:
        int health;
        int speed;
        Enemy();
        Enemy(int x, int y, int w, int h, int layer, std::string name, int speed);
        void onCollision(Collision<Entity> collision);
        void update();
        void move();
    };
}

#endif