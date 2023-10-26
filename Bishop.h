#pragma once
#include "Chesspiece.h"
#include "Cylinder.h"
#include "Torus.h"
#include "Cone.h"
#include "Sphere.h"

class Bishop : public Chesspiece
{
protected:

	void draw() override;

private:
	Cylinder* cylinder_base;
	Cylinder* cylinder_body;
	Sphere* sphere_head;
	Sphere* sphere_head_top;
	Torus* torus;
	Torus* torus_neck;
	Cone* cone;

public:

	Bishop(PieceColour pieceColour);

	~Bishop();
};

