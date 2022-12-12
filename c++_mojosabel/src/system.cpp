#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Constants.h"
#include "System.h"

namespace mojosabel {

    System::System()
    {
        std::cout << "Hej det funkar: systemet!\n";

        SDL_Init(SDL_INIT_EVERYTHING);
        win = SDL_CreateWindow("Mojosabel", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
        //SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN_DESKTOP);
        ren = SDL_CreateRenderer(win, -1, 0);
        TTF_Init();
        font = TTF_OpenFont((constants::gResPath + "fonts/arial.ttf").c_str(), 36);
        std::cout << "resPath: " << constants::gResPath << std::endl;
    }

    System::~System(){
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
    }

    SDL_Renderer* System::getRen() const {
        return ren;
    }
    
    TTF_Font* System::getFont() const {
        return font;
    }
    
   System sys;    
}