#include <iostream>
#include "Player.h"
#include "Bullet.h"
#include "System.h"
#include "Constants.h"
#include "Session.h"

namespace mojosabel {

    Player::Player() : GameObject()
    {
        health = 0;
        speed = 0;
    }

    Player::Player(int x, int y, int w, int h, int layer, std::string name, int sp)
        : GameObject (x, y, w, h, layer, name)
    {
        speed = sp;
    }
    
    void Player::update()
    {
        move();
    }

    void Player::move()
    {
        if(sys.keyboard[SDL_SCANCODE_W] && !(checkDirection("Up"))) { rect.y -= speed; }
        if(sys.keyboard[SDL_SCANCODE_S] && !(checkDirection("Down"))) { rect.y += speed; }
        if(sys.keyboard[SDL_SCANCODE_A] && !(checkDirection("Left"))) { rect.x -= speed; }
        if(sys.keyboard[SDL_SCANCODE_D] && !(checkDirection("Right"))) { rect.x += speed; }
    }

    void Player::mouseDown(SDL_Event event)
    {
        fire(event.button.x, event.button.y);
    }

    void Player::fire(int x, int y)
    {
        Bullet *bullet = new Bullet(rect.x, rect.y, 0, 0, 0, "Bullet", 30, x, y);
        bullet->loadTexture(constants::gResPath + "images/Bullet.png");
        bullet->resizeToImage();
        bullet->setCollision(true);
        instantiate(bullet);
        hasColliders();
    }
}