#include "Knight.h"

void Knight::draw()
{
	cylinder_base->update();
	cube_head->update();
	cube_body->update();
}

Knight::Knight(PieceColour pieceColour) : Chesspiece(pieceColour)
{
	cylinder_base = new Cylinder(1, 0.5F, 16);

	cylinder_base->SetRotation(vec3(90, 0, 0));

	cylinder_base->SetScale(vec3(0.5, 0.5, 0.5));

	cube_body = new Cube(1);

	cube_body->SetScale(vec3(0.4F, 2.0F, 0.4F));

	cube_body->SetRotation(vec3(-30, 0, 0));

	cube_body->SetPosition(cylinder_base->GetPosition() + vec3(-0.25F,-0.25F,-0.25F));

	cube_head = new Cube(1);

	cube_head->SetScale(vec3(0.5F, 1.0F, 0.5F));

	cube_head->SetRotation(vec3(90, 0, 0));

	cube_head->SetPosition(cube_body->GetPosition() + vec3(0, 2, -1));
}

Knight::~Knight()
{
	delete cylinder_base;
	delete cube_head;
	delete cube_body;
}
