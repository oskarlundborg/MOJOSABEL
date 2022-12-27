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
        hasCollision = true;
    }

    Player::Player(int x, int y, int w, int h, int layer, std::string name, int sp)
        : GameObject (x, y, w, h, layer, name)
    {
        speed = sp;
        hasCollision = true;
    }
    
    void Player::update()
    {
        move();
    }

    void Player::move()
    {
        if(sys.keyboard[SDL_SCANCODE_W]) { rect.y -= speed; }
        if(sys.keyboard[SDL_SCANCODE_S]) { rect.y += speed; }
        if(sys.keyboard[SDL_SCANCODE_A]) { rect.x -= speed; }
        if(sys.keyboard[SDL_SCANCODE_D]) { rect.x += speed; }
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
        //hasColliders();
    }

    void Player::onCollision(Collision<Entity> collision)
    {
        if (collision.tag == "Wall"){
            destroy(collision.object);
        }
    }
}