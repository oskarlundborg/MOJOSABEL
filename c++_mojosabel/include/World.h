#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Level.h"
#include "MapGenerator.h"


namespace mojosabel {
    
    class World
    {
    private:
        std::vector<Level*> levels;
        MapGenerator* mapGenerator;
        int currentLevel;
        
    public:
        World() : World(3, 49, 4, 4) {}
        World(int smoothMap, int fillPercent, int smoothWalkableLimit, int smoothUnwalkableLimit);
        void newLevel(std::string walkableTexturePath, std::string unwalkableTexturePath);
        void drawCurrentLevel();
        Level* getCurrentLevel() { return levels[currentLevel]; }
        MapGenerator* getMapGenerator() { return mapGenerator; }
    };
}

#endif