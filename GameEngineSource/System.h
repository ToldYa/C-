#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

namespace cwing {

	class System
	{
	public:
		System();
		~System();
		SDL_Renderer* getRen() const { return ren; }
		TTF_Font* getFont() const { return font; }
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
		TTF_Font* font;
	};

	extern System sys;

} // cwing
#endif