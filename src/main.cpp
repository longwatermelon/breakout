#include "../include/ball.h"
#include "../include/paddle.h"
#include "../include/brick.h"


int main(int argc, char** argv)
{
	Graphics* gfx = new Graphics;
	Ball ball(500, 500, { 7.f, 8.3f });
	Paddle paddle(400, 800, 150, 10);

	std::vector<Brick*> bricks;
	bricks.emplace_back(new Brick(100, 100, 40, 15));

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
			bricks[i]->render(gfx);

			if (bricks[i]->is_dead())
			{
				delete bricks[i];
				bricks.erase(bricks.begin() + i);
			}
		}

		SDL_RenderPresent(gfx->rend);
	}


	delete gfx;
	SDL_Quit();

	return 0;
}