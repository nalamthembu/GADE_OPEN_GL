#pragma once
#include "Chesspiece.h"
#include "Cylinder.h";
#include "Torus.h"
#include "Cone.h"

class Rook : public Chesspiece
{
protected:
	void draw() override;

private:
	Cylinder* cylinder_base;
	Cylinder* cylinder_body;
	Cone* cone_body;
	Cylinder* cylinder_head;
	Torus* torus_base;

public:
	Rook(PieceColour pieceColour);

	~Rook();
};

