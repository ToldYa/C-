#include "PlayerSprite.h"
#include <iostream>

namespace cwing {

	PlayerSprite* PlayerSprite::getInstance(std::string playerPath) {
		return new PlayerSprite(playerPath);
	}

	PlayerSprite::PlayerSprite(std::string playerPath) {
		SDL_Surface* playerSurf = SDL_LoadBMP(playerPath.c_str());
		Uint32 white = SDL_MapRGB(playerSurf->format, 255, 255, 255);
		SDL_SetColorKey(playerSurf, true, white);
		setTexture(SDL_CreateTextureFromSurface(sys.getRen(), playerSurf));
		if (getTexture() == nullptr)
			throw std::runtime_error("Player Sprite Path ej hittad!");

		SDL_Rect* playerRect = new SDL_Rect();
		*playerRect = { 20, 200, playerSurf->w, playerSurf->h };
		setRect(playerRect);
		SDL_FreeSurface(playerSurf);
	}

	void PlayerSprite::draw() {
		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, getRect());
	}

	void PlayerSprite::keyDown(const SDL_Event& event) {
		switch (event.key.keysym.sym) {
		case SDLK_x:
			i++;
			if (i > 15 || !holdingX) {
				holdingX = true;
				i = 0;
				Sprite* projectile = ProjectileSprite::getInstance(getRect());
				engine.add(projectile);
			}
			break;
		} // inre switch
	}

	void PlayerSprite::keyUp(const SDL_Event& event) {
		switch (event.key.keysym.sym) {
		case SDLK_x:
			holdingX = false;
			i = 0;
			break;
		}
	}

	void PlayerSprite::mouseMotion(const SDL_Event& event) {
		if (event.motion.y < (getRect()->h / 2)) {
			getRect()->y = 0;
		}
		else if (event.motion.y > 800) {
			getRect()->y = 800 - (getRect()->h / 2);
		}
		else {
			getRect()->y = event.motion.y - (getRect()->h / 2);
		}
	}

	PlayerSprite::~PlayerSprite() {
		delete getRect();
		SDL_DestroyTexture(getTexture());
	}

} //cwing
