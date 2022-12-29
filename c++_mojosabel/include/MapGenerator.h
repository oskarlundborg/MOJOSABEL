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
        std::vector<Enemy*> levelEnemies;
        int intMap[MAP_WIDTH][MAP_HEIGHT];
        int randomFillProcent = 49;
        bool useRandomSeed = true;

        std::vector<Enemy*>& getLevelEnemies() { return levelEnemies; }
        void genereateIntMap(int smoothCount);
        void randomFillIntMap();
        void smoothMap();
        void mixMap(Level* level);
        int getSurroundingWallCount(int tileX, int tileY);
        void generateEnemies(Level* level);
    };
}

#endif