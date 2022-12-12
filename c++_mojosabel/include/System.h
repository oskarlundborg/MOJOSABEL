#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

namespace mojosabel
{
    class System {
    private:
        SDL_Window* win;
        SDL_Renderer* ren;
        TTF_Font* font;

    public:
        System();
        ~System();
        SDL_Renderer* getRen() const;
        TTF_Font* getFont() const;
    };

    extern System sys;

} 

#endif