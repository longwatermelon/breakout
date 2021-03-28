#pragma once
#include "graphics.h"
#include "utils.h"
#include <Windows.h>
#include <array>


class Paddle
{
public:
	Paddle(float x, float y, float w, float h)
		: x(x), y(y), w(w), h(h)
	{
		rect = { (int)x, (int)y, (int)w, (int)h };
	}

	void move();

	void render(Graphics* gfx);

	std::array<float, 4> get_dimensions() { return { x, y, w, h }; }

private:
	float x{ 0.f }, y{ 0.f }, w{ 0.f }, h{ 0.f };
	float speed{ 10.f };

	SDL_Rect rect;
	SDL_Color color = { 255, 0, 100 };
};