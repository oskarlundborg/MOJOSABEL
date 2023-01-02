#ifndef UI_SLIDER_H
#define UI_SLIDER_H

#include "Ui_sprite.h"

namespace mojosabel {
   class Ui_slider : public Ui_sprite 
   {
      protected:
         Ui_slider(int x, int y, int w, int h, std::string txt);
      public:
         static Ui_slider* getInstance(int x, int y, int w, int h, std::string txt);
         void draw();
         ~Ui_slider() {}
   }; 
}


#endif