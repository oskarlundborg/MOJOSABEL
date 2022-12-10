#ifndef SESSION_H
#define SESSION_H
#include "World.h"
#include "Canvas.h"

namespace mojosabel {
    class Session{
    private:
        World world;
        Canvas canvas;

    public:
        Session();
        void NewWorld(int levelCount);
        void run();
        ~Session();
    };
}

#endif