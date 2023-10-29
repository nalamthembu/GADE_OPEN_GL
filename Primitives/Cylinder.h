#pragma once
#include <GL/glut.h>
#include <cmath>
#include "glm/glm.hpp"
#include "PrimitiveShape.h"


class Cylinder: public PrimitiveShape {
public:

    Cylinder(float radius, float height, int numSegments);
private:
    float radius_;
    float height_;
    int numSegments_;

protected:
    void draw() override;
};