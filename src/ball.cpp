#include "../include/ball.h"
#include <cmath>
#include <vector>


void Ball::move(Paddle& paddle, std::vector<Brick*>& bricks)
{
	x += vec.x;
	y += vec.y;

	if (x - radius <= 0) bounce(Direction::RIGHT);
	if (x + radius >= SCREEN_W) bounce(Direction::LEFT);
	if (y - radius <= 0) bounce(Direction::DOWN);
	if (y + radius >= SCREEN_H) bounce(Direction::UP);

	collides(paddle);

	for (auto ptr : bricks)
	{
		collides(*ptr);
	}
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