#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

namespace mojosabel {
    
    class Player : public GameObject
    {
    private:
        int health;
    public:
        Player() = delete;
        Player(int x, int y, int w, int h, int layer, std::string tag, int speed);
        void move();
        void update();
        void fire(int x, int y);
        void mouseDown(int x, int y);
    };
}
#endif