#include <iostream>
#include "Enemy.h"

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

    void Enemy::move()
    {
        //yPos += speed;
    }

    void Enemy::onCollision(Collision<Entity> collision)
    {
        if (collision.tag == "Bullet") { destroy(this); }
    }
}