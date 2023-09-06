#pragma once
#include "Vector3.h"
struct Transform
{
	Transform()
	{
		position = new Vector3;
		rotation = new Vector3;
		scale = new Vector3;
	};

	~Transform()
	{
		delete position;
		delete rotation;
		delete scale;
	};

public:
	Vector3* position;
	Vector3* rotation;
	Vector3* scale;
};