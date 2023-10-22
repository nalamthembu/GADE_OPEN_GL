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

    float M_PI = 3.15F;

    // Draw the sides of the cylinder
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= numSegments_; i++) {
        angle = 2.0f * M_PI * i / numSegments_;
        x = radius_ * std::cos(angle);
        y = radius_ * std::sin(angle);
        z = 0.0f;
        glVertex3d(x, y, 0.0);
        glVertex3d(x, y, height_);
    }
    glEnd();

    // Draw the top and bottom circles of the cylinder
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments_; i++) {
        angle = 2.0f * M_PI * i / numSegments_;
        x = radius_ * std::cos(angle);
        y = radius_ * std::sin(angle);
        z = 0.0f;
        glVertex3d(x, y, 0.0);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments_; i++) {
        angle = 2.0f * M_PI * i / numSegments_;
        x = radius_ * std::cos(angle);
        y = radius_ * std::sin(angle);
        z = height_;
        glVertex3d(x, y, height_);
    }
    glEnd();
}