#pragma once
#include <math.h>

struct Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	};

	Vector3()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	float Distance(Vector3 a, Vector3 b)
	{
		float x2 = (a.x - b.x) * (a.x - b.x);
		float y2 = (a.y - b.y) * (a.y - b.y);
		float z2 = (a.z - b.z) * (a.z - b.z);

		return sqrt(x2 + y2 + z2);
	}

	float DistanceSqr(Vector3 a, Vector3 b)
	{
		float x2 = (a.x - b.x) * (a.x - b.x);
		float y2 = (a.y - b.y) * (a.y - b.y);
		float z2 = (a.z - b.z) * (a.z - b.z);

		return (x2 + y2 + z2);
	}

	float GetMagnitude()
	{
		return sqrt((x * x) + (y * y) + (z * z));
	}
};