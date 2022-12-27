#ifndef WALLTILE_H
#define WALLTILE_H

#include "Entity.h"
#include "System.h"
#include "Constants.h"

namespace mojosabel{

    class WallTile : public Entity
    {
    public:
        const bool blocked = true;
        WallTile(int xPos, int yPos);
    };
}
#endif