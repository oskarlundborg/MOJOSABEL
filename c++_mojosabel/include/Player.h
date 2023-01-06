#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

namespace mojosabel {
    
    class Player : public GameObject
    {
    protected:
        int health;
    public:
        Player() = delete;
        Player(int x, int y, int w, int h, int layer, int speed);
        virtual void move();
        virtual void update();
        virtual void fire(int x, int y);
        virtual void mouseDown(int x, int y);
        virtual bool levelCompleted() { return true; }
    };
}
#endif