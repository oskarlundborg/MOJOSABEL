#ifndef JOSBULLET_H
#define JOSBULLET_H

#include "Bullet.h"

using namespace mojosabel;

class JosBullet : public Bullet {
private:
    int damage;
public:
    JosBullet(int posX, int posY, std::string tag, int speed, int targetX, int targetY, int damage);
};

JosBullet::JosBullet(int posX, int posY, std::string tag, int speed, int targetX, int targetY, int damage) 
        : Bullet(posX, posY, 16, 16, 1, tag, speed, targetX, targetY), damage(damage) 
{
    loadTexture(constants::gResPath + "images/Bullet.png");
    setCollision(true);
}

#endif