#include "ScoreSprite.h"

namespace cwing {

	ScoreSprite* ScoreSprite::getInstance() {
		return new ScoreSprite();
	}

	ScoreSprite::ScoreSprite() {
		makeTexture();
	}

	void ScoreSprite::makeTexture() {
		if (getTexture() != nullptr)
			SDL_DestroyTexture(getTexture());
		std::string scoreStr = "" + std::to_string(score);
		SDL_Surface* scoreSurf = TTF_RenderText_Solid(sys.getFont(), scoreStr.c_str(), SDL_Color{ 200, 220, 0 });
		setTexture(SDL_CreateTextureFromSurface(sys.getRen(), scoreSurf));

		if (getRect() != nullptr)
			delete getRect();
		SDL_Rect* scoreRect = new SDL_Rect();
		*scoreRect = { 400, 20, scoreSurf->w, scoreSurf->h };
		setRect(scoreRect);
		SDL_FreeSurface(scoreSurf);
	}

	void ScoreSprite::setScore(int newScore) {
		score = newScore;
		makeTexture();
	}

	void ScoreSprite::draw() {
		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, getRect());
	}

	ScoreSprite::~ScoreSprite()
	{
		delete getRect();
		SDL_DestroyTexture(getTexture());
	}

}
