#include "WallTile.h"

namespace mojosabel {

    WallTile::WallTile(int xPos, int yPos) : Entity(xPos, yPos, TILE_SIZE, TILE_SIZE, -1, "Wall")
    { 
        loadTexture(constants::gResPath + "images/GrayWall.png"); 
        hasCollision = true;
    }
}
