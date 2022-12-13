#include "Ui_button.h"
#include "System.h"

using namespace std;

namespace mojosabel {

	Ui_button* Ui_button::getInstance(int x, int y, int w, int h, std::string txt) 
	{
		return new Ui_button(x, y, w, h, txt);
	}

	Ui_button::Ui_button(int x, int y, int w, int h, std::string txt): Ui_sprite(x,y,w,h,txt)
	{
		SDL_Surface* surf = TTF_RenderText_Solid(sys.getFont(), text.c_str(), { 0,0,0 });
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);
		SDL_FreeSurface(surf);
	}

	void Ui_button::draw() const {
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
	}
}