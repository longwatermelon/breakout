#include "../include/ball.h"
#include "../include/paddle.h"
#include "../include/brick.h"

std::vector<Particle> particles;

int main(int argc, char** argv)
{
	Graphics* gfx = new Graphics;
	Ball ball(500, 500, { 5.f, -8.3f });
	Paddle paddle(400, 800, 150, 10);

	std::vector<Brick> bricks;
	

	for (int y = 120; y < 120 + 15 * 7; y += 15)
	{
		for (int x = 165; x < 165 + 40 * 15; x += 40)
		{
			bricks.emplace_back(Brick(x, y, 40, 15));
		}
	}

	bool running = true;
	SDL_Event evt;

	while (running)
	{
		while (SDL_PollEvent(&evt))
		{
			switch (evt.type)
			{
			case SDL_QUIT: running = false; break;
			}
		}

		SDL_RenderClear(gfx->rend);

		ball.move(paddle, bricks);
		ball.render(gfx);

		paddle.move();
		paddle.render(gfx);

		for (int i = 0; i < bricks.size(); ++i)
		{
			bricks[i].render(gfx);

			if (bricks[i].is_dead())
			{
				bricks.erase(bricks.begin() + i);
			}
		}

		for (int i = 0; i < particles.size(); ++i)
		{
			particles[i].render(gfx);
			particles[i].move();

			if (particles[i].out_of_bounds())
			{
				particles.erase(particles.begin() + i);
			}
		}

		SDL_RenderPresent(gfx->rend);
	}


	delete gfx;
	SDL_Quit();

	return 0;
}