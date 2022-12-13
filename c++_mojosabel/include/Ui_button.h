#ifndef UI_BUTTON_H
#define UI_BUTTON_H

#include "Ui_sprite.h"

namespace mojosabel {
    
    class Ui_button : public Ui_sprite 
    {
        public:
            static Ui_button* getInstance(int x, int y, int w, int h, std::string txt);
            void draw() const;
            ~Ui_button();
        protected:
            Ui_button(int x, int y, int w, int h, std::string txt);
        private:
    };
}


#endif