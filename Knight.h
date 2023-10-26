#pragma once
#include "Chesspiece.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Cube.h"

class Knight : public Chesspiece
{
protected:

	void draw() override;

private:
	Cylinder* cylinder_base;
	Cube* cube_head;
	Cube* cube_body;

public:

	Knight(PieceColour pieceColour);

	~Knight();
};

