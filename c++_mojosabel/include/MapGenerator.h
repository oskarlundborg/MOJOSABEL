#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <string>
#include "System.h"
#include "Level.h"

namespace mojosabel {
    class MapGenerator
    {
    public:
        int intMap[MAP_WIDTH][MAP_HEIGHT];
        int randomFillProcent = 52;
        bool useRandomSeed = true;

        MapGenerator();
        void genereateIntMap();
        void randomFillIntMap();
        void smoothMap();
        void mixMap(Level* level);
    };
}

#endif