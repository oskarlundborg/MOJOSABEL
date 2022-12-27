#include "Level.h"
#include "FloorTile.h"
#include "WallTile.h"
#include "System.h"
#include "Session.h"

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
                    tilemap(x, y)->add(new WallTile(x * TILE_SIZE, y * TILE_SIZE));
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

    void Level::easyFill(int x, int y, std::string tag){
        if(tag == "Floor")
        {
            tilemap(x, y)->add(new FloorTile(x * TILE_SIZE, y * TILE_SIZE));
        } else if(tag == "Wall")
        {
            WallTile* wallTile = new WallTile(x * TILE_SIZE, y * TILE_SIZE);
            tilemap(x, y)->add(wallTile);
            ses.add(wallTile);
        }
    }
}