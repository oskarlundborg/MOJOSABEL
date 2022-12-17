#include <SDL2/SDL_image.h>

#include "BulletEntity.h"
#include "System.h"

namespace mojosabel {

    SDL_Texture* BulletEntity::loadTexture(std::string filename)
    {
        SDL_Texture *texture;
        texture = IMG_LoadTexture(sys.getRen(), (filename).c_str());
        return texture;
    }

    void BulletEntity::draw(SDL_Texture* tex, int x, int y)
    {
        SDL_Rect rect;

        rect.x = x;
        rect.y = y;

        SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
        SDL_RenderCopy(sys.getRen(), texture, NULL, &rect);
    }
    
    void BulletEntity::update()
    {   
        if (sys.keyboard[SDL_SCANCODE_LCTRL] && health == 0)
        {
            health = 1;
            x = player->x;
            y = player->y;
        }
        move();
        if (x > SCREEN_WIDTH)
		{
			health = 0;
		}
    }

    void BulletEntity::move()
    {
        dx = 16;
		dy = 0;
        x += dx;
		y += dy;
    }
}
