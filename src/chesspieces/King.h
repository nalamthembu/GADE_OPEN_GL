#pragma once
#include "Chesspiece.h"
#include "Torus.h"
#include "Cylinder.h"
#include "Cube.h";
#include "Cone.h"

class King : public Chesspiece
{
protected:

	void draw() override;

private:
	Cylinder* cylinder_base;
	Cylinder* cylinder_head;
	Cylinder* cylinder_body;
	Torus* torus;
	Cone* cone;
	Cube* cube_cross_0;
	Cube* cube_cross_1;

public:

	King(PieceColour pieceColour);

	~King();
};

