#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>

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
        std::vector<Entity*> *sessionRemoved, *sessionAdded;
        std::string name;
        SDL_Texture* texture;
        Entity() : Entity(0, 0, 0, 0, 0, "Unknown") {}
        Entity(float x, float y, int w, int h, int layer, std::string name);
        void loadTexture(std::string filename);
        void draw(float x, float y);
        void setCollision(bool toSet);
        void setSession(std::vector<Entity*>* sesRemoved, std::vector<Entity*>* sesAdded) {sessionRemoved = sesRemoved; sessionAdded = sesAdded;}
        void sneakyUpdate();
        void instantiate(Entity* entity);
        void destroy();
        virtual void start() {}
        virtual void update() {}
        virtual void mouseUp(SDL_Event event) {}
        virtual void mouseDown(SDL_Event event) {}
        virtual ~Entity();
    };
}

#endif