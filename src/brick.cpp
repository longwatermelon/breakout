#include "../include/brick.h"


void Brick::hit()
{
	--resistance;
	col = colors[resistance];
}


bool Brick::is_dead()
{
	return resistance <= 0;
}


void Brick::render(Graphics* gfx)
{
	SDL_SetRenderDrawColor(gfx->rend, col.r, col.g, col.b, 255);
	SDL_RenderFillRect(gfx->rend, &rect);
	SDL_SetRenderDrawColor(gfx->rend, 0, 0, 0, 255);
}