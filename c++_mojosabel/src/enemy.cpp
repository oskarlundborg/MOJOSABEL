#include <iostream>
#include "Enemy.h"
#include "System.h"

namespace mojosabel {

    Enemy::Enemy() : GameObject()
    {
        health = 0;
        speed = 0;
        mF = moveLeft;
    }

    Enemy::Enemy(int x, int y) : Enemy(x, y, 32, 32, 0, "Enemy", 1)
    {
        
    }

    Enemy::Enemy(int x, int y, int w, int h, int layer, std::string name, int sp)
        : GameObject (x, y, w, h, layer, name)
    {
        speed = sp;
        mF = moveLeft;
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
        if(checkDirection("Left")){
            mF = moveRight;
        } else if(checkDirection("Right")){
            mF = moveLeft;
        }

        mF(this);
    }
        

    void Enemy::onCollision(Collision<Entity> collision)
    {
        if (collision.tag == "Bullet") { destroy(this); }
    }
}