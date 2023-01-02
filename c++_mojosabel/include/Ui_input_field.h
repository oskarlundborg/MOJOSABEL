#ifndef UI_INPUT_FIELD_H
#define UI_INPUT_FIELD_H

#include "Ui_sprite.h"

namespace mojosabel {
   class Ui_input_field : public Ui_sprite 
   {
      protected:
         Ui_input_field(int x, int y, int w, int h, std::string txt);
      public:
         static Ui_input_field* getInstance(int x, int y, int w, int h, std::string txt);
         void draw();
         ~Ui_input_field() {}
   }; 
}


#endif