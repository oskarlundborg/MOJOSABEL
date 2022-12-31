#include "MapGenerator.h"
#include "Constants.h"
#include <iostream>

namespace mojosabel {

    void MapGenerator::genereateIntMap()
    {
        randomFillIntMap();
        for(int i = 0; i < smoothMapCount; i++)
        {
            smoothMap();
        }
    }

    void MapGenerator::randomFillIntMap()
    {
        for(int x = 0; x < MAP_WIDTH; x++)
        {
            for(int y = 0; y < MAP_HEIGHT; y++)
            {
                int i = rand() % 20 + 40;
                intMap[x][y] = (i < randomFillProcent) ? 1 : 0;
            }
        }
    }

    void MapGenerator::mixMap(Level* level)
    {
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
        level->checkForFloor();
        generateEnemies(level);
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

    void MapGenerator::smoothMap()
    {
        for(int x = 0; x < MAP_WIDTH; x ++)
        {
            for(int y = 0; y < MAP_HEIGHT; y ++)
            {
                int neighbourWalls = getSurroundingWallCount(x, y);
                if (neighbourWalls > smoothUnwalkableLimit)
                {
                    intMap[x][y] = 1;
                } else if (neighbourWalls < smoothWalkableLimit)
                {
                    intMap[x][y] = 0;
                }
            }
        }
    }

    void MapGenerator::generateEnemies(Level* level) //ska inte ligga här, kanske gameObjectgenerator?
    {
        int random = rand() % 10 + 10;
        
        for(int i = 0; i < random; i++){
            Vector2 spawnPos = level->generateSpawnPosition();
            int spawnX = spawnPos.x;
            int spawnY = spawnPos.y;
            Enemy* enemy = new Enemy(spawnX, spawnY, 32, 32, 0, "Enemy", 1);
            enemy->loadTexture(constants::gResPath + "images/Spaceship.png");
            enemy->setCollision(true);
            levelEnemies.push_back(enemy);
        }
    }
}