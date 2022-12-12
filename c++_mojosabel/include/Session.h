#ifndef SESSION_H
#define SESSION_H

#include <vector>

#include "World.h"
#include "Canvas.h"
#include "Sprite.h"

namespace mojosabel {

    class Session{
    private:
        //World world;
        Canvas canvas;
        std::vector<Sprite*> sprites;

    public:
        Session();
        void add(Sprite* spriteToAdd);
        void CreateNewWorld(int levelCount);
        void CreateNewCanvas();
        void run();
        ~Session();
    };
}

#endif