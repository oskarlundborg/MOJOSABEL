#ifndef BULLETENTITY_H
#define BULLETENTITY_H

#include "Entity.h"
#include "PlayerEntity.h"

namespace mojosabel {

    class BulletEntity  : public Entity
    {
        public:
            PlayerEntity *player;
            SDL_Texture* loadTexture(std::string filename);
            void draw(SDL_Texture* tex, int x, int y);
            void update();
            void move();
    };
}
#endif