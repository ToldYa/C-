#ifndef BACKGROUNDSPRITE_H
#define BACKGROUNDSPRITE_H

#include "Sprite.h"
#include <SDL.h>
#include "System.h"
#include <string>
#include <SDL_image.h>
#include <iostream>

namespace cwing {

	class BackgroundSprite : public Sprite {
	public:
		static BackgroundSprite* getInstance(std::string);
		~BackgroundSprite();
		void draw();
	protected:
		BackgroundSprite(std::string);
	private:
		SDL_Texture* bgTex;
	};

}

#endif
