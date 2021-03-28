#pragma once
#include "utils.h"
#include "graphics.h"
#include "paddle.h"


class Ball
{
public:
	Ball(float x, float y, const vec2d& vec)
		: x(x), y(y), vec(vec) {}

	void move(Paddle& paddle);

	void bounce(Direction dir);
	
	void collides_paddle(Paddle& paddle);
	bool within_x(float px, float pw);
	bool within_y(float py, float ph);

	void render(Graphics* gfx);

private:
	float x{ 0.f }, y{ 0.f };
	float radius{ 10.f };

	vec2d vec{ 0.f, 0.f };
};