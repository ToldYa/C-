#ifndef PROJECTILESPRITE_H
#define PROJECTILESPRITE_H

#include "Sprite.h"
#include <SDL.h>
#include "GameEngine.h"
#include "System.h"

namespace cwing {

	class ProjectileSprite : public Sprite {
	public:
		static ProjectileSprite* getInstance(SDL_Rect* playerRect);
		~ProjectileSprite();
		void draw();
		void update();
	protected:
		ProjectileSprite(SDL_Rect* playerRect);
	private:
		unsigned int distanceTraveled = 0;
	};

}

#endif