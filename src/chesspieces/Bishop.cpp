#include "Bishop.h"

void Bishop::draw()
{
	cylinder_base->update();
	cone->update();
	torus->update();
	cylinder_body->update();
	sphere_head->update();
	sphere_head_top->update();
}

Bishop::Bishop(PieceColour pieceColour) : Chesspiece(pieceColour)
{
	//Base 

	cylinder_base = new Cylinder(1, 0.5F, 16);

	cylinder_base->SetRotation(vec3(90, 0, 0));

	cylinder_base->SetScale(vec3(0.5, 0.5, 0.5));

	//Body

	cone = new Cone(1, 3.0, 6, 6);

	cone->SetScale(vec3(0.4, 0.4, 0.4));

	cone->SetPosition(cylinder_base->GetPosition() + vec3(0, 0.5, 0));

	cylinder_body = new Cylinder(0.2, 0.75, 16);

	cylinder_body->SetPosition(cone->GetPosition() + vec3(0, 0.75, 0));

	cylinder_body->SetRotation(vec3(90, 0, 0));

	torus = new Torus(1.0, 0.3);

	torus->SetScale(vec3(0.35, 0.35, 0.35));

	torus->SetRotation(vec3(90, 0, 0));

	torus->SetPosition(vec3(0, 0.05, 0));

	//Head

	sphere_head = new Sphere(1.25F, 16);

	float d = 2.0F; //Divider

	sphere_head->SetScale(cylinder_base->GetScale() / vec3(d, d, d));

	sphere_head->SetPosition(cylinder_base->GetPosition() + vec3(0, 1.5F, 0));

	sphere_head->SetRotation(vec3(90, 0, 0));

	sphere_head_top = new Sphere(1.25F, 16);

	float d_t = 4.0F; //Divider

	sphere_head_top->SetScale(cylinder_base->GetScale() / vec3(d_t, d_t, d_t));

	sphere_head_top->SetPosition(cylinder_base->GetPosition() + vec3(0, 1.78F, 0));

	sphere_head_top->SetRotation(vec3(90, 0, 0));
}

Bishop::~Bishop()
{
	delete cylinder_base;
	delete cone;
	delete sphere_head;
	delete torus;
	delete sphere_head_top;
}
