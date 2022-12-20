#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Entity.h"
#include "Session.h"

namespace mojosabel{

    class GameObject : public Entity
    {
    private:

    public:
        GameObject() : Entity(0, 0, 0, 0, 0, "unkown") {}
        GameObject(float x, float y, int w, int h, int layer, std::string name) 
            : Entity(x, y, w, h, layer, name) {}
        void instantiate(Entity* entity);
        void destroy();
    };
}




#endif