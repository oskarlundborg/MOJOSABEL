#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define MAX_KEYBOARD_KEYS 350

namespace mojosabel
{
    class System 
    {
    private:
        SDL_Window* win;
        SDL_Renderer* ren;
        TTF_Font* font;

    public:
        System();
        ~System();
        SDL_Renderer* getRen() const;
        TTF_Font* getFont() const;
        SDL_Window* getWin() const;
        int keyboard[MAX_KEYBOARD_KEYS] = {0};
        bool isOutOfBounds(int x, int y);
    };

    extern System sys;

} 

#endif