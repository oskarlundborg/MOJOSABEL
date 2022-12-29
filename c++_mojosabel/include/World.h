#ifndef WORLD_H
#define WORLD_H

#include "Level.h"
#include "MapGenerator.h"
#include <vector>

namespace mojosabel {
    class World{
    private:
        std::vector<Level*> levels;
        MapGenerator* mapGenerator;
        
    public:
        World();
        int currentLevel;
        void newLevel();
        void drawCurrentLevel();
        Level* getCurrentLevel() { return levels[currentLevel]; }
        MapGenerator* getMapGenerator() { return mapGenerator; }
    };
}

#endif