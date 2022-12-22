#include <iostream>
#include "Bullet.h"
#include "System.h"
#include "Session.h"


namespace mojosabel {
    
    Bullet::Bullet(int x, int y, int w, int h, int layer, std::string tag, int s)
        : GameObject(x, y, w, h, layer, tag)
    {
        speed = s;
        findClosestEnemy();
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
        setPosition(position().moveTowards(target, speed));
    }

    void Bullet::findClosestEnemy()
    {
        
        target = ses.findEntity("Enemy")->position();
    }

    void Bullet::onCollision(Collision<Entity> collision)
    {
        if (collision.tag == "Enemy") 
        { 
            std::cout << "hit enemy" << std::endl; 
            destroy(collision.object);
            destroy(this);
        }
    }
}