#include "../include/ball.h"
#include <cmath>


void Ball::move()
{
	x += vec.x;
	y += vec.y;

	if (x - radius <= 0) bounds_bounce(Direction::LEFT);
	if (x + radius >= SCREEN_W) bounds_bounce(Direction::RIGHT);
	if (y - radius <= 0) bounds_bounce(Direction::UP);
	if (y + radius >= SCREEN_H) bounds_bounce(Direction::DOWN);
}


void Ball::bounds_bounce(Direction dir)
{
	switch (dir)
	{
	case Direction::LEFT:
	case Direction::RIGHT: vec.x *= -1; break;
	case Direction::UP:
	case Direction::DOWN: vec.y *= -1; break;
	}
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