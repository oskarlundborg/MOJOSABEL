#include <iostream>
#include <SDL2/SDL.h>
#include "Session.h"
#include "System.h"

namespace mojosabel {
    
    Session::Session()
    {
        std::cout << "Hej det funkar, session" << std::endl;
    }

    void Session::run(){
        bool quit = false;
        while(!quit){
            SDL_Event eve;
            while(SDL_PollEvent(&eve)){
                switch(eve.type){
                    case SDL_QUIT:
                        quit = true;
                        break;
                    default:
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(sys.getRen(), 255, 255, 255, 255);
        SDL_RenderClear(sys.getRen());
        SDL_RenderPresent(sys.getRen());
    }

    Session::~Session(){
        
    }
}
