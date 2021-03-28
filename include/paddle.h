#pragma once
#include "graphics.h"
#include "utils.h"
#include <Windows.h>


class Paddle
{
public:
	Paddle(float x, float y, float w, float h)
		: x(x), y(y), w(w), h(h)
	{
		rect = { (int)x, (int)y, (int)w, (int)h };
	}

	void move()
	{
		if (x - speed < 0) x = 0;
		if (x + w + speed > SCREEN_W) x = SCREEN_W - w;

		if (GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT) && x != 0) x -= speed;
		if (GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT) && x + w != SCREEN_W) x += speed;

		rect.x = (int)x;
	}


	void render(Graphics* gfx)
	{
		SDL_SetRenderDrawColor(gfx->rend, color.r, color.g, color.b, 255);
		SDL_RenderFillRect(gfx->rend, &rect);
		SDL_SetRenderDrawColor(gfx->rend, 0, 0, 0, 255);
	}

private:
	float x{ 0.f }, y{ 0.f }, w{ 0.f }, h{ 0.f };
	float speed{ 5.f };

	SDL_Rect rect;
	SDL_Color color = { 255, 0, 100 };
};