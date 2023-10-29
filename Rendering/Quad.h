#pragma once
#include "Vertex.h"

//This class is used to store 4 vertices to create a quad.
struct Quad
{
	Vertex vert1;
	Vertex vert2;
	Vertex vert3;
	Vertex vert4;

	Quad(Vertex vert1, Vertex vert2,
		Vertex vert3, Vertex vert4)
	{
		this->vert1 = vert1;
		this->vert2 = vert1;
		this->vert3 = vert1;
		this->vert4 = vert1;
	}

	Quad()
	{
		vert1 = Vertex();
		vert2 = Vertex();
		vert3 = Vertex();
		vert4 = Vertex();
	}
};