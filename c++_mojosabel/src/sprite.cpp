#include "Sprite.h"

namespace mojosabel {

    Sprite::Sprite(int x, int y, int w, int h) : rect {x, y, w, h} 
    { 
        
    }

    bool compareLayer(Sprite* s1, Sprite* s2) {
        return s1->getLayer() < s2->getLayer();
    }
}