#include <SDL2/SDL_image.h>
#include <iostream>
#include "System.h"
#include "Entity.h"


namespace mojosabel {

    Entity::Entity(float x, float y, int w, int h, int layer, std::string name) 
        : xPos(x), yPos(y), width(w), height(h), layer(layer), name(name) 
    {
        //start();
    } 
        
    void Entity::loadTexture(std::string filename)
    {
        texture = IMG_LoadTexture(sys.getRen(), (filename).c_str());
    }

    void Entity::draw(float x, float y)
    {
        if(!texture)
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
        draw(xPos, yPos);
    }

    void Entity::toggleCollision(bool toSet)
    {
        hasCollision = toSet;
    }

    void Entity::removeFromSession()
    {
        for (std::vector<Entity*>::iterator it = session->begin(); it != session->end(); ++it)
        {
            if (*it == this)
            {
                it = session->erase(it);
            }
        }
    }

    Entity::~Entity() 
    { 
        removeFromSession();
        SDL_DestroyTexture(texture); 
    }
}