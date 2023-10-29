#pragma once
#include <GL/glut.h>
#include <cmath>
#include "glm/glm.hpp"
#include <string>
#include <iostream>

#define M_PI 3.15

class PrimitiveShape
{
public:
    void SetRotation(glm::vec3 rotation);
    void setPosition(glm::vec3 position);
    void setScale(glm::vec3 scale);
    void update();
    
    glm::vec3 GetRotation();
    glm::vec3 GetScale();
    glm::vec3 GetPosition();

    PrimitiveShape()
    {
        scale = glm::vec3(1, 1, 1);
        position = glm::vec3(0, 0, 0);
        rotation = position;
    }

    void setTexture(std::string texName);

protected:
	virtual void draw();
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    std::string texture;
};