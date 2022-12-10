#include <SDL2/SDL.h>
#include <string>
#include "../include/Session.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

using namespace mojosabel;

int main(int argc, char* argv[]){
    
    Session ses;

    ses.run();

    return 0;
}