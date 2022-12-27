#ifndef LEVEL_H
#define LEVEL_H

#include "Tilemap.h"


namespace mojosabel {
class Level {
    private:
        Tilemap tilemap;

    public:
        void fillTilemap(std::string tag);
        void drawTiles();
        void easyFill(int x, int y, std::string tag);

 };
}


#endif