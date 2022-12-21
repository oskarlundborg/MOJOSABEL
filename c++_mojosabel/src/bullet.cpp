#include <iostream>
#include "Bullet.h"
#include "System.h"


namespace mojosabel {
    
    Bullet::Bullet(int x, int y, int w, int h, int layer, std::string tag, int s)
        : GameObject(x, y, w, h, layer, tag)
    {
        speed = s;
    }

    void Bullet::update()
    {
        move();

        if (sys.isOutOfBounds(rect.x, rect.y))
        {
            destroy(this);
        }
    }

    void Bullet::move()
    {
        rect.y -= speed;
    }

    void Bullet::onCollision(Collision<Entity> collision)
    {
        if (collision.tag == "Enemy") 
        { 
            std::cout << "hit enemy" << std::endl; 
            destroy(collision.object);
        }
    }
}