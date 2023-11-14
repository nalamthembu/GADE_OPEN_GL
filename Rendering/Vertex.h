#pragma once
#include <glm/glm.hpp>
struct Vertex
{
public:
    glm::vec3 position;
    glm::vec3 colour;
    glm::vec3 normal;
    glm::vec2 texCoord;
};