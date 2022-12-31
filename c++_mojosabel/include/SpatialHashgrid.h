#ifndef SPATIALHASHGRID_H
#define SPATIALHASHGRID_H

#include <vector>
#include "Entity.h"
#include "System.h"

namespace mojosabel {

    class SpatialHashgrid
    {
        std::vector<Entity*> entityGrid [MAP_WIDTH][MAP_HEIGHT];

        
        //add metoden: ta emot en entity* och sätta in den i en cell som motsvarar entitiens koorrdinater. 
        //remove metod: ta in en entity* att ta bort, ta bort den i den cell som motsvarar entities koordinater.
        //getNearby metod: tar emot en entity* och en avståndsvariabel(aka antal celler bort) och returnerar en vector med entity*

    };
}

#endif

