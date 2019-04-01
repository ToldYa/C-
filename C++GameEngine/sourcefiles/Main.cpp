#include <SDL.h>
#include "System.h"
#include "GameEngine.h"
#include "Sprite.h"
#include "BackgroundSprite.h"
#include "PlayerSprite.h"
#include "ScoreSprite.h"

using namespace std;
using namespace cwing;


int main(int argc, char** argv) {
	engine.defineFPS(80);
	engine.setBgPath("//GOOFY2/HT16/emve6881/Desktop/CPROGMAPP/CPROG_FINAL/backgroundSprite.bmp");
	engine.setPlayerPath("//GOOFY2/HT16/emve6881/Desktop/CPROGMAPP/CPROG_FINAL/playerSprite.bmp");

	Sprite* bgSprite = BackgroundSprite::getInstance(engine.getBgPath());
	engine.add(bgSprite);

	Sprite* playerSprite = PlayerSprite::getInstance(engine.getPlayerPath());
	engine.add(playerSprite);

	engine.run();

	return 0;
}
