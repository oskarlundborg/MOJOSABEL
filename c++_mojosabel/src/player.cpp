#include <iostream>
#include "Player.h"
#include "Bullet.h"
#include "System.h"
#include "Constants.h"

namespace mojosabel {

    Player::Player() : GameObject()
    {
        health = 0;
        speed = 0;
    }

    Player::Player(float x, float y, int w, int h, int layer, std::string name, float sp)
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
        if(sys.keyboard[SDL_SCANCODE_W]) { yPos -= speed; }
        if(sys.keyboard[SDL_SCANCODE_S]) { yPos += speed; }
        if(sys.keyboard[SDL_SCANCODE_A]) { xPos -= speed; }
        if(sys.keyboard[SDL_SCANCODE_D]) { xPos += speed; }
    }

    void Player::mouseDown(SDL_Event event)
    {
        fire();
    }

    void Player::fire()
    {
        Bullet *bullet = new Bullet(xPos, yPos, 0, 0, 0, "bullet", 4);
        bullet->loadTexture(constants::gResPath + "images/Bullet.png");
        instantiate(bullet);
    }
}