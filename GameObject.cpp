#include "GameObject.h"
#include <GL/freeglut.h>
#include <iostream>
#include "Settings.h"

void GameObject::drawGeometry()
{
	//printf("Inherited member not implemented");
}

void GameObject::drawOrigin()
{
    glDisable(GL_DEPTH_TEST);

    glBegin(GL_LINES);
    {
        //X-AXIS
        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(originSize, 0, 0);

        //Y-AXIS
        glColor3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, originSize, 0);

        //Z-AXIS
        glColor3f(0, 0, 1);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, originSize);
    }
    glEnd();



    //X-CONE
    glPushMatrix();
    {
        glColor3f(1, 0, 0);
        glTranslatef(originSize, 0, 0);
        glRotatef(90, 0, 1, 0);
        glutSolidCone(0.05f, 0.2F, 8, 1);
    }
    glPopMatrix();

    //Y-CONE
    glPushMatrix();
    {
        glColor3f(0, 1, 0);
        glTranslatef(0, originSize, 0);
        glRotatef(-90, 1, 0, 0);
        glutSolidCone(0.05f, 0.2F, 8, 1);
    }
    glPopMatrix();

    //Z-CONE - NEEDS WORK
    glPushMatrix();
    {
        glColor3f(0, 0, 1);
        glTranslatef(0, 0, originSize);
        glRotatef(-90, 0, 0, 1);
        glutSolidCone(0.05f, 0.2F, 8, 1);
    }
    glPopMatrix();




    glEnable(GL_DEPTH_TEST);
}

GameObject::GameObject(std::string name)
{
	this->name = name;
	transform = new Transform;
}

GameObject::GameObject()
{
    this->name = "New Game Object";
    transform = new Transform;
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


		if (transform->scale->GetMagnitude() <= 0)
		{
			transform->scale = new Vector3(1, 1, 1);
		}

		glScalef(transform->scale->x, transform->scale->y, transform->scale->z);

		drawGeometry();

        if (Settings::IsInDebugMode) {
            drawOrigin();
        }
	}
	glPopMatrix();
}