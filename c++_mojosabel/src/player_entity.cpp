#include <SDL2/SDL_image.h>
#include "System.h"
#include "PlayerEntity.h"

namespace mojosabel {

    SDL_Texture* PlayerEntity::loadTexture(std::string filename)
    {
        SDL_Texture *texture;
        texture = IMG_LoadTexture(sys.getRen(), (filename).c_str());
        return texture;
    }

    void PlayerEntity::draw(SDL_Texture* tex, int x, int y)
    {
        SDL_Rect rect;

        rect.x = x;
        rect.y = y;

        SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
        SDL_RenderCopy(sys.getRen(), texture, NULL, &rect);
    }

    void PlayerEntity::update()
    {
        move();
        fire();
    }
    void PlayerEntity::move() 
    {
        if(sys.keyboard[SDL_SCANCODE_W]) { moveUp(speed); }
        if(sys.keyboard[SDL_SCANCODE_S]) { moveDown(speed); }
        if(sys.keyboard[SDL_SCANCODE_A]) { moveLeft(speed); }
        if(sys.keyboard[SDL_SCANCODE_D]) { moveRight(speed); }
    }

    void PlayerEntity::moveUp(int dist) { y -= dist; }
    
    void PlayerEntity::moveDown(int dist) { y += dist; }

    void PlayerEntity::moveLeft(int dist) { x -= dist; }

    void PlayerEntity::moveRight(int dist) { x += dist; }

    void PlayerEntity::fire() 
    { 
        if(sys.keyboard[SDL_SCANCODE_LCTRL])
        {
            // säga till bullet att röra sig om hälsa är inte 0
        } 
    }
}