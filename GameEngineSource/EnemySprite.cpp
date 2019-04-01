#include "EnemySprite.h"
#include <iostream>				// For testing to console <<-----------------

namespace cwing {

	EnemySprite* EnemySprite::getInstance() {
		return new EnemySprite();
	}

	EnemySprite::EnemySprite() {
		std::string enemyPath = "//GOOFY2/HT16/emve6881/Desktop/CPROGMAPP/CPROG_FINAL/enemySprite.bmp";
		SDL_Surface* enemySurf = SDL_LoadBMP(enemyPath.c_str());
		Uint32 white = SDL_MapRGB(enemySurf->format, 255, 255, 255);
		SDL_SetColorKey(enemySurf, true, white);
		setTexture(SDL_CreateTextureFromSurface(sys.getRen(), enemySurf));
		if (getTexture() == nullptr)
			throw std::runtime_error("Enemy Sprite Path ej hittad!");
		
		SDL_Rect* enemyRect = new SDL_Rect();
		*enemyRect = { 1500, (rand() % 300) + 200, enemySurf->w, enemySurf->h };
		setRect(enemyRect);
		SDL_FreeSurface(enemySurf);
	}

	void EnemySprite::update() {

		SDL_Rect* updatedRect = getRect();
		updatedRect->x -= 2;

		if (yDifferential < 200) {
			updatedRect->y -= 1;
		}
		else if (yDifferential > 200) {
			updatedRect->y += 1;
		}

		if (yDifferential > 399) {
			yDifferential = 0;
		}

		yDifferential++;

		if (updatedRect->x < (0 - getRect()->w)) {
			setToDelete(true);
		}

		setRect(updatedRect);
	}

	void EnemySprite::draw() {
		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, getRect());
	}

	EnemySprite::~EnemySprite() {
		delete getRect();
		SDL_DestroyTexture(getTexture());
	}



}


