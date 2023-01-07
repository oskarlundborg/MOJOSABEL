#ifndef GTURTLE_H
#define GTURTLE_H

#include "Player.h"

using namespace mojosabel;

class GTurtle : public Player
{
    private:
        int iFrameCounter = 60;
        bool canShoot;
    public:
        GTurtle(int x, int y, int startHealth) : Player(x, y, 32, 32, 0, 3){health = startHealth; canShoot = true;}
        void adjustHealth(int changeHealth);
        void onCollision(Collision<Entity> collision);
        void fire(int x, int y);
        void die();
        void update();
};

#endif