#include "World.h"

namespace mojosabel{
    World::World(){
        currentLevel = 0;
        newLevel();
    }

    void World::newLevel(){
        Level* level = new Level();
        levels.push_back(level);
        level->fillTilemap("Floor");
    }

    void World::drawCurrentLevel(){
        levels[currentLevel]->drawTiles();
    }
}