#include "Camera.h"
#include <GL/freeglut.h>


Camera::Camera(float FOV, int width, int height, float nearZ, float farZ)
{
	this->FOV = FOV;
	this->width = width;
	this->height = height;
	this->nearZ = nearZ;
	this->farZ = farZ;
	
	glMatrixMode(GL_PROJECTION);
	
	glLoadIdentity();
	gluPerspective(this->FOV, (double)this->width / (double)this->height, this->nearZ, this->farZ);

	gluLookAt
	(
		0.0, 0.0, 25.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0
	);

	glClearColor(0.2f, 0.2f, 0.3f, 1.0f);

	Update();
}

void Camera::Update()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Camera::SetClearColour(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}