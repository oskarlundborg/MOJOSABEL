#ifndef UI_LABEL_H
#define UI_LABEL_H

#include "Ui_sprite.h"

namespace mojosabel {

	class Label: public Ui_sprite
	{
	public:
		static Label* getInstance(int x, int y, int w, int h, std::string txt);
		void draw() const;
		~Label();
	protected:
		Label(int x, int y, int w, int h, std::string txt);
	private:
		
	};

}
#endif