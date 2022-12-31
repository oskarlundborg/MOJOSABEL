#include "WallTile.h"

namespace mojosabel {

    WallTile::WallTile(int xPos, int yPos, std::string texture) : Entity(xPos, yPos, TILE_SIZE, TILE_SIZE, -1, "Wall")
    { 
        loadTexture(constants::gResPath + texture); 
        hasCollision = true;
    }
}
