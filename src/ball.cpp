#include "../include/ball.h"
#include <cmath>


void Ball::move(Paddle& paddle)
{
	x += vec.x;
	y += vec.y;

	if (x - radius <= 0) bounce(Direction::RIGHT);
	if (x + radius >= SCREEN_W) bounce(Direction::LEFT);
	if (y - radius <= 0) bounce(Direction::DOWN);
	if (y + radius >= SCREEN_H) bounce(Direction::UP);

	collides_paddle(paddle);
}


void Ball::bounce(Direction dir)
{
	switch (dir)
	{
	case Direction::LEFT:
	case Direction::RIGHT: vec.x *= -1; break;
	case Direction::UP:
	case Direction::DOWN: vec.y *= -1; break;
	}
}


void Ball::collides_paddle(Paddle& paddle)
{
	std::array<float, 4> dpad = paddle.get_dimensions();
	float px = dpad[0];
	float py = dpad[1];
	float pw = dpad[2];
	float ph = dpad[3];

	if (within_x(px, pw) && within_y(py, ph))
	{
		if ((x - radius) < (px + pw) && (x + radius) > (px + pw)) bounce(Direction::RIGHT);
		if ((x + radius) > px && (x - radius) < px) bounce(Direction::LEFT);
		if ((y - radius) < (py + ph) && (y + radius) > (py + ph)) bounce(Direction::UP);
		if ((y + radius) > py && (y - radius) < py) bounce(Direction::DOWN);
	}
}


bool Ball::within_x(float px, float pw)
{
	return ((x - radius) < (px + pw) && (x + radius) > px);
}


bool Ball::within_y(float py, float ph)
{
	return ((y - radius) < (py + ph) && (y + radius) > py);
}


void Ball::render(Graphics* gfx)
{
	SDL_SetRenderDrawColor(gfx->rend, 255, 0, 255, 255);

	for (float y = this->y - radius; y < this->y + radius; ++y)
	{
		for (float x = this->x - radius; x < this->x + radius; ++x)
		{
			if (std::sqrtf((this->x - x) * (this->x - x) + (this->y - y) * (this->y - y)) < radius)
			{
				SDL_RenderDrawPoint(gfx->rend, (int)x, (int)y);
			}
		}
	}

	SDL_SetRenderDrawColor(gfx->rend, 0, 0, 0, 255);
}