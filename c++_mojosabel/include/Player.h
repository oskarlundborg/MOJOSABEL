#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

namespace mojosabel {
    
    class Player : public GameObject
    {
    private:
        int health;
        float speed;
    public:
        Player();
        Player(float x, float y, int w, int h, int layer, std::string tag, float speed);
        void move();
        void update();
        void fire();
        void mouseDown(SDL_Event event);
        virtual ~Player() {}
    };
}
#endif