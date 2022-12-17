#include <SDL2/SDL_image.h>
#include "Player.h"
#include "System.h"
#include "Constants.h"
#include <iostream>

namespace mojosabel {

    void Player::draw() 
    {
        if(!texture)
        {
            std::cout << "Player Texture Error: No texture loaded" << std::endl;
            return;
        }
        move();
        SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
    }

    void Player::loadTexture(std::string filename)
    {
        texture = IMG_LoadTexture(sys.getRen(), (filename).c_str());
    }

    void Player::move() 
    {
        if(sys.keyboard[SDL_SCANCODE_W]) { moveUp(speed); }
        if(sys.keyboard[SDL_SCANCODE_S]) { moveDown(speed); }
        if(sys.keyboard[SDL_SCANCODE_A]) { moveLeft(speed); }
        if(sys.keyboard[SDL_SCANCODE_D]) { moveRight(speed); }
    }

    void Player::moveUp(int dist) { rect.y -= dist; }
    
    void Player::moveDown(int dist) { rect.y += dist; }

    void Player::moveLeft(int dist) { rect.x -= dist; }

    void Player::moveRight(int dist) { rect.x += dist; }

    void Player::fire() {};

    Player::~Player() { SDL_DestroyTexture(texture); }

}