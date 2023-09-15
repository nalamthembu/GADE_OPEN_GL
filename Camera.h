#pragma once
#include "GL/freeglut.h"
#include "glm/glm.hpp"

using namespace glm;

struct Camera
{
public:
	float fov = 60;
	double height;
	double width;
	float nearZ;
	float farZ;

	Camera(float fov, float height, float width, float nearZ, float farZ)
	{
		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();

		this->fov = fov;
		this->width = width;
		this->height = height;
		this->nearZ = nearZ;
		this->farZ = farZ;

		gluPerspective(this->fov, this->width / this->height, this->nearZ, this->farZ);

		glClearColor(0, 0, 0, 0);
	}

	void LookAt(vec3 pos, vec3 tar)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);

		gluLookAt
		(
			pos.x, pos.y, pos.z,
			tar.x, tar.y, tar.z,
			0.0, 1.0, 0.0

		);
	}

	void LateUpdate()
	{
		glutSwapBuffers();
	}
};