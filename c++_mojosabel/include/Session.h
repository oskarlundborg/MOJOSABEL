#ifndef SESSION_H
#define SESSION_H

#include <vector>

#include "World.h"
#include "Canvas.h"
#include "Entity.h"

namespace mojosabel {

    class Session
    {
    private:
        World* world;
        long renderTime; //tiden det tog för förra framen att rendera
        float remainder; 
        Canvas *rootCanvas;
        std::vector<Entity*> entities, addedEntities, removedEntities; 
        void doKeyUp(SDL_KeyboardEvent* event);
        void doKeyDown(SDL_KeyboardEvent* event);
        bool entityExists(Entity* entity); //loopa genom alla entities, om en entity är samma returnera true, annars returnera false efter loopen
        bool checkCollision(SDL_Rect rect1, SDL_Rect rect2);
        bool checkColliders(SDL_Rect rectToCheck, std::vector<Collider>& colliders);
        void checkAllCollisions(Entity* entity); // går igenom alla entities och kollar om det objektet kolliderar med något av objekten 
        void capFrameRate(long *renderTime, float *remainder);

    public:
        Session();
        void add(Entity* entityToAdd);
        void remove(Entity* entityToRemove);
        void createNewWorld(int smoothMap, int fillPercent, int smoothWalkableLimit, int smoothUnwalkableLimit);
        void run();
        World* getWorld() { return world; }
        ~Session();
        Canvas* getRootCanvas() {return rootCanvas;};
        Entity* findEntity(std::string name);
    };

    // struct collision som innehåller en pointer/namnet till det objektet kolliderar med
    extern Session ses;
    
}

#endif