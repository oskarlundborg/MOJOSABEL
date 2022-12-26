#ifndef FLOORTILE_H
#define FLOORTILE_H

#include "Entity.h"
#include "System.h"
#include "Constants.h"

namespace mojosabel{

    class FloorTile : public Entity
    {
    public:
        FloorTile(int xPos, int yPos)
            : Entity(xPos, yPos, TILE_SIZE, TILE_SIZE, -1, "Floor" ) 
        { loadTexture(constants::gResPath + "images/GrassTile.png"); 
        
        }
        
        
    };
}
#endif