#ifndef IMAGE_H
#define IMAGE_H
#include "Image_test.h"
#include "System.h"

namespace mojosabel {
    Image_test::Image_test(int x, int y, int w, int h): Sprite(x,y,w,h){
        SDL_Surface* surf = SDL_LoadBMP("C:/Users/moawi/OneDrive/Skola/CPROG/projekt/MOJOSABEL/c++_mojosabel/resources/images");
        texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);
        SDL_FreeSurface(surf);
    };

    void Image_test::draw() const{
        SDL_RenderCopy(sys.getRen(), texture, NULL, NULL);
    }

}


#endif