#ifndef UI_INPUT_FIELD_H
#define UI_INPUT_FIELD_H

#include "Ui_sprite.h"

namespace mojosabel {
   class Ui_input_field : public Ui_sprite 
   {
      public:
         static Ui_input_field* getInstance(int x, int y, int w, int h, std::string txt);
         void draw() const;
         ~Ui_input_field();
      protected:
         Ui_input_field(int x, int y, int w, int h, std::string txt);
      private:
   }; 
}


#endif