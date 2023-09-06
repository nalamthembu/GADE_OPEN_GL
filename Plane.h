#pragma once
#include <GL/freeglut.h>
#include <GL/glut.h>
#include "GameObject.h"
class Plane : public GameObject
{
public:
	void drawGeometry() override;
};

