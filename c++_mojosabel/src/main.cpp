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

int main(int argc, char* argv[]) 
{

    std::cout << "***main***" << std::endl;

    UI = ses.getRootCanvas();
    UI->addUiSprite(Ui_label::getInstance(0, 0, 100, 25, "MOJOSABEL"));

    Player* player = new Player(100, 100, 32, 32, 0, "Player", 3);
    player->loadTexture(constants::gResPath + "images/Spaceship.png");
    ses.add(player);

    Enemy* enemy = new Enemy(500, 500, 32, 32, 0, "Enemy", 1);
    enemy->loadTexture(constants::gResPath + "images/Spaceship.png");
    enemy->setCollision(true);
    ses.add(enemy);

    Ui_label* lbl = Ui_label::getInstance(235, 0, 25, 25, "0");
	ses.addSprite(lbl);

    Ui_button* b1 = new IncreaseButton(lbl);
    ses.addSprite(b1);

    Ui_button* b2 = new DecreaseButton(lbl);
    ses.addSprite(b2);
    
    ses.run();

    std::cout << "***done***" << std::endl;

    return 0;
}

/*
    - Klasshierarkin och sprites + components
    - DLL-processen - mer info om library?
    - canvas position hantering
*/