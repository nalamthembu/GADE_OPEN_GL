#pragma once
#include <GL/glut.h>
#include "PrimitiveShape.h"
class Cube :
    public PrimitiveShape
{

public:
    Cube(float sideLength) {
        this->sideLength = sideLength;
    }

protected:
    void draw() override;

private:
    float sideLength;
};

