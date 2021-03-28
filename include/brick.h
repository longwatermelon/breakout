#pragma once
#include "graphics.h"
#include "utils.h"
#include <vector>
#include <array>


class Brick
{
public:
	Brick(float x, float y, float w, float h)
		: x(x), y(y), w(w), h(h)
	{
		rect = { (int)x, (int)y, (int)w, (int)h };
	}

	void hit();

	bool is_dead();

	void render(Graphics* gfx);

	std::array<float, 4> get_dimensions() { return { x, y, w, h }; }

private:
	float x{ 0.f }, y{ 0.f }, w{ 0.f }, h{ 0.f };
	SDL_Rect rect;

	int resistance{ 3 };
	SDL_Color col{ 0, 255, 0 };
	std::vector<SDL_Color> colors{ {255, 0, 0}, {255, 255, 0}, {0, 255, 0} };
};