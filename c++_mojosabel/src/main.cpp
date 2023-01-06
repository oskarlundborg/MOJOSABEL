#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Session.h"
#include "Ui_label.h"
#include "Ui_sprite.h"
#include "Ui_button.h"
#include "Canvas.h"
#include "Player.h"
#include "Constants.h"
#include "Entity.h"
#include "Enemy.h"
#include "MapGenerator.h"
#include "GameObjectGenerator.h"


using namespace mojosabel;

int value = 0;
Canvas* UI;



void nextLevelFunc()
{
    ses.getWorld()->newLevel("images/WaterTile.png", "images/GrassTile.png");
};

void enemiesToNextLevel()
{
    generateGameObjects<Enemy>(ses.getWorld()->getCurrentLevel(), ses.getWorld()->getCurrentLevelIndex() + 5, "images/Spaceship.png", true);
}

int main(int argc, char* argv[]) 
{

    std::cout << "***main***" << std::endl;

    UI = ses.getRootCanvas();
    UI->addUiSprite(Ui_label::getInstance((SCREEN_WIDTH/2 -100), 0, 400, 100, "WOW SEA ADVENTURE 400"));

    ses.createNewWorld(2, 48, 5, 4);
    ses.getWorld()->newLevel("images/WaterTile.png", "images/GrassTile.png");

    Vector2 spawnPos = ses.getWorld()->getCurrentLevel()->generateSpawnPosition();
    int spawnX = spawnPos.x;
    int spawnY = spawnPos.y;
    Player* player = new Player(spawnX, spawnY, 32, 32, 0, 3);
    player->loadTexture(constants::gResPath + "images/Spaceship.png");
    ses.add(player);

    generateGameObjects<Enemy>(ses.getWorld()->getCurrentLevel(), 5, "images/Spaceship.png", true );

    ses.addLoadLevelFunc(nextLevelFunc);
    ses.addLoadLevelFunc(enemiesToNextLevel);

    
    
    ses.run();

    std::cout << "***done***" << std::endl;

    return 0;
}

