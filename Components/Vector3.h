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

	float Distance(Vector3 a, Vector3 b)
	{
		return sqrt((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
	}

	float SqrDistance(Vector3 a, Vector3 b)
	{
		return sqrt((a.x * b.x) + (a.y * b.y) + (a.z * b.z));

	}
};