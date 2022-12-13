#include "Ui_label.h"
#include "System.h"

using namespace std;

namespace mojosabel {

	Label* Label::getInstance(int x, int y, int w, int h, std::string txt) 
	{
		return new Label(x, y, w, h, txt);
	}

	Label::Label(int x, int y, int w, int h, std::string txt): Ui_sprite(x,y,w,h,txt)
	{
		SDL_Surface* surf = TTF_RenderText_Solid(sys.getFont(), text.c_str(), { 0,0,0 });
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);
		SDL_FreeSurface(surf);
	}

	void Label::draw() const {
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
	}
}