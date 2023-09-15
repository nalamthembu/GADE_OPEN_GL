#pragma once
#include "GL/freeglut.h"
#include "glm/glm.hpp"

using namespace glm;

class Camera
{
public:
	float fov = 60;
	double height;
	double width;
	float nearZ;
	float farZ;

	vec3 position = vec3(0,0,0);
	vec3 rotation = vec3(0,0,0);

	Camera(float fov, float height, float width, float nearZ, float farZ)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		this->fov = fov;
		this->width = width;
		this->height = height;
		this->nearZ = nearZ;
		this->farZ = farZ;

		gluPerspective(this->fov, this->width / this->height, this->nearZ, this->farZ);
	}

	void SetPosition(vec3 pos)
	{
		glTranslatef(pos.x, pos.y, pos.z);
	}

	void SetClearColour(vec4 colour)
	{
		glClearColor(colour.x, colour.y, colour.z, colour.w);
	}

	void SetRotation(vec3 rot)
	{
		glRotatef(rot.x, 1, 0, 0);
		glRotatef(rot.y, 0, 1, 0);
		glRotatef(rot.z, 0, 0, 1);
	}

	void LookAt(vec3 pos, vec3 tar)
	{
		position = pos;

		gluLookAt
		(
			position.x, position.y, position.z,
			tar.x, tar.y, tar.z,
			0.0, 1.0, 0.0
		);
	}

	void Update()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void LateUpdate()
	{
		glutSwapBuffers();
	}
};