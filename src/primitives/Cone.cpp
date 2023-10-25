#include "Cone.h"

Cone::Cone(float radius, float height, int slices, int stacks)
{

    this->radius = radius;
    this->height = height;
    this->slices = slices;
    this->stacks = stacks;

}

void Cone::draw()
{
    glPushMatrix();

    glTranslatef(0.0, -height / 2, 0.0);

    float M_PI = 3.15F;

    // Draw the bottom base of the cone
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0, 0.0, 0.0); // Center of the bottom base
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0 * M_PI * static_cast<float>(i) / slices;
        glVertex3f(radius * cos(angle), 0.0, radius * sin(angle));
    }
    glEnd();

    // Draw the sides of the cone
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0 * M_PI * static_cast<float>(i) / slices;
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        glVertex3f(x, 0.0, z);
        glVertex3f(0.0, height, 0.0);
    }
    glEnd();

    glPopMatrix();
}
