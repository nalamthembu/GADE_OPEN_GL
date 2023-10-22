#include "Queen.h"

void Queen::draw()
{
	cylinder_base->update();
	cone_base->update();
	cylinder_body->update();
	cone_head->update();
	sphere_hat->update();
	sphere_hat_top->update();
	cylinder_head->update();
}

Queen::Queen(PieceColour pieceColour) : Chesspiece(pieceColour)
{
	//Create Shape

	//BASE
	cylinder_base = new Cylinder(1.15, 0.5F, 8);

	cylinder_base->SetRotation(vec3(90, 0, 0));

	cylinder_base->SetScale(vec3(0.45, 0.45, 0.45));

	cone_base = new Cone(0.5, 1.5, 8, 8);

	cone_base->SetPosition(cylinder_base->GetPosition() + vec3(0, 0.5, 0));

	//BODY
	cylinder_body = new Cylinder(0.25, 1, 8);

	cylinder_body->SetRotation(vec3(90, 0, 0));

	cylinder_body->SetPosition(cone_base->GetPosition() + vec3(0, 1, 0));


	//BODY
	cone_head = new Cone(0.45, 1.5, 8, 8);

	cone_head->SetPosition(cylinder_body->GetPosition() - vec3(0, 0.25, 0));

	cone_head->SetRotation(vec3(180, 0, 0));

	//HEAD
	cylinder_head = new Cylinder(1.0, 1, 16);

	cylinder_head->SetScale(vec3(0.3,0.3,0.3));

	cylinder_head->SetPosition(cone_head->GetPosition() + vec3(0,0.35,0));

	cylinder_head->SetRotation(vec3(90, 0, 0));

	//Hat

	sphere_hat = new Sphere(0.15);

	sphere_hat->SetPosition(cone_head->GetPosition() + vec3(0, 0.8, 0));

	sphere_hat_top = new Sphere(0.05);

	sphere_hat_top->SetPosition(sphere_hat_top->GetPosition() + vec3(0, 2.2, 0));
}

Queen::~Queen()
{
	delete cylinder_base;
	delete cone_base;
	delete cylinder_body;
	delete cone_head;
	delete sphere_hat_top;
	delete sphere_hat;
	delete cylinder_body;
}

