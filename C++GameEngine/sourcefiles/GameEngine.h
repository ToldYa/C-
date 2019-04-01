#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include "Sprite.h"
#include "BackgroundSprite.h"
#include "PlayerSprite.h"
#include <SDL.h>
#include "System.h"
#include "ExplosionSprite.h"
#include "EnemySprite.h"
#include "ScoreSprite.h"
#include <string>

namespace cwing {

	class GameEngine
	{
	public:
		GameEngine();
		void add(Sprite*);
		void run();
		~GameEngine();
		void defineFPS(int);
		std::vector<Sprite*>* getToAdd() { return &toAdd; }
		void setPlayerPath(std::string path) { playerSpritePath = path; }
		void setBgPath(std::string path) { bgSpritePath = path; }
		std::string getPlayerPath() { return playerSpritePath; }
		std::string getBgPath() { return bgSpritePath; }
	private:
		void restartGame();
		void clearVec();
		void setupNewRound();
		std::vector<Sprite*> sprites;
		std::vector<Sprite*> toAdd;
		int FPS = 0;
		const int DEFAULT_FPS = 60;
		int enemyGen = 0;
		ScoreSprite *scoreSprite;
		std::string playerSpritePath;
		std::string bgSpritePath;
	};

	extern GameEngine engine;
} // cwing

#endif
