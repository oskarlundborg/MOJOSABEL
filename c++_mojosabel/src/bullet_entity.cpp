#include <SDL2/SDL_image.h>

#include "BulletEntity.h"
#include "System.h"

namespace mojosabel {
    
    void BulletEntity::update()
    {   
        if (sys.keyboard[SDL_SCANCODE_LCTRL] && health == 0)
        {
            health = 1;
            x = player->x;
            y = player->y;
        }
        if (y < 0)
		{
			health = 0;
		}
        move();
        draw(texture, x, y);
    }

    void BulletEntity::move()
    {
        x += dx;
		y += dy;
    }
}
