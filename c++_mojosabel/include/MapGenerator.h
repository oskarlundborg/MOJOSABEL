#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <string>
#include "System.h"
#include "Level.h"
#include "Enemy.h"

namespace mojosabel {
    class MapGenerator
    {
    private:
        int smoothMapCount, randomFillProcent, smoothWalkableLimit, smoothUnwalkableLimit;
        int intMap[MAP_WIDTH][MAP_HEIGHT];
        int getSurroundingWallCount(int tileX, int tileY);
        void randomFillIntMap();
        void smoothMap();

    public:
        MapGenerator(int smoothMap, int fillPercent, int smoothWalkableLimit, int smoothUnwalkableLimit)
            : smoothMapCount(smoothMap), randomFillProcent(fillPercent), smoothWalkableLimit(smoothWalkableLimit), smoothUnwalkableLimit(smoothUnwalkableLimit) {}
        void genereateIntMap();
        void mixMap(Level* level);
    };
}

#endif