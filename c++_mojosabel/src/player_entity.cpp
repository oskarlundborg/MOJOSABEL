#include <iostream>
#include "Player_Entity.h"
#include "Bullet_Entity.h"
#include "System.h"
#include "Constants.h"

namespace mojosabel {

    Player_Entity::Player_Entity() : Entity()
    {
        health = 0;
        speed = 0;
    }

    Player_Entity::Player_Entity(float x, float y, int w, int h, int layer, std::string name, float sp)
        : Entity (x, y, w, h, layer, name)
    {
        speed = sp;
    }

    void Player_Entity::update()
    {
        move();
    }
    void Player_Entity::move()
    {
        if(sys.keyboard[SDL_SCANCODE_W]) { yPos -= speed; }
        if(sys.keyboard[SDL_SCANCODE_S]) { yPos += speed; }
        if(sys.keyboard[SDL_SCANCODE_A]) { xPos -= speed; }
        if(sys.keyboard[SDL_SCANCODE_D]) { xPos += speed; }
    }

    void Player_Entity::mouseDown(SDL_Event event)
    {
        fire();
    }

    void Player_Entity::fire()
    {
        Bullet_Entity *bullet = new Bullet_Entity(xPos, yPos, 0, 0, 0, "bullet", 4);
        bullet->loadTexture(constants::gResPath + "images/Bullet.png");
        sessionAdded->push_back(bullet);
        bullet->setSession(sessionRemoved, sessionAdded);
    }
}