#pragma once
#include "GameObject.h"
#include "glm/glm.hpp"

using namespace glm;

class Terrain : public GameObject
{
private:
	vec2 terrainSize = vec2(1, 1);

public:
	void drawGeometry() override;
	void SetTerrainSize(vec2 size);
};