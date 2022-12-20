#include "GameObject.h"

namespace mojosabel
{
    void GameObject::instantiate(Entity* entity)
    {
        if (entity != this)
        {
            ses.add(entity);
        }
    }

    void GameObject::destroy()
    {
        ses.remove(this);
    }
} 
