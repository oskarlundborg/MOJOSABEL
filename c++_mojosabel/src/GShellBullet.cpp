#include "GShellBullet.h"
#include "GCrocodile.h"

void GShellBullet::onCollision(Collision<Entity> collision)
{
    if (collision.tag == "Enemy") 
    { 
        int enemyHealth = static_cast<GCrocodile*>(collision.object)->getHealth();
        static_cast<GCrocodile*>(collision.object)->setHealth(enemyHealth - damage);
        static_cast<GCrocodile*>(collision.object)->checkHealth();
    }

    if (collision.tag == "Wall")
    {
        destroy(this);
    }
}