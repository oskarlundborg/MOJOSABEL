#include <iostream>
#include <SDL2/SDL.h>
#include "Session.h"
#include "System.h"

namespace mojosabel {

    
    Session::Session()
    {
        std::cout << "Hej det funkar, session" << std::endl;
        rootCanvas = new Canvas();
    }

    void Session::add(Sprite* spriteToAdd)
    {
        sprites.push_back(spriteToAdd); 
    }

    void Session::doKeyUp(SDL_KeyboardEvent *event)
    {
        if (event->keysym.scancode < MAX_KEYBOARD_KEYS)
        {
            sys.keyboard[event->keysym.scancode] = 0;
        }
    }

    void Session::doKeyDown(SDL_KeyboardEvent *event)
    {
        if (/*event->repeat == 0 && */ event->keysym.scancode < MAX_KEYBOARD_KEYS)
        {
            sys.keyboard[event->keysym.scancode] = 1;
        }
    }

    void Session::run()
    {
        bool quit = false;
        while(!quit)
        {
            SDL_Event event;
            while(SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                    case SDL_QUIT:
                        quit = true;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        for (Sprite* s : sprites)
                        {
                            s -> mouseDown(event);
                        }
                        break;
                    case SDL_MOUSEBUTTONUP:
                        for (Sprite* s : sprites)
                        {
                            s -> mouseUp(event);
                        }
                        break;
                    case SDL_KEYDOWN:
                        doKeyDown(&event.key);
                        break;
                    case SDL_KEYUP:
                        doKeyUp(&event.key);
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
            rootCanvas->drawSprites();
            SDL_RenderPresent(sys.getRen());
        }
    }

    Session::~Session(){
        
    }
}
