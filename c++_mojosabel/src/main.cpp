#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Session.h"
#include "Ui_label.h"
#include "Ui_sprite.h"
#include "Ui_button.h"
#include "Canvas.h"
#include "Player_Entity.h"
#include "Constants.h"
#include "Entity.h"


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

    // if(sys.isWithinBounds((float)1, (float)1)){
    //     std::cout << "In bounds" << std::endl;
    // }

    // if(sys.isWithinBounds((float)-1, (float)-1)){
    //     std::cout << "Out of bounds" << std::endl;
    // }

    // if(sys.isWithinBounds((float)1281, (float)721)){
    //     std::cout << "Out of bounds" << std::endl;
    // }
    
    Session ses;

    UI = ses.getRootCanvas();
    UI->addUiSprite(Ui_label::getInstance(0, 0, 100, 25, "MOJOSABEL"));

    Player_Entity* player = new Player_Entity(100, 100, 0, 0, 0, "spaceship", 3);
    player->loadTexture(constants::gResPath + "images/Spaceship.png");
    ses.add(player);

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