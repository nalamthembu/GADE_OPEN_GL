#pragma once
#include "Pixel.h"

struct QuadColour
{
	Pixel p1;
	Pixel p2;
	Pixel p3;
	Pixel p4;

	QuadColour(Pixel p1,
		Pixel p2,
		Pixel p3,
		Pixel p4)
	{
		this->p1 = p1;
		this->p2 = p2;
		this->p3 = p3;
		this->p4 = p4;
	}

	QuadColour()
	{
		p1 = Pixel();
		p2 = Pixel();
		p3 = Pixel();
		p4= Pixel();
	}
};