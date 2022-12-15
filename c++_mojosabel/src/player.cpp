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

    void Player::keyDown(const SDL_Event& event) 
    {
        if(event.key.keysym.sym == SDLK_w) { movingUp = true; }
        if(event.key.keysym.sym == SDLK_d) { movingRight = true; }
        if(event.key.keysym.sym == SDLK_s) { movingDown = true; }
        if(event.key.keysym.sym == SDLK_a) { movingLeft = true; }
    }

    void Player::keyUp(const SDL_Event& event)
    {
        if(event.key.keysym.sym == SDLK_w) { movingUp = false; }
        if(event.key.keysym.sym == SDLK_d) { movingRight = false; }
        if(event.key.keysym.sym == SDLK_s) { movingDown = false; }
        if(event.key.keysym.sym == SDLK_a) { movingLeft = false; }
    }

    void Player::move() 
    {
        if(movingUp) { moveUp(speed); }
        if(movingDown) { moveDown(speed); }
        if(movingLeft) { moveLeft(speed); }
        if(movingRight) { moveRight(speed); }
    }

    void Player::moveUp(int dist) { rect.y -= dist; }
    
    void Player::moveDown(int dist) { rect.y += dist; }

    void Player::moveLeft(int dist) { rect.x -= dist; }

    void Player::moveRight(int dist) { rect.x += dist; }

    Player::~Player() { SDL_DestroyTexture(texture); }

}