#pragma once
#include <GL/glut.h>
#include "glm/glm.hpp"
#include <cmath>
#include "PrimitiveShape.h"

class Sphere : public PrimitiveShape 
{
public:

    Sphere(float radius, int slices = 30, int stacks = 30) {
        
        this->radius = radius;
        this->slices = slices;
        this->stacks = stacks;

        this->position = glm::vec3(0, 0, 0);
        this->rotation = glm::vec3(0, 0, 0);
        this->scale = glm::vec3(1, 1, 1);
    }

protected:
    void draw() override;

private:
    float radius;
    int slices;
    int stacks;
};