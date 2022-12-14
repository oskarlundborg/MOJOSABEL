#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Session.h"
#include "Ui_label.h"
#include "Ui_sprite.h"
#include "Ui_button.h"
#include "Canvas.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

using namespace mojosabel;

int value = 0;
Canvas* UI;

class IncreaseButton : public Ui_button
{
public:
    IncreaseButton(Ui_label *lbl) : Ui_button(100, 100, 150, 70, "Oka"), ui_label(lbl) {}
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
    DecreaseButton(Ui_label *lbl) : Ui_button(600, 100, 150, 70, "Minska"), ui_label(lbl) {}
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

    Session ses;
    UI = ses.getRootCanvas();
    UI->addUiSprite(Ui_label::getInstance(270, 300, 150, 70, "MOJOSABEL"));

    Ui_label* lbl = Ui_label::getInstance(270, 100, 150, 70, "0");
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