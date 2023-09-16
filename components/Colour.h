#pragma once
struct Colour
{
public:

	float r;
	float g;
	float b;
	float a;

	Colour(float r, float g, float b, float a = 1)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
};