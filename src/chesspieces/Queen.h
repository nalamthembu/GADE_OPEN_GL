#pragma once
#include "Cylinder.h"
#include "Cone.h"
#include "Chesspiece.h"
#include "Sphere.h"

class Queen : public Chesspiece
{
protected:
	void draw() override;

private:
	Cylinder* cylinder_base;
	Cone* cone_base;
	Cylinder* cylinder_body;
	Cylinder* cylinder_head;
	Cone* cone_head;
	Sphere* sphere_hat;
	Sphere* sphere_hat_top;

public:
	Queen(PieceColour pieceColour);

	~Queen();
};

