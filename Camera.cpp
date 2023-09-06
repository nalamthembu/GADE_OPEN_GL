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
		0.0, 0.0, 10.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0
	);

	Update();
}

void Camera::Update()
{

}

void Camera::SetClearColour(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}