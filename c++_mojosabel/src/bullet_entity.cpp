#include <iostream>
#include "Bullet_Entity.h"
#include "System.h"


namespace mojosabel {
    
    Bullet_Entity::Bullet_Entity(float x, float y, int w, int h, int layer, std::string name, float s)
        : Entity(x, y, w, h, layer, name)
    {
        speed = s;
    }

    void Bullet_Entity::update()
    {
        move();

        if (sys.isOutOfBounds(xPos, yPos))
        {
            destroy();
        }
    }

    void Bullet_Entity::move()
    {
        yPos -= speed;
    }
}