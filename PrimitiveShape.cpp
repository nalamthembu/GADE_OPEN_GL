#include "PrimitiveShape.h"

void PrimitiveShape::SetRotation(glm::vec3 rotation)
{
	this->rotation = rotation;
}

void PrimitiveShape::SetPosition(glm::vec3 position)
{
	this->position = position;
}

void PrimitiveShape::SetScale(glm::vec3 scale)
{
	this->scale = scale;
}

void PrimitiveShape::update()
{
    //Set POS, ROT, SCALE

    glPushMatrix();

    glTranslated(position.x, position.y, position.z);
    glRotated(rotation.x, 1, 0, 0);
    glRotated(rotation.y, 0, 1, 0);
    glRotated(rotation.z, 0, 0, 1);

    glScaled(scale.x, scale.y, scale.z);

    draw();

    glPopMatrix();
}

glm::vec3 PrimitiveShape::GetRotation()
{
    return rotation;
}

glm::vec3 PrimitiveShape::GetScale()
{
    return scale;
}

glm::vec3 PrimitiveShape::GetPosition()
{
    return position;
}

void PrimitiveShape::draw()
{
    printf("not yet implemented");
}
