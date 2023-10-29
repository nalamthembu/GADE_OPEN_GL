#include "Chesspiece.h"
#include "GL/freeglut.h"
#include <iostream>

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

vec3 Chesspiece::getPosition()
{
	return position;
}


vec3 Chesspiece::getRotation()
{
	return rotation;
}

vec3 Chesspiece::getScale()
{
	return scale;
}

PieceColour Chesspiece::GetColour()
{
	return this->colour;
}

void Chesspiece::MoveForward()
{
	switch (colour) {

	case PieceColour::BLACK:
		SetPosition(getPosition() + vec3(0, 0, -1));

	case PieceColour::WHITE:
		SetPosition(getPosition() + vec3(0, 0, 1));
	}

	std::cout << "Moved" << std::endl;
}
