#pragma once
#include "Chesspiece.h"
#include "Cylinder.h"
#include "Cube.h";

class Knight : public Chesspiece
{
public:
	Knight(PieceColour colour);
	~Knight();

protected:
	void draw() override;

private:
	Cylinder* cylinder_base;
	Cube* cube_body;
	Cube* cube_head;
};