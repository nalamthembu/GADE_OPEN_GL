#include "GameObject.h"
#include <GL/freeglut.h>
#include <iostream>
#include "Settings.h"
#include <math.h>

void GameObject::setPosition(vec3 position)
{
	this->position = position;
}

void GameObject::setRotation(vec3 rotation)
{
	this->rotation = rotation;
}

vec3 GameObject::getPosition()
{
	return position;
}

vec3 GameObject::normalised()
{
	float x = sqrt(position.x);
	float y = sqrt(position.y);
	float z = sqrt(position.z);

	return vec3(x, y, z);
}

void GameObject::draw()
{
	glEnable(GL_DEPTH_TEST);

	//saves cuurent state we at
	glPushMatrix();
	{
		//translating where we want to draw the geometry - then revert back to state before we drew
		glTranslatef(position.x, position.y, position.z);

		glRotatef(rotation.x, 1, 0, 0);
		glRotatef(rotation.y, 0, 1, 0);
		glRotatef(rotation.z, 0, 0, 1);

		drawGeometry();
	
		if (Settings::debug)
		{
			drawOrigin();
		}
	
	}
	//reverts back to original state
	glPopMatrix();
	
}

void GameObject::drawGeometry()
{
}

void GameObject::drawOrigin()
{
	//draw on top over everything 
	glDisable(GL_DEPTH_TEST);

	glBegin(GL_LINES);
	{
		//x axis - red
		glColor3f(1, 0, 0);
		//at origin
		glVertex3f(0, 0, 0);
		glVertex3f(originSize, 0, 0);

		//y axis - green
		glColor3f(0, 1, 0);
		//at origin
		glVertex3f(0, 0, 0);
		glVertex3f(0, originSize, 0);

		//z axis - blue
		glColor3f(0, 0, 1);
		//at origins
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, originSize);


	
	}
	glEnd();

	//x cone
	glPushMatrix();
	{
		glColor3f(1, 0, 0);
		glTranslatef(originSize, 0, 0);
		glRotatef(90, 0, 1, 0);
		glutSolidCone(0.05, 0.2, 8, 1);

	}
	glPopMatrix();

	glEnable(GL_DEPTH_TEST);

	//y cone
	glPushMatrix();
	{
		glColor3f(0, 1, 0);
		glTranslatef(0, originSize, 0);
		glRotatef(-90, 1, 0, 0);
		glutSolidCone(0.05, 0.2, 8, 1);

	}
	glPopMatrix();

	//z cone
	glPushMatrix();
	{
		glColor3f(0, 0, 1);
		glTranslatef(0, 0, originSize);
		glRotatef(0, 0, 0, 0);
		glutSolidCone(0.05, 0.2, 8, 1);

	}
	glPopMatrix();

	
}


