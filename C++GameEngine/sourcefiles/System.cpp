#include "System.h"
#include <SDL.h>
#include <stdexcept>
#include <iostream>

namespace cwing {

	System::System()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("Cwing", 100, 50, 1500, 900, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		TTF_Init();
		font = TTF_OpenFont("//GOOFY2/HT16/emve6881/Desktop/CPROGMAPP/CPROG_FINAL/arialbd.ttf", 36);
		if (font == nullptr)
			throw std::runtime_error("Font ej hittad!");
	}

	System::~System()
	{
		TTF_CloseFont(font);
		TTF_Quit();
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
	}

	System sys;

} // cwing
