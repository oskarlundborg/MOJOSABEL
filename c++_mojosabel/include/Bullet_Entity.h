#ifndef BULLET_ENTITY_H
#define BULLET_ENTITY_H

#include "Entity.h"
namespace mojosabel {

    class Bullet_Entity : public Entity
    {
    private:
        
    public:
        Bullet_Entity() : Entity() { speed = 0;}
        Bullet_Entity(float x, float y, int w, int h, int layer, std::string name, float speed);
        int speed;
        bool isDead = false;
        void update();
        void move();
    };
}
#endif