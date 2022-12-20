#include <iostream>
#include "Bullet.h"
#include "System.h"


namespace mojosabel {
    
    Bullet::Bullet(float x, float y, int w, int h, int layer, std::string name, float s)
        : GameObject(x, y, w, h, layer, name)
    {
        speed = s;
    }

    void Bullet::update()
    {
        move();

        if (sys.isOutOfBounds(xPos, yPos))
        {
            destroy();
        }
    }

    void Bullet::move()
    {
        yPos -= speed;
    }
}