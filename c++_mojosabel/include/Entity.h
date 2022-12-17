#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <string>

namespace mojosabel {

    class Entity 
    {
    public:
        Entity() : Entity(0, 0, 0, 0, 1) {}
        Entity(float xVal, float yVal, float dxVal, float dyVal, int healthVal); 
        float x;
        float y;
        float dx;
        float dy;
        int health;
        SDL_Texture* texture;
        void loadTexture(std::string filename);
        void draw(SDL_Texture* tex, float x, float y);
        virtual void update() {}
        void print();
        ~Entity();
    };
}

#endif