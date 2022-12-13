#ifndef LABEL_H
#define LABEL_H
#include "Ui_sprite.h"
#include <string>
#include <SDL2/SDL.h>

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