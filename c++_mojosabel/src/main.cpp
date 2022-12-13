#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Session.h"
#include "Ui_label.h"
#include "Ui_sprite.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

using namespace mojosabel;

int main(int argc, char* argv[]){
    
    std::cout << "Hej bitch" << std::endl;

    Session ses;

    Label* lbl = Label::getInstance(270, 100, 100, 70, "yay kod!");
	ses.add(lbl);
    ses.run();

    std::cout << "hej då bitch" << std::endl;

    return 0;
}