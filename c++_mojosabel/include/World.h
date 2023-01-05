#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Level.h"
#include "MapGenerator.h"


namespace mojosabel {
    
    class World
    {
    private:
        int currentLevel;
        MapGenerator* mapGenerator;
        std::vector<Level*> levels;
        
    public:
        World() : World(3, 49, 4, 4) {}
        World(const World* other) = delete;
        const World operator=(const World& rhs) = delete;
        World(int smoothMap, int fillPercent, int smoothWalkableLimit, int smoothUnwalkableLimit);
        void newLevel(std::string walkableTexturePath, std::string unwalkableTexturePath);
        void drawCurrentLevel();
        Level* getCurrentLevel() { return levels[currentLevel]; }
        MapGenerator* getMapGenerator() { return mapGenerator; }
        ~World();
    };
}

#endif