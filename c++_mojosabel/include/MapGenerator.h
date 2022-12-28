#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <string>
#include "System.h"
#include "Level.h"

namespace mojosabel {
    class MapGenerator
    {
    public:
        int intMap[MAP_WIDTH][MAP_HEIGHT];
        int randomFillProcent = 49;
        bool useRandomSeed = true;

        MapGenerator();
        void genereateIntMap(int smoothCount);
        void randomFillIntMap();
        void smoothMap();
        void mixMap(Level* level);
        int getSurroundingWallCount(int tileX, int tileY);
    };
}

#endif