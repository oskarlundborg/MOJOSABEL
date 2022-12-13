#ifndef IMAGE_TEST_H
#define IMAGE_TEST_H
#include "Sprite.h"

namespace mojosabel {

	class Image_test: public Sprite
	{
	public:
		Image_test(int x, int y, int w, int h);
        void draw() const;

	private:
		SDL_Texture* texture;
	};

}


#endif