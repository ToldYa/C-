#include "ProjectileSprite.h"
#include <iostream>				// For testing to console <<-----------------

namespace cwing {

	ProjectileSprite* ProjectileSprite::getInstance(SDL_Rect* playerRect) {
		return new ProjectileSprite(playerRect);
	}

	ProjectileSprite::ProjectileSprite(SDL_Rect* playerRect) {
		std::string projectilePath = "//GOOFY2/HT16/emve6881/Desktop/CPROGMAPP/CPROG_FINAL/projectileSprite.bmp";
		SDL_Surface* projectileSurf = SDL_LoadBMP(projectilePath.c_str());
		Uint32 white = SDL_MapRGB(projectileSurf->format, 255, 255, 255);
		SDL_SetColorKey(projectileSurf, true, white);
		setTexture(SDL_CreateTextureFromSurface(sys.getRen(), projectileSurf));
		if (getTexture() == nullptr)
			throw std::runtime_error("Projectile Sprite Path ej hittad!");

		SDL_Rect* projectileRect = new SDL_Rect();
		int initialX = playerRect->w + 20;
		int initialY = playerRect->y + (playerRect->h / 2) - (projectileSurf->h / 2);
		*projectileRect = { initialX, initialY, projectileSurf->w, projectileSurf->h };
		setRect(projectileRect);
		SDL_FreeSurface(projectileSurf);
	}

	void ProjectileSprite::update() {
		distanceTraveled += 10;

		SDL_Rect* updatedRect = getRect();
		updatedRect->x += 10;

		updatedRect->y += distanceTraveled / 200;

		if (updatedRect->x > 1500) {
			setToDelete(true);
		}

		setRect(updatedRect);
	}

	void ProjectileSprite::draw() {
		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, getRect());
	}

	ProjectileSprite::~ProjectileSprite() {
		delete getRect();
		SDL_DestroyTexture(getTexture());
	}



}


