#pragma once
#include <math.h>

struct Vector3
{
public:
	float x;
	float y;
	float z;
	float magnitude =
		sqrt((x * x) + (y * y) + (z * z));

	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};