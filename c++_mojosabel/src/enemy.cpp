#include <iostream>
#include "Enemy.h"

namespace mojosabel {

    Enemy::Enemy() : GameObject()
    {
        health = 0;
        speed = 0;
    }

    Enemy::Enemy(float x, float y, int w, int h, int layer, std::string name, float sp)
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
        yPos += speed;
    }

    void Enemy::onCollision(Collision<Entity> other)
    {
        if (other.tag == "Bullet") { std::cout << "enemy hit" << std::endl; }
    }
}