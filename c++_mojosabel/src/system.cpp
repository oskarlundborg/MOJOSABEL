#include <SDL2/SDL.h>
#include <iostream>
#include "Constants.h"
#include "System.h"

namespace mojosabel {

    System::System()
    {
        std::cout << "Hej det funkar: systemet!´\n";

        SDL_Init(SDL_INIT_EVERYTHING);
        win = SDL_CreateWindow("Mojosabel", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, 0);
        ren = SDL_CreateRenderer(win, -1, 0);
        //TTF_Init();
        //font = TTF_openFont();
    }

    System::~System(){
        //TTF_closeFont(font);
        //TTF_Quit();
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
    }

    SDL_Renderer* System::getRen() const {
        return ren;
    }

    /*
    TTF_Font* System::getFont() const {
        return font;
    }
    */

   System sys;    

}