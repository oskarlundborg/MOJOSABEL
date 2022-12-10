#ifndef UI_SPRITE_H
#define UI_SPRITE_H

#include "Sprite.h"

class Ui_sprite : public Sprite {
private:
    char* text;

public:
    void SetText(char* text);
    char* GetText() {return text; }

};

#endif