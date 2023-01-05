#include <string>
#include "World.h"

namespace mojosabel {
    
    World::World(int smoothMap, int fillPercent, int smoothWalkableLimit, int smoothUnwalkableLimit)
    {
        mapGenerator = new MapGenerator(smoothMap, fillPercent, smoothWalkableLimit, smoothUnwalkableLimit);
    }

    void World::newLevel(std::string walkableTexturePath, std::string unwalkableTexturePath)
    {
        if (levels.size() == 0)
        {
            currentLevel = 0;
        }
        else 
        {
            currentLevel++;
        }
        Level* level = new Level(walkableTexturePath, unwalkableTexturePath); 
        levels.push_back(level);
        mapGenerator->genereateIntMap();
        mapGenerator->mixMap(level);
    }

    void World::drawCurrentLevel()
    {
        levels[currentLevel]->drawTiles();
    }

    World::~World()
    {
        for (Level* p : levels) { delete p; }
        levels.clear();
        delete mapGenerator;
    }
}