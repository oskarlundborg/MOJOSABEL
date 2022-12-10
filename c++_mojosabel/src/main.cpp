#include <SDL2/SDL.h>
#include "Session.h"
#include <string>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400


int main(int argc, char* argv[]){
    
    Session ses;

    ses.run();

    return 0;
}