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
        std::vector<Enemy*> levelEnemies;
        int intMap[MAP_WIDTH][MAP_HEIGHT];
        int smoothMapCount, randomFillProcent, smoothWalkableLimit, smoothUnwalkableLimit;
        std::vector<Enemy*>& getLevelEnemies() { return levelEnemies; }
        void genereateIntMap();
        void randomFillIntMap();
        void smoothMap();
        void mixMap(Level* level);
        int getSurroundingWallCount(int tileX, int tileY);
        void generateEnemies(Level* level);
    };
}

#endif