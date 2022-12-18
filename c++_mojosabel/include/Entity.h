#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <string>

namespace mojosabel {

    class Entity 
    {
    public:
        float xPos;
        float yPos;
        int width;
        int height;
        int layer;
        bool hasCollision = false;
        std::string name;
        SDL_Texture* texture;
        Entity() : Entity(0, 0, 0, 0, 0, "Unknown") {}
        Entity(float x, float y, int w, int h, int layer, std::string name) 
            : xPos(x), yPos(y), width(w), height(h), layer(layer), name(name) {} 
        void loadTexture(std::string filename);
        void draw(SDL_Texture* tex, float x, float y);
        virtual void update() {}
        void sneakyUpdate();
        ~Entity();
    };
}

#endif