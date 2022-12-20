#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "Collision.h"

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
        std::string tag;
        SDL_Texture* texture;
        Entity() : Entity(0, 0, 0, 0, 0, "Unknown") {}
        Entity(float x, float y, int w, int h, int layer, std::string tag);
        void loadTexture(std::string filename);
        void draw(float x, float y);
        void setCollision(bool toSet);
        void sneakyUpdate();
        virtual void start() {}
        virtual void update() {}
        virtual void onCollision(Collision<Entity> collision) {} 
        virtual void mouseUp(SDL_Event event) {}
        virtual void mouseDown(SDL_Event event) {}
        virtual ~Entity();
    };
}

#endif