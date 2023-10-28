#pragma once
struct Vertex
{
	float x;
	float y;
	float z;

	Vertex(float x, float y, float z)
	{
		//VERTEX POSITIONS
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vertex()
	{
		x = 0;
		y = 0;
		z = 0;
	}
};