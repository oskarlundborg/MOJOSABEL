#include "World.h"
#include "MapGenerator.h"

namespace mojosabel {
    World::World()
    {
        currentLevel = 0;
        mapGenerator = new MapGenerator();
        newLevel();
    }

    void World::newLevel()
    {
        Level* level = new Level();
        levels.push_back(level);
        mapGenerator->genereateIntMap(3);
        mapGenerator->mixMap(level);
    }

    void World::drawCurrentLevel()
    {
        levels[currentLevel]->drawTiles();
    }
}