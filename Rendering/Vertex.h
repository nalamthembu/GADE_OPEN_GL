#pragma once

//This is a struct that stores the (x,y,z) components of a vertex.
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