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
        Enemy(float x, float y, int w, int h, int layer, std::string name, float speed);
        void onCollision(Collision<Entity> other);
        void update();
        void move();
    };
}

#endif