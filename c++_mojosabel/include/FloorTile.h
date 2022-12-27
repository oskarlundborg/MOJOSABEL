#ifndef FLOORTILE_H
#define FLOORTILE_H

#include "Entity.h"
#include "System.h"
#include "Constants.h"

namespace mojosabel{

    class FloorTile : public Entity
    {
    public:
        const bool blocked = false;
        FloorTile(int xPos, int yPos);
    };
}
#endif