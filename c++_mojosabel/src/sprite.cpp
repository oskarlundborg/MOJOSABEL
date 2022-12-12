#include <SDL2/SDL_image.h>
#include <iostream>


#include "Session.h"
#include "System.h"
#include "Sprite.h"
#include "Constants.h"

namespace mojosabel {

    Sprite::Sprite(int x, int y, int w, int h) : rect {x, y, w, h} 
    { 
        
    }

    Sprite::~Sprite() 
    { 

    }
}