#pragma once
#include "utils.h"
#include "graphics.h"
#include "paddle.h"
#include "brick.h"


class Ball
{
public:
	Ball(float x, float y, const vec2d& vec)
		: x(x), y(y), vec(vec) {}

	void move(Paddle& paddle, std::vector<Brick*>& bricks);

	void bounce(Direction dir);
	
	template <typename T>
	void collides(T& object)
	{
		std::array<float, 4> dpad = object.get_dimensions();
		float px = dpad[0];
		float py = dpad[1];
		float pw = dpad[2];
		float ph = dpad[3];

		if (within_x(px, pw) && within_y(py, ph))
		{
			if ((y - radius) < (py + ph) && (y + radius) > (py + ph))
			{
				bounce(Direction::UP);
				y += ((py + ph) - (y - radius)) + 1;
			}

			if ((y + radius) > py && (y - radius) < py)
			{
				bounce(Direction::DOWN);
				y += (py - (y + radius)) - 1;
			}

			if ((x - radius) < (px + pw) && (x + radius) > (px + pw))
			{
				bounce(Direction::RIGHT);
				x += ((px + pw) - (x - radius)) + 1;
			}

			if ((x + radius) > px && (x - radius) < px)
			{
				bounce(Direction::LEFT);
				x += (px - (x + radius)) - 1;
			}		

			if constexpr (std::is_same_v<T, Brick>)
			{
				object.hit();
			}
		}
	}

	bool within_x(float px, float pw);
	bool within_y(float py, float ph);

	void render(Graphics* gfx);

private:
	float x{ 0.f }, y{ 0.f };
	float radius{ 10.f };

	vec2d vec{ 0.f, 0.f };
};