#include "MapGenerator.h"
#include <iostream>

namespace mojosabel {
    MapGenerator::MapGenerator(){
        genereateIntMap(3);
    }

    void MapGenerator::genereateIntMap(int smoothCount){
        randomFillIntMap();
        for(int i = 0; i < smoothCount; i++){
            smoothMap();
        }
    }

    void MapGenerator::randomFillIntMap(){
        if (useRandomSeed){
            //std::size_t seedHash = std::hash<std::string>()(seed);
            //seedHash = rand() % 60 + 40;
            for(int x = 0; x < MAP_WIDTH; x++)
            {
                for(int y = 0; y < MAP_HEIGHT; y++)
                {
                    int i = rand() % 20 + 40;
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

    int MapGenerator::getSurroundingWallCount(int tileX, int tileY){
        int wallCount = 0;
        for(int neighbourX = tileX - 1; neighbourX <= tileX + 1; neighbourX ++){
            for(int neighbourY = tileY - 1; neighbourY <= tileY + 1; neighbourY ++){
                if (neighbourX >= 0 && neighbourX < MAP_WIDTH && neighbourY >= 0 && neighbourY < MAP_HEIGHT){
                    if (neighbourX != tileX || neighbourY != tileY){
                        wallCount += intMap[neighbourX][neighbourY];
                    }
                } else {
                    wallCount ++;
                }
            }
        }
        //std::cout << wallCount << std::endl;
        return wallCount;
    }

    void MapGenerator::smoothMap(){
        for(int x = 0; x < MAP_WIDTH; x ++){
            for(int y = 0; y < MAP_HEIGHT; y ++){
                int neighbourWalls = getSurroundingWallCount(x, y);
                if (neighbourWalls > 5){
                    intMap[x][y] = 1;
                } else if (neighbourWalls < 4){
                    intMap[x][y] = 0;
                }
            }
        }
    }
}