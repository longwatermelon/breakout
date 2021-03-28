#pragma once
#include "utils.h"
#include "graphics.h"


class Particle
{
public:
	Particle(float x, float y, const vec2d& vec, const SDL_Color& col)
		: x(x), y(y), vec(vec), col(col) {}

	void move();

	void render(Graphics* gfx);

	bool out_of_bounds();

private:
	float x{ 0.f }, y{ 0.f };
	vec2d vec{ 0.f, 0.f };

	SDL_Color col{ 255, 255, 255 };
};