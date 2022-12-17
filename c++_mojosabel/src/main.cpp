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
#include "PlayerEntity.h"
#include "BulletEntity.h"

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

    if(sys.isWithinBounds(1, 1)){
        std::cout << "In bounds" << std::endl;
    }

    if(sys.isWithinBounds(-1, -1)){
        std::cout << "Out of bounds" << std::endl;
    }

    if(sys.isWithinBounds(1281, 721)){
        std::cout << "Out of bounds" << std::endl;
    }
    
    Session ses;

    UI = ses.getRootCanvas();
    UI->addUiSprite(Ui_label::getInstance(0, 0, 100, 25, "MOJOSABEL"));
    
    // Old Player object
        // Player* player = Player::getInstance(200, 200, 50, 50);
        // ses.add(player);
        // player->loadTexture(constants::gResPath + "images/Spaceship.png");
        // player->setSpeed(3);


    PlayerEntity* player = new PlayerEntity(100, 100, 0, 0, 1, 3, 5);
    std::cout << player->x << std::endl;
    player->loadTexture(constants::gResPath + "images/Spaceship.png");
    ses.add(player);

    BulletEntity* bullet = new BulletEntity(500, 500, 0, -16, 1);
    bullet->loadTexture(constants::gResPath + "images/Bullet.png");
    bullet->player = player;
    ses.add(bullet);


    Ui_label* lbl = Ui_label::getInstance(235, 0, 25, 25, "0");
	ses.add(lbl);

    Ui_button* b1 = new IncreaseButton(lbl);
    ses.add(b1);

    Ui_button* b2 = new DecreaseButton(lbl);
    ses.add(b2);

    ses.run();

    std::cout << "***done***" << std::endl;

    return 0;
}

/*
    - Klasshierarkin och sprites + components
    - DLL-processen - mer info om library?
    - canvas position hantering
*/