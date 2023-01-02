#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <string>
#include "System.h"
#include "Level.h"
#include "Enemy.h"

namespace mojosabel {
    class MapGenerator
    {
    public:
        MapGenerator(int smoothMap, int fillPercent, int smoothWalkableLimit, int smoothUnwalkableLimit)
            : smoothMapCount(smoothMap), randomFillProcent(fillPercent), smoothWalkableLimit(smoothWalkableLimit), smoothUnwalkableLimit(smoothUnwalkableLimit) {}
        int intMap[MAP_WIDTH][MAP_HEIGHT];
        int smoothMapCount, randomFillProcent, smoothWalkableLimit, smoothUnwalkableLimit;
        void genereateIntMap();
        void randomFillIntMap();
        void smoothMap();
        void mixMap(Level* level);
        int getSurroundingWallCount(int tileX, int tileY);
    };
}

#endif