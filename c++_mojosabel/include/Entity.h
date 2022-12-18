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
        std::vector<Entity*> *session;
        bool hasCollision = false;
        std::string name;
        SDL_Texture* texture;
        Entity() : Entity(0, 0, 0, 0, 0, "Unknown") {}
        Entity(float x, float y, int w, int h, int layer, std::string name);
        void loadTexture(std::string filename);
        void removeFromSession();
        void draw(float x, float y);
        void toggleCollision(bool toSet);
        void setSession(std::vector<Entity*>* ses) {session = ses;}
        virtual void start() {}
        virtual void update() {}
        void sneakyUpdate();
        ~Entity();
    };
}

#endif