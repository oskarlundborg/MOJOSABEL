#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Sprite.h"

namespace mojosabel
{
    class Player : public Sprite 
    {
        private:
            int speed = 0;
            int pHealth = 0;
            SDL_Texture* texture;
            Player(int x, int y, int w, int h) : Sprite (x, y, w, h) {}
            void move();
            void moveUp(int dist);
            void moveDown(int dist);
            void moveLeft(int dist);
            void moveRight(int dist);
        public:
            static Player* getInstance(int x, int y, int w, int h) { return new Player(x, y, w, h);}
            void loadTexture(std::string filename);
            void setSpeed(int newSpeed) {speed = newSpeed;}
            void health(int newHealth) {pHealth = newHealth;}
            int health() { return pHealth; }
            void fire();
            void draw();
            ~Player();
    };
}

#endif