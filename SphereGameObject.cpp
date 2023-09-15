#include "SphereGameObject.h"
#include <GL/freeglut.h>

//new terrain game object and load height map here for POE
void SphereGameObject::drawGeometry()
{
	glColor3f(1, 1, 1);
	//low poly less than this
	glutSolidSphere(0.5f, 12, 12);
}
