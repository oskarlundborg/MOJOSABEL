#include <iostream>
#include "Bullet.h"
#include "System.h"


namespace mojosabel {
    
    Bullet::Bullet(float x, float y, int w, int h, int layer, std::string tag, float s)
        : GameObject(x, y, w, h, layer, tag)
    {
        speed = s;
    }

    void Bullet::update()
    {
        move();

        if (sys.isOutOfBounds(xPos, yPos))
        {
            destroy(this);
        }
    }

    void Bullet::move()
    {
        yPos -= speed;
    }
}