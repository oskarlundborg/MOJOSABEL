#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"

namespace mojosabel {

    class Bullet : public GameObject
    {
    private:
        
    public:
        Bullet() : GameObject() { speed = 0; }
        Bullet(int x, int y, int w, int h, int layer, std::string tag, int speed);
        int speed;
        void update();
        void move();
        void onCollision(Collision<Entity> collision);
    };
}
#endif