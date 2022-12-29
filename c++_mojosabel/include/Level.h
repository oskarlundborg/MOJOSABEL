#ifndef LEVEL_H
#define LEVEL_H

#include "Tilemap.h"


namespace mojosabel {
class Level {
    private:
        Tilemap tilemap;

    public:
        std::vector<Vector2> floorTiles;
        void fillTilemap(std::string tag);
        void drawTiles();
        void easyFill(int x, int y, std::string tag);
        void checkForFloor();
        bool isTileWall(int x, int y);
        Vector2 generateSpawnPosition(); // möjligen enemypointer 
 };
}


#endif