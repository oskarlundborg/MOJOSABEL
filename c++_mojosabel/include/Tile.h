#ifndef TILE_H
#define TILE_H

#include "Grid_object.h"

namespace mojosabel {
   class Tile {
    private:
        Grid_object *content;

    public:
        void DrawContents();

    }; 
}


#endif