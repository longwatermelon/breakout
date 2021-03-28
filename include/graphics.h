#pragma once
#include "utils.h"
#include <SDL.h>


class Graphics
{
public:
	SDL_Window* window{ nullptr };
	SDL_Renderer* rend{ nullptr };

	Graphics()
	{
		SDL_Init(SDL_INIT_EVERYTHING);

		window = SDL_CreateWindow("sample", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
		rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		SDL_RenderClear(rend);
	}

	~Graphics()
	{
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(rend);
	}
};