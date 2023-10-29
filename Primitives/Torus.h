#pragma once
#include <GL/glut.h>
#include <cmath>
#include "PrimitiveShape.h"

class Torus : public PrimitiveShape
{
public:
    
    Torus(float majorRadius, float minorRadius, int sides = 30, int rings = 30) {
        this->majorRadius = majorRadius;
        this->minorRadius = minorRadius;
        this->sides = sides;
        this->rings = rings;
    }

protected:
    void draw() override;

private:
    float majorRadius;
    float minorRadius;
    int sides;
    int rings;
};