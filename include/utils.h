#pragma once
#include <random>
#define SCREEN_W 1000
#define SCREEN_H 1000


struct vec2d
{
	float x, y;
};

enum class Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

inline float random_float(float min, float max)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> uni(min, max);

	return uni(rng);
}