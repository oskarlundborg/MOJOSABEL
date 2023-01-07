#include "GTurtle.h"
#include <iostream>
#include "Session.h"
#include "Ui_label.h"
#include "Ui_sprite.h"
#include "Ui_button.h"

void GTurtle::adjustHealth(int changeHealth){
    if((health += changeHealth) <= 0){
        health = 0;
        std::cout << "dead" << std::endl;
        die();
        setCollision(false);
    } else {
        health += changeHealth;
        iFrameCounter = 0;
        std::cout << health << std::endl;
        setCollision(false);
    }
}

void GTurtle::onCollision(Collision<Entity> collision){
    if(collision.tag == "Enemy"){
        adjustHealth(-10);
    }
}

void GTurtle::update(){
    move();
    iFrameCounter++;
    if(iFrameCounter > 2000000000){
        iFrameCounter = 60;
    }
    if(iFrameCounter > 60 && health > 0){
        setCollision(true);
    }
}

class NewGameButton : public Ui_button
{
    public:
        NewGameButton() : Ui_button((SCREEN_WIDTH/2 -100), 400, 200, 100, "New Game") {}
        void perform(Ui_button source)
        {
            //start new game
        }
};

void GTurtle::die(){
    ses.getRootCanvas()->addUiSprite(Ui_label::getInstance((SCREEN_WIDTH/2 -200), 200, 400, 80, "Oh no! You died"));
    Ui_button* uiButton = new NewGameButton();
    ses.getRootCanvas()->addUiSprite(uiButton);
}