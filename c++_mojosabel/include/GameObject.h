#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Entity.h"

namespace mojosabel {

    class GameObject : public Entity
    {
    private:
         
    public:
        GameObject() : Entity(0, 0, 0, 0, 0, "Unkown") {}
        GameObject(int x, int y, int w, int h, int layer, std::string tag) 
            : Entity(x, y, w, h, layer, tag) {}
        void instantiate(Entity* entity);
        void destroy(Entity* entity);
    };
}

#endif