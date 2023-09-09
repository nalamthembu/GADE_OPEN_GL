#pragma once
#include "GameObject.h"
#include "Behaviour.h"
#include <GL/freeglut.h>

class Cube : public GameObject
{
public:
	void drawGeometry() override
	{
		glutSolidCube(1);
	}
};