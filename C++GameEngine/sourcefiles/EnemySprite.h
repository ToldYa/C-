#ifndef ENEMYSPRITE_H
#define ENEMYSPRITE_H

#include "Sprite.h"
#include <SDL.h>
#include "GameEngine.h"
#include "System.h"

namespace cwing {

	class EnemySprite : public Sprite {
	public:
		static EnemySprite* getInstance();
		~EnemySprite();
		void draw();
		void update();
	protected:
		EnemySprite();
	private:
		int yDifferential = 0;
	};

}

#endif