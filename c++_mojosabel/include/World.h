#ifndef WORLD_H
#define WORLD_H

#include "Level.h"
#include <vector>

namespace mojosabel {
    class World{
    private:
        std::vector<Level*> levels;

    public:
        World();
        int currentLevel;
        void newLevel();
        void drawCurrentLevel();
        Level* getCurrentLevel() { return levels[currentLevel]; }

    };
}

#endif