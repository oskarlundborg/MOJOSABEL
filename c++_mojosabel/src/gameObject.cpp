#include "GameObject.h"
#include "Session.h"

namespace mojosabel
{
    void GameObject::instantiate(Entity* entity)
    {
        if (entity != this)
        {
            ses.add(entity);
        }
    }

    void GameObject::destroy(Entity* entity)
    {
        ses.remove(entity);
    }
} 
