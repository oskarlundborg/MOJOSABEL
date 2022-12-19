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

    void Session::add(Entity* entityToAdd)
    {
        addedEntities.push_back(entityToAdd); 
        entityToAdd->setSession(&removedEntities, &addedEntities);
    }

    void Session::remove(Entity* entityToRemove)
    {
        removedEntities.push_back(entityToRemove); // göra en removed ses i entity?
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

    void Session::capFrameRate (long *renderTime, float *remainder)
    {
        long wait, frameTime;

        wait = 16 + *remainder; 

        *remainder -= (int)*remainder;

        frameTime = SDL_GetTicks() - *renderTime;

        wait -= frameTime;

        if (wait < 1) { wait = 1; }

        SDL_Delay(wait);

        *remainder += 0.667;

        *renderTime = SDL_GetTicks();
    }

    void Session::run()
    {
        renderTime = SDL_GetTicks();
        remainder = 0;
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
                        for (Entity* e : entities)
                        {
                            e -> mouseDown(event);
                        }
                        break;
                    case SDL_MOUSEBUTTONUP:
                        for (Sprite* s : sprites)
                        {
                            s -> mouseUp(event);
                        }
                        for (Entity* e : entities)
                        {
                            e -> mouseUp(event);
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

            
            SDL_SetRenderDrawColor(sys.getRen(), 255, 255, 255, 255);
            SDL_RenderClear(sys.getRen());

            // Uppdaterar och ritar entities
            for (Entity* e : entities)
            {
                e->sneakyUpdate();
            }
 
            for (Entity* e : addedEntities)
            {
                entities.push_back(e);
            }
            addedEntities.clear();
            
            

            for (Entity* e : removedEntities)
            {
                for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end();)
                {
                    if (*it == e)
                    {
                        delete e;
                        it = entities.erase(it);
                    }
                    else 
                    {
                        it++;
                    }
                }
            }
            removedEntities.clear();
            
          
            // Ritar sprite objekt
            for (Sprite* s : sprites)
            {
                s->draw();
            }
            rootCanvas->drawSprites();
            SDL_RenderPresent(sys.getRen());
            capFrameRate(&renderTime, &remainder);
        }
    }

    Session::~Session(){
        
    }
}
