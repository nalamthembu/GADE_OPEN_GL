#include "Chesspiece.h"
#include "GL/freeglut.h"

void Chesspiece::draw()
{
	printf("not being implemented");
}

Chesspiece::Chesspiece(PieceColour pieceColour)
{
	scale = vec3(1, 1, 1);
	this->colour = pieceColour;
	position = vec3(0, 0, 0);
	rotation = vec3(0, 0, 0);
}

void Chesspiece::update()
{
	//Set POS, ROT, SCALE
	glPushMatrix();
	{
		glTranslated(position.x, position.y, position.z);

		glRotated(rotation.x, 1, 0, 0);
		glRotated(rotation.y, 0, 1, 0);
		glRotated(rotation.z, 0, 0, 1);

		glScaled(scale.x, scale.y, scale.z);

		switch (colour)
		{
		case PieceColour::BLACK:

			glColor3f(0, 0, 0);

			break;

		case PieceColour::WHITE:

			glColor3f(1, 1, 1);

			break;
		}

		draw();
	}
	glPopMatrix();
}

void Chesspiece::SetPosition(vec3 position)
{
	this->position = position;
}

void Chesspiece::SetRotation(vec3 rotation)
{
	this->rotation = rotation;
}

void Chesspiece::SetScale(vec3 scale)
{
	this->scale = scale;
}
