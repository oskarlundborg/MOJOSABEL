#include <SDL2/SDL_image.h>
#include <iostream>
#include "System.h"
#include "Entity.h"


namespace mojosabel {

    void Entity::loadTexture(std::string filename)
    {
        texture = IMG_LoadTexture(sys.getRen(), (filename).c_str());
    }

    void Entity::draw(SDL_Texture* tex, float x, float y)
    {
        if(!tex)
        {
            std::cout << "Draw Error: No texture" << std::endl;
            return;
        }
        SDL_Rect rect;

        rect.x = (int)x;
        rect.y = (int)y;

        SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
        SDL_RenderCopy(sys.getRen(), texture, NULL, &rect);
    }

    void Entity::sneakyUpdate()
    {
        update();
    }

    Entity::~Entity() { SDL_DestroyTexture(texture); }
}