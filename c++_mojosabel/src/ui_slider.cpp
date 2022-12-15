#include "Ui_slider.h"
#include "System.h"

using namespace std;

namespace mojosabel {

	Ui_slider* Ui_slider::getInstance(int x, int y, int w, int h, std::string txt) 
	{
		return new Ui_slider(x, y, w, h, txt);
	}

	Ui_slider::Ui_slider(int x, int y, int w, int h, std::string txt): Ui_sprite(x,y,w,h,txt)
	{
		SDL_Surface* surf = TTF_RenderText_Solid(sys.getFont(), text.c_str(), { 0,0,0 });
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);
		SDL_FreeSurface(surf);
	}

	void Ui_slider::draw() 
	{
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
	}
}