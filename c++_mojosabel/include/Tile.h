#ifndef TILE_H
#define TILE_H

#include <Vector>
#include "Entity.h"

namespace mojosabel {

   class Tile 
   {
    private:
        std::vector<Entity*> tileObjects;
    public:
        void getTopLayer(); // när vi ritar ut tiles i tilemap så hämtar vi det översta lagret och ritar ut det.
        void add(Entity* entityToAdd);
        void remove(Entity* entityToRemove);
        void sort();
    }; 
    bool compareLayer(Entity* e1, Entity* e2);
}

#endif

