#include "Cylinder.h"
#include <iostream>

Cylinder::Cylinder(float radius, float height, int numSegments) :
    radius_(radius), height_(height), numSegments_(numSegments)
{

}

void Cylinder::draw()
{
    float angle;
    float x, y, z;

    // Draw the sides of the cylinder with texture coordinates
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= numSegments_; i++) {
        angle = 2.0f * M_PI * i / numSegments_;
        x = radius_ * std::cos(angle);
        y = radius_ * std::sin(angle);
        z = 0.0f;

        // Calculate texture coordinates for the sides
        float s = static_cast<float>(i) / numSegments_;
        for (int j = 0; j < 2; j++) {
            float t = static_cast<float>(j);
            glTexCoord2f(s, t);
            glVertex3d(x, y, t * height_);
        }
    }
    glEnd();

    // Draw the top circle of the cylinder with texture coordinates
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments_; i++) {
        angle = 2.0f * M_PI * i / numSegments_;
        x = radius_ * std::cos(angle);
        y = radius_ * std::sin(angle);
        z = 0.0f;

        // Calculate texture coordinates for the top circle
        float s = 0.5f * (1 + x / radius_);
        float t = 0.5f * (1 + y / radius_);
        glTexCoord2f(s, t);

        glVertex3d(x, y, z);
    }
    glEnd();

    // Draw the bottom circle of the cylinder with texture coordinates
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments_; i++) {
        angle = 2.0f * M_PI * i / numSegments_;
        x = radius_ * std::cos(angle);
        y = radius_ * std::sin(angle);
        z = height_;

        // Calculate texture coordinates for the bottom circle
        float s = 0.5f * (1 + x / radius_);
        float t = 0.5f * (1 + y / radius_);
        glTexCoord2f(s, t);

        glVertex3d(x, y, z);
    }
    glEnd();
}
