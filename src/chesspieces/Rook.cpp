#include "Rook.h"
#include <iostream>

void Rook::draw()
{
	cylinder_base->update();
	cylinder_body->update();
	cone_body->update();
	torus_base->update();
	cylinder_head->update();
}

Rook::Rook(PieceColour pieceColour) : Chesspiece(pieceColour)
{
	//type name
	std::cout << typeid(this).name() << std::endl;


	//BASE
	cylinder_base = new Cylinder(1.15, 0.5F, 8);

	cylinder_base->SetRotation(vec3(90, 0, 0));

	cylinder_base->SetScale(vec3(0.45, 0.45, 0.45));

	cone_body = new Cone(0.5, 1.2, 8, 8);

	cone_body->SetPosition(cylinder_base->GetPosition() + vec3(0, 0.5, 0));

	torus_base = new Torus(1, 0.3);

	float torus_size = 0.35;

	torus_base->SetScale(vec3(torus_size, torus_size, torus_size));

	torus_base->SetPosition(vec3(0,0.05,0));

	torus_base->SetRotation(vec3(90, 0, 0));

	//BODY
	cylinder_body = new Cylinder(0.35, 1, 8);

	cylinder_body->SetRotation(vec3(90, 0, 0));

	cylinder_body->SetPosition(cone_body->GetPosition() + vec3(0, 0.5, 0));

	//HEAD

	cylinder_head = new Cylinder(1.15, 1.15F, 8);

	cylinder_head ->SetPosition(vec3(0,1.15,0));

	cylinder_head->SetRotation(vec3(90, 0, 0));

	cylinder_head->SetScale(vec3(0.4, 0.4, 0.4));
}

Rook::~Rook()
{
	delete cylinder_base;
	delete cylinder_body;
	delete cone_body;
	delete cylinder_head;
	delete torus_base;
}
