#include "../include/brick.h"

extern std::vector<Particle> particles;

void Brick::hit()
{
	--resistance;

	for (int iy = (int)y; iy < (int)(y + h); ++iy)
	{
		for (int ix = (int)x; ix < (int)(x + w); ++ix)
		{
			particles.emplace_back(Particle(ix, iy, { random_float(-0.4f, 0.4f), random_float(-1.f, 1.f) }, col));
		}
	}

	if (resistance - 1 >= 0)
	{
		col = colors[resistance - 1];
	}
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