#include "../include/ball.h"
#include "../include/paddle.h"
#include "../include/brick.h"

std::vector<Particle> particles;

int main(int argc, char** argv)
{
	Graphics* gfx = new Graphics;
	Ball ball(500, 500, { 5.f, -8.3f });
	Paddle paddle(400, 800, 75, 15);

	std::vector<Brick> bricks;
	std::vector<Ball> balls;

	balls.emplace_back(Ball(500, 500, { 5.f, -8.3f }));
	

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
			case SDL_KEYDOWN:
			{
				switch (evt.key.keysym.sym)
				{
				case SDLK_1: balls.emplace_back(Ball(500, 500, { random_float(-10.f, 10.f), random_float(-10.f, 10.f) }));
				}
			}
			}
		}

		SDL_RenderClear(gfx->rend);

		for (auto& b : balls)
		{
			b.move(paddle, bricks);
			b.render(gfx);
		}

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