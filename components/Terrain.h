#pragma once
#include "GameObject.h"
#include "glm/glm.hpp"
#include "Texture.h"

using namespace glm;

class Terrain : public GameObject
{
private:
	vec2 size = vec2(1, 1);
	Texture* texture;

public:
	void drawGeometry() override;
	void SetHeightMap(Texture* texture);
	void SetTerrainSize(vec2 size);
};