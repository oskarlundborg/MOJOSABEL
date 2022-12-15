#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>
#include <SDL2/SDL.h>
#include "Component.h"


namespace mojosabel {

    class Game_object 
    {
    private:
        int layer = 0;
        SDL_Rect* rect; 
        std::vector<Component*> comps; //kanske map
        
    protected:

    public:
        Game_object();
        void start(); // körs av session i början av run()
        void doUpdate(); //kallar på update, automatiskt rendera vår image om vi har en, om gameobject flyttas osv
        void update(); //virtuell, 
        //void fixedUpdate() ?
        void addComponent(Component* compToAdd);
    };
}

#endif