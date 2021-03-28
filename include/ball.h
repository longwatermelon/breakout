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

	void move(Paddle& paddle, std::vector<Brick>& bricks);

	void bounce(Direction dir);
	
	template <typename T>
	void collides(T& object)
	{
		std::array<float, 4> dpad = object.get_dimensions();
		float px = dpad[0];
		float py = dpad[1];
		float pw = dpad[2];
		float ph = dpad[3];

		bool hit = false;

		if ((x + radius + vec.x) >= px && (x + radius) < px && within_y(py, ph))
		{
			x += px - (x + radius + vec.x) - 1;
			bounce(Direction::LEFT);

			if constexpr (std::is_same_v<T, Brick>)
			{
				if (!hit)
				object.hit();
				hit = true;
			}
		}

		if ((x - radius + vec.x) <= (px + pw) && (x - radius) > (px + pw) && within_y(py, ph))
		{
			x += (px + pw) - (x - radius + vec.x) + 1;
			bounce(Direction::RIGHT);

			if constexpr (std::is_same_v<T, Brick>)
			{
				if (!hit)
				object.hit();
				hit = true;
			}
		}

		if ((y + radius + vec.y) >= py && (y + radius) < py && within_x(px, pw))
		{
			y += py - (y + radius + vec.y) - 1;
			bounce(Direction::UP);

			if constexpr (std::is_same_v<T, Brick>)
			{
				if (!hit)
				object.hit();
				hit = true;
			}
		}

		if ((y - radius + vec.y) <= (py + ph) && (y - radius) > (py + ph) && within_x(px, pw))
		{
			y += (py + ph) - (y - radius + vec.y) + 1;
			bounce(Direction::DOWN);

			if constexpr (std::is_same_v<T, Brick>)
			{
				if (!hit)
				object.hit();
				hit = true;
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