#include "MapGenerator.h"

namespace mojosabel {
    MapGenerator::MapGenerator(){
        genereateIntMap();
    }

    void MapGenerator::genereateIntMap(){
        randomFillIntMap();
        //iterera smoothMap() några ggr
    }

    void MapGenerator::randomFillIntMap(){
        if (useRandomSeed){
            //std::size_t seedHash = std::hash<std::string>()(seed);
            //seedHash = rand() % 60 + 40;
            for(int x = 0; x < MAP_WIDTH; x++)
            {
                for(int y = 0; y < MAP_HEIGHT; y++)
                {
                    int i = rand() % 60 + 40;
                    intMap[x][y] = (i < randomFillProcent) ? 1 : 0;
                }
            }
        }
    }

    void MapGenerator::mixMap(Level* level){
        for(int x = 0; x < MAP_WIDTH; x++)
            {
                for(int y = 0; y < MAP_HEIGHT; y++)
                {
                    if (intMap[x][y] == 1){
                        level->easyFill(x, y, "Wall");
                    } else if (intMap[x][y] == 0){
                        level->easyFill(x, y, "Floor");
                    }
                }
            }
    }
}