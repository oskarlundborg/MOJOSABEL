#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>

#include "Collision.h"
#include "Collider.h"
#include "Vector2.h"

namespace mojosabel {


    /*
        För spatial hashgrid: måste veta vart den är hela tiden och uppdatera sin position. 
        Ska kunna vara i fler gridspaces samtidigt
        
    */
    class Entity 
    {
    public:
        SDL_Rect rect;
        int layer;
        int delay = 60;
        bool hasCollision = false;
        std::string tag;
        SDL_Texture* texture;
        std::vector<Collider> colliders;
        Entity() : Entity(0, 0, 0, 0, 0, "Unknown") {}
        Entity(int xPos, int yPos, int width, int height, int layer, std::string tag);
        void setCollision(bool toSet);
        bool hasColliders();
        void addCollider(int xOffset, int yOffset, int colWidth, int colHight);
        void adjustColliders();
        int getLayer() { return layer; }
        std::vector<Collider>& getColliders();
        Vector2 position();
        void setPosition(Vector2 vecToSet);
        void loadTexture(std::string filename);
        void resizeToImage();
        void draw();
        void sneakyUpdate();
        virtual void start() {}
        virtual void update() {}
        virtual void fixedUpdate() {}
        virtual void onCollision(Collision<Entity> collision) {} 
        virtual void mouseUp(SDL_Event event) {}
        virtual void mouseDown(SDL_Event event) {}
        virtual ~Entity();
    };
}

#endif