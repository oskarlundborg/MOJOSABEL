#include <iostream>
#include <SDL2/SDL.h>
#include "Session.h"
#include "System.h"

namespace mojosabel {

    
    Session::Session()
    {
        std::cout << "Hej det funkar, session" << std::endl;
    }

    void Session::add(Sprite* spriteToAdd)
    {
        sprites.push_back(spriteToAdd);
        
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
                }
            }
            //std::cout << "while klar" << std::endl;
            SDL_SetRenderDrawColor(sys.getRen(), 255, 255, 255, 255);
            SDL_RenderClear(sys.getRen());
            for (Sprite* s : sprites)
            {
                s->draw();
                //std::cout << "yay draw" << std::endl;
            }
            SDL_RenderPresent(sys.getRen());
        }
    }

    Session::~Session(){
        
    }
}
