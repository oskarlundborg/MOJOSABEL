#include "FloorTile.h"

namespace mojosabel {

    FloorTile::FloorTile(int xPos, int yPos) : Entity(xPos, yPos, TILE_SIZE, TILE_SIZE, -1, "Floor")
    { 
        loadTexture(constants::gResPath + "images/GrassTile.png"); 
    }
}
