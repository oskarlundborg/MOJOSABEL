#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <string>

namespace mojosabel {

    class Entity {
        
    public:
        int x;
        int y;
        int dx;
        int dy;
        int health;
        SDL_Texture *texture;
        virtual SDL_Texture* loadTexture(std::string filename);
        virtual void draw(SDL_Texture* tex, int x, int y);
        virtual void update();
    };

}

#endif