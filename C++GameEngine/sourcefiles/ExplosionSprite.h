#ifndef EXPLOSIONSPRITE_H
#define EXPLOSIONSPRITE_H

#include <string>
#include <SDL.h>
#include "Sprite.h"
#include "System.h"

namespace cwing {

	class ExplosionSprite : public Sprite {
	public:
		static ExplosionSprite* getInstance(SDL_Rect*);
		~ExplosionSprite();
		void draw();
		int getFramesToShow() { return framesToShow; }
		void incrementFramesToShow() { framesToShow++; }
	protected:
		ExplosionSprite(SDL_Rect*);
	private:
		int framesToShow = 0;
	};

} // cwing

#endif