#ifndef COMPONENT_H
#define COMPONENT_H

#include "System.h"

namespace mojosabel {

    class Component 
    {
    protected:
        SDL_Rect rect;
        Component(int x, int y, int w, int h) : rect {x, y, w, h} {}
        
    public:
        virtual void start() {}
        virtual void update() {}
        virtual void draw() {}
        const SDL_Rect& getRect() const { return rect; };
    };
}

#endif