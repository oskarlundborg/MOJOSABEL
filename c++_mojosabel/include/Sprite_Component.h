#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <SDL2/SDL_image.h>
#include "Component.h"
#include "System.h"


namespace mojosabel {

    class Sprite_Component : public Component
    {
    private:
        
        SDL_Texture* texture;
        
    };
}
#endif