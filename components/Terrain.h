#pragma once
#include "GameObject.h"
#include <vector>
#include "GL/glew.h"
#include "glm/glm.hpp"
#include "TextureManager.h"

using namespace glm;

class Terrain : public GameObject
{
public:
	Terrain(Texture* tex, float size, float height);

private:
	int size, height;
	Texture* heightMap;
	void drawGeometry() override;
};