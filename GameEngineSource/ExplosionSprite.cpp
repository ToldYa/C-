#include "ExplosionSprite.h"

namespace cwing {

	ExplosionSprite* ExplosionSprite::getInstance(SDL_Rect* ref) {
		return new ExplosionSprite(ref);
	}

	ExplosionSprite::ExplosionSprite(SDL_Rect* ref) {
		std::string explosionPath = "//GOOFY2/HT16/emve6881/Desktop/CPROGMAPP/CPROG_FINAL/explosionSprite.bmp";
		SDL_Surface* explosionSurf = SDL_LoadBMP(explosionPath.c_str());
		Uint32 white = SDL_MapRGB(explosionSurf->format, 255, 255, 255);
		SDL_SetColorKey(explosionSurf, true, white);
		setTexture(SDL_CreateTextureFromSurface(sys.getRen(), explosionSurf));
		if (getTexture() == nullptr)
			throw std::runtime_error("Explosion Sprite Path ej hittad!");

		SDL_Rect* explosionRect = new SDL_Rect();
		*explosionRect = { (ref->x + (ref->w / 2) - (explosionSurf->w / 2)), (ref->y + (ref->h / 2) - (explosionSurf->h / 2)), explosionSurf->w, explosionSurf->h };
		setRect(explosionRect);
		SDL_FreeSurface(explosionSurf);
	}

	void ExplosionSprite::draw() {
		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, getRect());
	}

	ExplosionSprite::~ExplosionSprite() {
		delete getRect();
		SDL_DestroyTexture(getTexture());
	}
}

