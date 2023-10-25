#include "Knight.h"

Knight::Knight(PieceColour colour) : Chesspiece(colour)
{
	//Base 

	cylinder_base = new Cylinder(1, 0.5F, 16);

	cylinder_base->SetRotation(vec3(90, 0, 0));

	cylinder_base->SetScale(vec3(0.5, 0.5, 0.5));

	//Body
	cube_body = new Cube(1);

	cube_body->SetScale(vec3(1, 2, 1));

	cube_body->SetPosition(vec3(0, 2, 0));

	//Head

	cube_head = new Cube(1);

	cube_head->SetScale(vec3(1, 2, 1));

	cube_head->SetPosition(vec3(0, 2, 0));

	cube_head->SetRotation(vec3(90, 0, 0));
}

Knight::~Knight()
{
	delete cylinder_base;
	delete cube_body;
	delete cube_head;
}

void Knight::draw()
{
	cylinder_base->update();
	cube_body->update();
	cube_head->update();
}




