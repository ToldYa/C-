#include "BackgroundSprite.h"
#include <stdexcept>

namespace cwing {

	BackgroundSprite* BackgroundSprite::getInstance(std::string bgPath) {
		return new BackgroundSprite(bgPath);
	}

	BackgroundSprite::BackgroundSprite(std::string bgPath) {
		setTexture(IMG_LoadTexture(sys.getRen(), bgPath.c_str()));
		if (getTexture() == nullptr)
			throw std::runtime_error("Background Sprite Path ej hittad!");
	}

	void BackgroundSprite::draw() {
		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, NULL);
	}

	BackgroundSprite::~BackgroundSprite() {
		SDL_DestroyTexture(getTexture());
	}

}
