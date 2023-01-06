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

class IncreaseButton : public Ui_button
{
    public:
        IncreaseButton(Ui_label *lbl) : Ui_button(150, 0, 50, 25, "Oka"), ui_label(lbl) {}
        void perform(Ui_button* source)
        {
            value++;
            ui_label -> setText(std::to_string(value));
        }
    private:
        Ui_label* ui_label;
};

class DecreaseButton : public Ui_button
{
    public:
        DecreaseButton(Ui_label *lbl) : Ui_button(300, 0, 100, 25, "Minska"), ui_label(lbl) {}
        void perform(Ui_button* source)
        {
            value--;
            ui_label -> setText(std::to_string(value));
        }
    private:
        Ui_label* ui_label;
};

void nextLevelFunc()
{
    ses.getWorld()->newLevel("images/GrassTile.png", "images/GrayWall.png");
};

void enemiesToNextLevel()
{
    generateGameObjects<Enemy>(ses.getWorld()->getCurrentLevel(), ses.getWorld()->getCurrentLevelIndex() + 5, "images/Spaceship.png", true);
}

int main(int argc, char* argv[]) 
{

    std::cout << "***main***" << std::endl;

    UI = ses.getRootCanvas();
    UI->addUiSprite(Ui_label::getInstance(0, 0, 100, 25, "MOJOSABEL"));

    ses.createNewWorld(2, 48, 5, 4);
    ses.getWorld()->newLevel("images/GrassTile.png", "images/GrayWall.png");

    Vector2 spawnPos = ses.getWorld()->getCurrentLevel()->generateSpawnPosition();
    int spawnX = spawnPos.x;
    int spawnY = spawnPos.y;
    Player* player = new Player(spawnX, spawnY, 32, 32, 0, 3);
    player->loadTexture(constants::gResPath + "images/Spaceship.png");
    ses.add(player);

    generateGameObjects<Enemy>(ses.getWorld()->getCurrentLevel(), 5, "images/Spaceship.png", true );

    ses.addLoadLevelFunc(nextLevelFunc);
    ses.addLoadLevelFunc(enemiesToNextLevel);

    Ui_label* lbl = Ui_label::getInstance(235, 0, 25, 25, "0");
	UI->addUiSprite(lbl);

    Ui_button* b1 = new IncreaseButton(lbl);
    UI->addUiSprite(b1);

    Ui_button* b2 = new DecreaseButton(lbl);
    UI->addUiSprite(b2);
    
    ses.run();

    std::cout << "***done***" << std::endl;

    return 0;
}

/*
    - Klasshierarkin och sprites + components
    - DLL-processen - mer info om library?
    - canvas position hantering
*/