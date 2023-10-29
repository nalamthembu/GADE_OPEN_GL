#include "Bishop.h"

void Bishop::draw()
{
	cylinder_base->update();
	cone->update();
	cylinder_body->update();
	sphere_head->update();
	sphere_head_top->update();
	torus_neck->update();
	torus->update();
}

Bishop::Bishop(PieceColour pieceColour) : Chesspiece(pieceColour)
{
	//Creating Shape

	//Base 

	cylinder_base = new Cylinder(1, 0.5F, 16);

	cylinder_base->SetRotation(vec3(90, 0, 0));

	cylinder_base->setScale(vec3(0.5, 0.5, 0.5));

	//Body

	cone = new Cone(1, 3.0, 6, 6);

	cone->setScale(vec3(0.4, 0.4, 0.4));

	cone->setPosition(cylinder_base->GetPosition() + vec3(0, 0.5, 0));

	cylinder_body = new Cylinder(0.30, 1, 16);

	cylinder_body->setPosition(cone->GetPosition() + vec3(0, 0.67, 0));

	cylinder_body->SetRotation(vec3(90, 0, 0));

	float d_body_cyl = 0.67F;

	cylinder_body->setScale(vec3(d_body_cyl, d_body_cyl, d_body_cyl));

	torus = new Torus(1.0, 0.3);

	torus->setScale(vec3(0.35, 0.35, 0.35));

	torus->SetRotation(vec3(90, 0, 0));

	torus->setPosition(vec3(0, 0.05, 0));

	//Neck

	torus_neck = new Torus(1.0, 0.3);

	float sc_neck = 0.30F;

	torus_neck->setScale(vec3(sc_neck, sc_neck, sc_neck));

	torus_neck->SetRotation(vec3(90, 0, 0));

	torus_neck->setPosition(vec3(0, 1, 0));

	//Head

	sphere_head = new Sphere(1, 12, 12);

	float d = 0.36F;

	sphere_head->setScale(vec3(d, d, d));

	sphere_head->setPosition(cylinder_base->GetPosition() + vec3(0, 1.25, 0));

	sphere_head->SetRotation(vec3(90, 0, 0));

	sphere_head_top = new Sphere(1, 12, 12);

	float d_t = 4.0F; //Divider

	sphere_head_top->setScale(cylinder_base->GetScale() / vec3(d_t, d_t, d_t));

	sphere_head_top->setPosition(sphere_head->GetPosition() + vec3(0, 0.35F, 0));

	sphere_head_top->SetRotation(vec3(90, 0, 0));
}

Bishop::~Bishop()
{
	delete cylinder_base;
	delete cone;
	delete cylinder_body;
	delete sphere_head;
	delete sphere_head_top;
	delete torus_neck;
	delete torus;
}
