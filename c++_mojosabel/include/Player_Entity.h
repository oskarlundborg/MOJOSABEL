#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include "Entity.h"

namespace mojosabel {
    
    class Player_Entity : public Entity
    {
    private:
        int health;
        float speed;
    public:
        Player_Entity();
        Player_Entity(float x, float y, int w, int h, int layer, std::string name, float speed);
        void move();
        void update();
        void fire();
        void mouseDown(SDL_Event event);
        virtual ~Player_Entity();
    };
}
#endif