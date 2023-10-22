#pragma once
#include <GL/glut.h>
#include <cmath>
#include "PrimitiveShape.h"

class Cone : public PrimitiveShape
{
public:
    
    Cone(float radius, float height, int slices = 30, int stacks = 30);
    
protected:
    void draw() override;

private:
    float radius;
    float height;
    int slices;
    int stacks;
};