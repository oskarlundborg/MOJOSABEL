#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Sprite.h"

class Game_object : public Sprite {

private:
    float elasticity;

public:
    float GetElasticity() const;

};


#endif