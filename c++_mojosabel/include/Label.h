#ifndef LABEL_H
#define LABEL_H
#include "Sprite.h"
#include <string>
#include <SDL2/SDL.h>
namespace mojosabel {

	class Label: public Sprite
	{
	public:
		static Label* getInstance(int x, int y, int w, int h, std::string txt);
		void draw() const;
		std::string getText() const;
		void setText(std::string newText);
		~Label();
	protected:
		Label(int x, int y, int w, int h, std::string txt);
	private:
		std::string text;
		SDL_Texture* texture;
	};

}
#endif