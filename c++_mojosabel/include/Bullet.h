#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"

namespace mojosabel {

    class Bullet : public GameObject
    {
    private:
        
    public:
        Bullet() : GameObject() { speed = 0; }
        Bullet(float x, float y, int w, int h, int layer, std::string tag, float speed);
        int speed;
        void update();
        void move();
    };
}
#endif