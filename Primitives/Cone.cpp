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

    // Draw the bottom base of the cone
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5, 0.5); // Center of the bottom base
    glVertex3f(0.0, 0.0, 0.0);
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0 * M_PI * static_cast<float>(i) / slices;
        glTexCoord2f(0.5 * cos(angle) + 0.5, 0.5 * sin(angle) + 0.5);
        glVertex3f(radius * cos(angle), 0.0, radius * sin(angle));
    }
    glEnd();

    // Draw the sides of the cone with texture coordinates
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0 * M_PI * static_cast<float>(i) / slices;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        // Calculate texture coordinates based on the angle and height
        float s = static_cast<float>(i) / slices;
        float t = static_cast<float>(i) / slices;

        glTexCoord2f(s, 0.0);
        glVertex3f(x, 0.0, z);

        glTexCoord2f(s, 1.0);
        glVertex3f(0.0, height, 0.0);
    }
    glEnd();

    glPopMatrix();
}