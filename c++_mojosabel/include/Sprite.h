#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>

namespace mojosabel {

    class Sprite {
    private:
        int layer;
        SDL_Rect rect;
        Sprite(const Sprite&) = delete;
        const Sprite& operator=(const Sprite&) = delete;

    protected:
        Sprite(int x, int y, int w, int h);
    public:
        ~Sprite();
        virtual void mouseDown(const SDL_Event&) {}
		virtual void mouseUp(const SDL_Event&) {}
        virtual void keyDown(const SDL_Event&) {}
		virtual void keyUp(const SDL_Event&) {}
        virtual void draw() const = 0;
        //virtual void tick();
        const SDL_Rect& getRect() const { return rect; };
        
    };
}



#endif