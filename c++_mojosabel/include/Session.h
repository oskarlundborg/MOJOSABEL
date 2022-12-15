#ifndef SESSION_H
#define SESSION_H

#include <vector>

#include "World.h"
#include "Canvas.h"
#include "Sprite.h"
#include "System.h"

namespace mojosabel {

    class Session
    {
    private:
        //World world;
        Canvas *rootCanvas;
        std::vector<Sprite*> sprites;
        void doKeyUp(SDL_KeyboardEvent* event);
        void doKeyDown(SDL_KeyboardEvent* event);
    public:
        Session();
        void add(Sprite* spriteToAdd);
        Canvas* getRootCanvas() {return rootCanvas;};
        void CreateNewWorld(int levelCount);
        void run();
        ~Session();
    };
}

#endif