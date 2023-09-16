#pragma once
#include "GameObject.h"
#include "GL/freeglut.h"
#include "glm/glm.hpp"

class Plane : public GameObject
{
private:

	float s = 0.5F;

	glm::vec3 verts[4]
	{
		vec3(-s, -s, s),
		vec3(s, -s, s),
		vec3(s, s, s),
		vec3(-s, s, s)
	};

	glm::vec2 texCoords[4]
	{
		vec2(0, 0),
		vec2(1, 0),
		vec2(1, 1),
		vec2(0, 1),
	};

public:
	void drawGeometry() override
	{
		glBegin(GL_QUADS);
		{
			for (int i = 0; i < 4; i++)
			{
				glVertex3f(verts[i].x, verts[i].y, verts[i].z);
				glTexCoord2f(texCoords[i].x, texCoords[i].y);
			}
		}
		glEnd();
	}
};