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

	cylinder_base->SetScale(vec3(0.5, 0.5, 0.5));

	//Body

	cone = new Cone(1, 3.0, 6, 6);

	cone->SetScale(vec3(0.4, 0.4, 0.4));

	cone->SetPosition(cylinder_base->GetPosition() + vec3(0, 0.5, 0));

	cylinder_body = new Cylinder(0.30, 1, 16);

	cylinder_body->SetPosition(cone->GetPosition() + vec3(0, 0.67, 0));

	cylinder_body->SetRotation(vec3(90, 0, 0));

	float d_body_cyl = 0.67F;

	cylinder_body->SetScale(vec3(d_body_cyl, d_body_cyl, d_body_cyl));

	torus = new Torus(1.0, 0.3);

	torus->SetScale(vec3(0.35, 0.35, 0.35));

	torus->SetRotation(vec3(90, 0, 0));

	torus->SetPosition(vec3(0, 0.05, 0));

	//Neck

	torus_neck = new Torus(1.0, 0.3);

	float sc_neck = 0.30F;

	torus_neck->SetScale(vec3(sc_neck, sc_neck, sc_neck));

	torus_neck->SetRotation(vec3(90, 0, 0));

	torus_neck->SetPosition(vec3(0, 1, 0));

	//Head

	sphere_head = new Sphere(1, 12, 12);

	float d = 0.36F;

	sphere_head->SetScale(vec3(d, d, d));

	sphere_head->SetPosition(cylinder_base->GetPosition() + vec3(0, 1.25, 0));

	sphere_head->SetRotation(vec3(90, 0, 0));

	sphere_head_top = new Sphere(1, 12, 12);

	float d_t = 4.0F; //Divider

	sphere_head_top->SetScale(cylinder_base->GetScale() / vec3(d_t, d_t, d_t));

	sphere_head_top->SetPosition(sphere_head->GetPosition() + vec3(0, 0.35F, 0));

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
