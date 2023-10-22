#pragma once
#include "Chesspiece.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Sphere.h"

class Pawn : public Chesspiece
{
protected :
	
	void draw() override;

private:
	Cylinder* cylinder;
	Cone* cone;
	Sphere* sphere;

public:

	Pawn(PieceColour pieceColour);

	~Pawn();
};