#include "Pawn.h"

void Pawn::draw()
{
	//Colour

	//cylinder->update();

	cone->update();

	sphere->update();
}

Pawn::Pawn(PieceColour pieceColour) : Chesspiece(pieceColour)
{
	//Creating shape
	
	//Base
	cylinder = new Cylinder(1, 0.5F, 16);

	cylinder->SetRotation(vec3(90, 0, 0));

	cylinder->setScale(vec3(0.5, 0.5, 0.5));

	//Neck
	cone = new Cone(1.0, 2.0, 6, 6);

	cone->setScale(vec3(0.35, 0.35, 0.35));

	cone->setPosition(cylinder->GetPosition() + vec3(0, 0.35, 0));

	//Head
	sphere = new Sphere(2, 8, 8);

	sphere->setPosition(vec3(0, 0.65, 0));

	sphere->setScale(vec3(0.15, 0.15, 0.15));
}

Pawn::~Pawn()
{
	delete cylinder;
	delete cone;
	delete sphere;
}