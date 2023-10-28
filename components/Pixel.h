#pragma once

struct Pixel
{
	//information for the Pixels- storing the colours (RGB) and transparency (alpha)
	float r;
	float g;
	float b;
	float a;

	Pixel(float r, float g, float b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = 1;
	}

	void SetAlpha(float alpha)
	{
		a = alpha;
	}
	
	Pixel()
	{
		this->r = 0;
		this->g = 0;
		this->b = 0;
		this->a = 1;
	}
};

inline Pixel operator*(const Pixel& left, float right)
{
	return Pixel(left.r * right, left.g * right, left.b * right);
}

inline Pixel operator*(const Pixel& left, Pixel right)
{
	return Pixel(left.r * right.r, left.g * right.g, left.b * right.b);
}

