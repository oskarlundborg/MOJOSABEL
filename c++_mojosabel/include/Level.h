#ifndef LEVEL_H
#define LEVEL_H

#include "Tile.h"
#include "Free_object.h"

class Level{
private:
    Tile **tileGrid;
    Free_object *freeObjects;

public:
    void PlaceFreeOnGrid();

};

#endif