#include "../include/particle.h"


void Particle::move()
{
	x += vec.x;
	y += vec.y;
	vec.y += 0.1f;
}


void Particle::render(Graphics* gfx)
{
	SDL_SetRenderDrawColor(gfx->rend, col.r, col.g, col.b, 255);
	SDL_RenderDrawPoint(gfx->rend, x, y);
	SDL_SetRenderDrawColor(gfx->rend, 0, 0, 0, 255);
}


bool Particle::out_of_bounds()
{
	return (x <= 0 || x >= SCREEN_W || y >= SCREEN_H);
}