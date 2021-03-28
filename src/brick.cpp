#include "../include/brick.h"

extern std::vector<Particle> particles;

void Brick::hit()
{
	--resistance;

	for (int iy = (int)y; iy < (int)(y + h); ++iy)
	{
		for (int ix = (int)x; ix < (int)(x + w); ++ix)
		{
			particles.emplace_back(Particle(ix, iy, { 0, random_float(0.f, 2.f) }, col));
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

	/*for (int i = 0; i < particles.size(); ++i)
	{
		if (particles[i].out_of_bounds()) particles.erase(particles.begin() + i);
		else
		{
			particles[i].render(gfx);
			particles[i].move();
		}
	}*/

	SDL_SetRenderDrawColor(gfx->rend, 0, 0, 0, 255);
}