#pragma once
#include "VertexQ.h"

//This class is used to store 4 vertices to create a quad.
struct Quad
{
	VertexQ vert1;
	VertexQ vert2;
	VertexQ vert3;
	VertexQ vert4;

	Quad(VertexQ vert1, VertexQ vert2,
		VertexQ vert3, VertexQ vert4)
	{
		this->vert1 = vert1;
		this->vert2 = vert1;
		this->vert3 = vert1;
		this->vert4 = vert1;
	}

	Quad()
	{
		vert1 = VertexQ();
		vert2 = VertexQ();
		vert3 = VertexQ();
		vert4 = VertexQ();
	}
};