#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Session.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

using namespace mojosabel;

int main(int argc, char* argv[]){

    std::cout << "Fuck world!" << std::endl;

    std::cout << "warhammer rocks" << std::endl;
    
    Session ses;

    ses.run();


    std::cout << "hej då!" << std::endl;

    return 0;
}