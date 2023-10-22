#pragma once
#include <GL/glut.h>
#include <cmath>
#include "glm/glm.hpp"

class PrimitiveShape
{
public:
    void SetRotation(glm::vec3 rotation);
    void SetPosition(glm::vec3 position);
    void SetScale(glm::vec3 scale);
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

protected:
	virtual void draw();
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};