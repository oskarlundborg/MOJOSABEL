#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"
#include "Vector2.h"

namespace mojosabel {

    class Bullet : public GameObject
    {
    private:
        Vector2 target;
    public:
        Bullet() = delete;
        Bullet(int x, int y, int w, int h, int layer, std::string tag, int speed, int targetX, int targetY);
        void update();
        void move();
        void onCollision(Collision<Entity> collision);
    };
}
#endif