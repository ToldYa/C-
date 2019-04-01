#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <string>

namespace cwing {

	class Sprite
	{
	public:
		virtual ~Sprite();
		virtual void keyDown(const SDL_Event&) {}
		virtual void keyUp(const SDL_Event&) {}
		virtual void mouseMotion(const SDL_Event&) {}
		SDL_Rect* getRect() const { return rect; }
		virtual void setRect(SDL_Rect* newRect) { rect = newRect; }
		virtual void draw() = 0;
		virtual void update() {};
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;
		bool getToDelete() { return toDelete; }
		void setToDelete(bool newToDelete) { toDelete = newToDelete; }
		SDL_Texture* getTexture() { return spriteTex; }
		void setTexture(SDL_Texture* tex) { spriteTex = tex; }
	protected:
		Sprite();
	private:
		bool toDelete = false;
		SDL_Texture* spriteTex = nullptr;
		SDL_Rect* rect;

	};

}
#endif
