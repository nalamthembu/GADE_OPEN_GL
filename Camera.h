#pragma once
#include "GameObject.h"

class Camera : public GameObject
{
	float FOV;
	double width;
	double height;
	float nearZ;
	float farZ;

public:
	Camera(float FOV, int width, int height, float nearZ, float farZ);
	void Update();
	void SetClearColour(float r, float g, float b, float a);
};