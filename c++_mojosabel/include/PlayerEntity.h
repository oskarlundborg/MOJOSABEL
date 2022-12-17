#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include "Entity.h"
namespace mojosabel {

    class PlayerEntity  : public Entity
    {
        public:
            int speed = 0;
            SDL_Texture* loadTexture(std::string filename);
            void move();
            void moveUp(int x);
            void moveDown (int x);
            void moveLeft(int x);
            void moveRight(int x);
            void fire();
            void draw(SDL_Texture* tex, int x, int y);
            void update();
    };
}
#endif