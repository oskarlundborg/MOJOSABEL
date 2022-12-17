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
        for(auto bullet : bullets){
            bullet->update();
        }
    }
    void PlayerEntity::move() 
    {
        if(sys.keyboard[SDL_SCANCODE_W]) { moveUp(speed); }
        if(sys.keyboard[SDL_SCANCODE_S]) { moveDown(speed); }
        if(sys.keyboard[SDL_SCANCODE_A]) { moveLeft(speed); }
        if(sys.keyboard[SDL_SCANCODE_D]) { moveRight(speed); }
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