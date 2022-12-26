#include "Level.h"
#include "FloorTile.h"
#include "System.h"

namespace mojosabel{
    
    void Level::fillTilemap(std::string tag)
    {
        for(int x = 0; x < MAP_WIDTH; x++)
        {
            for(int y = 0; y < MAP_HEIGHT; y++)
            {
                if(tag == "Floor")
                {
                    tilemap(x, y)->add(new FloorTile(x * TILE_SIZE, y * TILE_SIZE));
                } else if(tag == "Wall")
                {
                    //hdhdhd
                }
            }
        }
    }

    void Level::drawTiles()
    {
        for(int x = 0; x < MAP_WIDTH; x++)
        {
            for(int y = 0; y < MAP_HEIGHT; y++)
            {
                tilemap(x, y)->getTopLayer()->draw();
            }
        }
    }
}