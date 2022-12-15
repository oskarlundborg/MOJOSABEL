#ifndef UI_SLIDER_H
#define UI_SLIDER_H

#include "Ui_sprite.h"

namespace mojosabel {
   class Ui_slider : public Ui_sprite 
   {
      public:
         static Ui_slider* getInstance(int x, int y, int w, int h, std::string txt);
         void draw();
         ~Ui_slider() {}
      protected:
         Ui_slider(int x, int y, int w, int h, std::string txt);
      private:
   }; 
}


#endif