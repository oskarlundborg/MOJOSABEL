#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"
#include "Constants.h"


/*
*/

namespace mojosabel
{
    struct Tilemap
    {
    private:
        Tile* map[MAP_WIDTH][MAP_HEIGHT];
    
    public:
        Tilemap();
        Tile* operator()(int x, int y){return map[x][y];}
    };
}


#endif