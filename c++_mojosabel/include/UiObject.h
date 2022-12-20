#ifndef UIOBJECT_H
#define UIOBJECT_H

#include "Entity.h"

namespace mojosabel
{   
    class UiObject : public Entity
    {
    private:
        std::string text;
    public:
        UiObject() : Entity(0, 0, 0, 0, 0, "Unknown") {}
        UiObject(float x, float y, int w, int h, int layer, std::string name) 
            : Entity(x, y, w, h, layer, name) {}
        void setText(std::string newText) { text = newText; }
        std::string getText() const { return text; }
    };   
} // namespace mojosabel



#endif