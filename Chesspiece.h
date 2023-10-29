#pragma once
#include "components/GameObject.h"
#include "GL/freeglut.h"
#include "PieceColour.h"

class Chesspiece
{
protected:
	PieceColour colour;
	virtual void draw();
	vec3 position;
	vec3 rotation;
	vec3 scale;

public:
	 Chesspiece(PieceColour pieceColour);
	virtual void update();
	void SetPosition(vec3 position);
	void SetRotation(vec3 rotation);
	void SetScale(vec3 scale);
	vec3 getPosition();
	vec3 getRotation();
	vec3 getScale();
	PieceColour GetColour();
	vec3 originalPosition;
	void MoveForward();
};