#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"
#include "System.h"


namespace mojosabel
{
    struct Tilemap
    {
    private:
        Tilemap();
        Tile* tileGrid[MAP_WIDTH][MAP_HEIGHT];

    };
}


#endif