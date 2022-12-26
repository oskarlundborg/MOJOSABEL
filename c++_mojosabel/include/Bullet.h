#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"
#include "Vector2.h"

namespace mojosabel {

    class Bullet : public GameObject
    {
    public:
        Vector2 target;
        Bullet() : GameObject() { speed = 0; }
        Bullet(int x, int y, int w, int h, int layer, std::string tag, int speed, int targetX, int targetY);
        int speed;
        void update();
        void move();
        void onCollision(Collision<Entity> collision);
        void findClosestEnemy();
    };
}
#endif