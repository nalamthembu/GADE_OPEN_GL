#pragma once
#include <math.h>

struct Vector2
{
public:
	float x;
	float y;
	float magnitude =
		sqrt((x * x) + (y * y));

	Vector2(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
	}
};