#pragma once
struct QuadTexCoord
{
	float x1;
	float y1;

	float x2;
	float y2;

	float x3;
	float y3;
	
	float x4;
	float y4;

	QuadTexCoord(
    float x1,
	float y1,
	float x2,
	float y2,
	float x3,
	float y3,
	float x4,
	float y4)
	{
		this->x1 = x1;
		this->x2 = x2;
		this->x3 = x3;
		this->x4 = x4;

		this->y1 = y1;
		this->y2 = y2;
		this->y3 = y3;
		this->y4 = y4;
	}
};