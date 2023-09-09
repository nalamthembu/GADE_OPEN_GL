#include "GameObject.h"
#include "Transform.h"
#include <GL/freeglut.h>

GameObject::GameObject()
{
    transform = new Transform();
}

GameObject::~GameObject()
{
    delete transform;
}

void GameObject::draw()
{
	glPushMatrix();
	{
		glTranslatef(transform->position->x, transform->position->y, transform->position->z);
		glRotatef(transform->rotation->x, 1, 0, 0);
		glRotatef(transform->rotation->y, 0, 1, 0);
		glRotatef(transform->rotation->z, 0, 0, 1);
		glScalef(transform->scale->x, transform->scale->y, transform->scale->z);
		drawGeometry();
	}
	glPopMatrix();
}

void GameObject::drawGeometry()
{
	//do something.
}

void GameObject::OnUpdate()
{
	draw();
}
