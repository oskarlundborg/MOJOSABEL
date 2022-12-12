#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Session.h"
#include "Label.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

using namespace mojosabel;

int main(int argc, char* argv[]){
    
    std::cout << "Hej bitch" << std::endl;

    Session ses;

    Label* lbl = Label::getInstance(270, 100, 100, 70, "Hej jag heter isabel");
	ses.add(lbl);
    std::cout << "item added" << std::endl;

    ses.run();

    std::cout << "hej då bitch" << std::endl;

    return 0;
}