#include "../include/paddle.h"


void Paddle::move()
{
	if (x - speed < 0) x = 0;
	if (x + w + speed > SCREEN_W) x = SCREEN_W - w;

	if (GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT) && x != 0) x -= speed;
	if (GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT) && x + w != SCREEN_W) x += speed;

	rect.x = (int)x;
}


void Paddle::render(Graphics* gfx)
{
	SDL_SetRenderDrawColor(gfx->rend, color.r, color.g, color.b, 255);
	SDL_RenderFillRect(gfx->rend, &rect);
	SDL_SetRenderDrawColor(gfx->rend, 0, 0, 0, 255);
}