#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H

#include "Sprite.h"
#include <SDL.h>
#include "ProjectileSprite.h"
#include "GameEngine.h"
#include "System.h"

namespace cwing {

	class PlayerSprite : public Sprite {
	public:
		void keyDown(const SDL_Event&);
		void keyUp(const SDL_Event&);
		void mouseMotion(const SDL_Event&);
		static PlayerSprite* getInstance(std::string);
		~PlayerSprite();
		void draw();
		void setPath(std::string path) { playerPathStr = path; }
		std::string getPath() { return playerPathStr; }
	protected:
		PlayerSprite(std::string);
	private:
		bool holdingX = false;
		int i = 0;
		std::string playerPathStr;
	};

}

#endif
