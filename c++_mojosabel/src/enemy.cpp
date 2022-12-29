#include <iostream>
#include "Enemy.h"
#include "System.h"

namespace mojosabel {

    Enemy::Enemy() : GameObject()
    {
        health = 0;
        speed = 0;
    }

    Enemy::Enemy(int x, int y, int w, int h, int layer, std::string name, int sp)
        : GameObject (x, y, w, h, layer, name)
    {
        speed = sp;
    }

    void Enemy::update()
    {
        move();
    }

    void Enemy::fixedUpdate()
    {
        if (direction == 0)
        {
            direction = 1;
        }
        else if (direction == 1)
        {
            direction = 0;
        }
    }

    void Enemy::move()
    {
        switch (direction)
        {
        case(0):
            rect.x -= speed; //left
            break;
        case(1):
            rect.x += speed; //right
            break;
        }
    }
        

    void Enemy::onCollision(Collision<Entity> collision)
    {
        if (collision.tag == "Bullet") { destroy(this); }
    }
}