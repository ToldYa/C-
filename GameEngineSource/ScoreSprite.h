#ifndef SCORESPRITE_H
#define SCORESPRITE_H

#include <string>
#include "Sprite.h"
#include "System.h"

namespace cwing {

	class ScoreSprite : public Sprite
	{
	public:
		static ScoreSprite* getInstance();
		void draw();
		void setScore(int newScore);
		int getScore() { return score; }
		void resetScore() { score = 0; }
		void makeTexture();
		~ScoreSprite();
	protected:
		ScoreSprite();
	private:
		int score = 0;
	};

} // cwing

#endif
