#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

class Sprite {
private:
    int layer;

public:
    void Draw();
    void Tick();
    void GetRect();

};


#endif