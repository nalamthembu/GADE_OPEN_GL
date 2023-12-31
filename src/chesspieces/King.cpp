#include "King.h"
#include <iostream>

void King::draw()
{
	cylinder_base->update();
	cone->update();
	cylinder_body->update();
	cylinder_head->update();
	torus->update();
	cube_cross_0->update();
	cube_cross_1->update();
}

King::King(PieceColour pieceColour) : Chesspiece (pieceColour)
{
	//type name 
	std::cout << typeid(this).name() << std::endl;


	//Creating Shape

	//Base 

	cylinder_base = new Cylinder(1, 0.5F, 16);

	cylinder_base->SetRotation(vec3(90, 0, 0));

	cylinder_base->SetScale(vec3(0.5, 0.5, 0.5));

	//Body

	cone = new Cone(1, 3.0, 6, 6);

	cone->SetScale(vec3(0.4, 0.4, 0.4));

	cone->SetPosition(cylinder_base->GetPosition() + vec3(0, 0.5, 0));

	cylinder_body = new Cylinder(0.2, 1.5, 16);

	cylinder_body->SetPosition(cone->GetPosition() + vec3(0,1,0));

	cylinder_body->SetRotation(vec3(90, 0, 0));

	torus = new Torus(1.0, 0.3);

	torus->SetScale(vec3(0.35, 0.35, 0.35));

	torus->SetRotation(vec3(90, 0, 0));

	torus->SetPosition(vec3(0, 0.05, 0));

	//Head

	cylinder_head = new Cylinder(1, 1.5, 16);

	float d = 1.7F; //Divider

	cylinder_head->SetScale(cylinder_base->GetScale() / vec3(d,d,d));

	cylinder_head->SetPosition(cylinder_base->GetPosition() + vec3(0, 1.5, 0));

	cylinder_head->SetRotation(vec3(90, 0, 0));

	//King Cross Hat

	cube_cross_0 = new Cube(0.5);

	cube_cross_0->SetPosition(cylinder_head->GetPosition());

	cube_cross_0->SetScale(vec3(0.25, 1, 0.15));

	cube_cross_1 = new Cube(0.5);

	cube_cross_1->SetPosition(cube_cross_0 ->GetPosition() + vec3(0.27 ,0.25,0));

	cube_cross_1->SetScale(vec3(0.25, 1, 0.15));

	cube_cross_1->SetRotation(vec3(0, 0, 90));

}

King::~King()
{
	delete cylinder_base;
	delete cylinder_head;
	delete cone;
	delete torus;
	delete cube_cross_0;
	delete cube_cross_1;
}
