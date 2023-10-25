#pragma once
#include "GL/freeglut.h"
#include "PieceColour.h"
#include ""

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
};