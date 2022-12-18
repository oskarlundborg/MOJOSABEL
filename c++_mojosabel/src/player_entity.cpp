#include <SDL2/SDL_image.h>
#include "System.h"
#include "PlayerEntity.h"

namespace mojosabel {

    
    void PlayerEntity::update()
    {
        reload--;
        move();
        fire();
        draw(texture, x, y);
    }
    void PlayerEntity::move() 
    {
        if(sys.keyboard[SDL_SCANCODE_W]) { moveUp(-dy); }
        if(sys.keyboard[SDL_SCANCODE_S]) { moveDown(dy); }
        if(sys.keyboard[SDL_SCANCODE_A]) { moveLeft(-dx); }
        if(sys.keyboard[SDL_SCANCODE_D]) { moveRight(dx); }
    }

    void PlayerEntity::moveUp(int speed) { y -= speed; }
    
    void PlayerEntity::moveDown(int speed) { y += speed; }

    void PlayerEntity::moveLeft(int speed) { x -= speed; }

    void PlayerEntity::moveRight(int speed) { x += speed; }

    void PlayerEntity::fire() 
    { 
        if(sys.keyboard[SDL_SCANCODE_LCTRL])
        {
            
        } 
    }
}