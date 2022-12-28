#ifndef SESSION_H
#define SESSION_H

#include <vector>

#include "World.h"
#include "Canvas.h"
#include "Sprite.h"
#include "System.h"
#include "Entity.h"

namespace mojosabel {

    class Session
    {
    private:
        World* world;
        long renderTime; //tiden det tog för förra framen att rendera
        float remainder; 
        Canvas *rootCanvas;
        std::vector<Sprite*> sprites;
        std::vector<Entity*> entities, addedEntities, removedEntities; 
        void doKeyUp(SDL_KeyboardEvent* event);
        void doKeyDown(SDL_KeyboardEvent* event);
    public:
        Session();
        bool entityExists(Entity* entity); //loopa genom alla entities, om en entity är samma returnera true, annars returnera false efter loopen
        bool checkCollision(SDL_Rect rect1, SDL_Rect rect2);
        bool checkColliders(SDL_Rect rectToCheck, std::vector<Collider>& colliders);
        void checkAllCollisions(Entity* entity); // går igenom alla entities och kollar om det objektet kolliderar med något av objekten 
        void addSprite(Sprite* spriteToAdd);
        void add(Entity* entityToAdd);
        void remove(Entity* entityToRemove);
        void removeSprite(Sprite* spriteToAdd); //no working
        void createNewWorld(int levelCount);
        void capFrameRate(long *renderTime, float *remainder);
        void run();
        World* getWorld(){return world;}
        void setWorld(World* worldToSet) { world = worldToSet;}
        ~Session();
        Canvas* getRootCanvas() {return rootCanvas;};
        Entity* findEntity(std::string name);
    };

    // struct collision som innehåller en pointer/namnet till det objektet kolliderar med
    extern Session ses;
    
}

#endif