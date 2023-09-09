#pragma once
#include "Vector3.h"

struct Transform
{
public:
	
	Vector3* position;
	Vector3* rotation;
	Vector3* scale;

	Transform()
	{
		position = new Vector3(0, 0, 0);
		rotation = new Vector3(0, 0, 0);
		scale = new Vector3(1, 1, 1);
	}

	~Transform()
	{
		delete position;
		delete rotation;
		delete scale;
	}
};