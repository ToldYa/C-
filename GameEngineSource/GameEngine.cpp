#include "GameEngine.h"
#include <iostream>

namespace cwing {

	GameEngine::GameEngine()
	{
	}

	void GameEngine::add(Sprite* s) {
		toAdd.push_back(s);
	}

	void GameEngine::run() {
		scoreSprite = ScoreSprite::getInstance();
		add(scoreSprite);

		bool running = true;

		if (FPS == 0) {
			FPS = DEFAULT_FPS;
		}
		const int MILLI_SEC_INTERVAL = 1000 / FPS;

		while (running) {
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT:
					running = false;
					break;
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_r) {
						restartGame();
					}
					else {
						for (Sprite* s : sprites)
							s->keyDown(event);
					}
					break;
				case SDL_KEYUP:
					for (Sprite* s : sprites)
						s->keyUp(event);
					break;
				case SDL_MOUSEMOTION:
					for (Sprite* s : sprites)
						s->mouseMotion(event);
					break;
				} // outer while
			} // inner while

			for (auto s1 : sprites) {
				if (!(dynamic_cast<BackgroundSprite*>(s1)) && !(dynamic_cast<ScoreSprite*>(s1)) &&
					!(dynamic_cast<ExplosionSprite*>(s1))) {
					for (auto s2 : sprites) {
						if (s1 != s2 && !(dynamic_cast<ScoreSprite*>(s2)) && !(dynamic_cast<ExplosionSprite*>(s2)) &&
							SDL_HasIntersection(s1->getRect(), s2->getRect()) &&
							!(dynamic_cast<PlayerSprite*>(s1) && dynamic_cast<ProjectileSprite*>(s2)) &&
							!(dynamic_cast<ProjectileSprite*>(s1) && !(dynamic_cast<PlayerSprite*>(s2)))) {
							s1->setToDelete(true);
							s2->setToDelete(true);
						}
					}
				}
			}

			for (size_t i = 0; i < sprites.size(); i++) {
				if (sprites[i]->getToDelete()) {
					if (dynamic_cast<EnemySprite*>(sprites[i])) {
						Sprite* explosionSprite = ExplosionSprite::getInstance(sprites[i]->getRect());
						add(explosionSprite);
						ScoreSprite *score = static_cast<ScoreSprite*>(scoreSprite);					
						score->setScore(score->getScore() + 100);
					}
					delete sprites[i];
					sprites.erase(sprites.begin() + i);
				}
			}

			for (size_t i = 0; i < sprites.size(); i++) {
				if (dynamic_cast<ExplosionSprite*>(sprites[i])) {
					if (dynamic_cast<ExplosionSprite*>(sprites[i])->getFramesToShow() > 50) {
						sprites[i]->setToDelete(true);
					}
					else {
						dynamic_cast<ExplosionSprite*>(sprites[i])->incrementFramesToShow();
					}
				}
			}

			++enemyGen;
			if (enemyGen > 200) {	//used to generate enemies
				Sprite* newEnemy = EnemySprite::getInstance();
				add(newEnemy);
				enemyGen = 0;
			}

			if (!toAdd.empty()) {	// add sprites to sprites* vector
				for (Sprite* s : toAdd) {
					sprites.push_back(s);
				}
				toAdd.clear();
			}


			for (Sprite* s : sprites) {		// update sprite positions
				s->update();
			}

			SDL_RenderClear(sys.getRen());	// clear renderer -> to draw sprites

			for (Sprite* s : sprites)		// draw all sprites to renderer
				s->draw();

			SDL_RenderPresent(sys.getRen());

			SDL_Delay(MILLI_SEC_INTERVAL);

		} // outer while

	} //run()

	void GameEngine::defineFPS(int fps) {
		FPS = fps;
	}

	void GameEngine::restartGame() {
		clearVec();
		setupNewRound();
	}

	void GameEngine::setupNewRound() {

		Sprite* bgSprite = BackgroundSprite::getInstance(bgSpritePath);
		add(bgSprite);

		Sprite* playerSprite = PlayerSprite::getInstance(playerSpritePath);
		add(playerSprite);

		scoreSprite = ScoreSprite::getInstance();
		add(scoreSprite);
	}

	void GameEngine::clearVec() {
		for (Sprite* s : sprites)
			delete s;

		sprites.clear();
	}

	GameEngine::~GameEngine()
	{
		clearVec();
	}

	GameEngine engine;

}
