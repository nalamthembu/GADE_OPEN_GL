#pragma once
#include "GameObject.h"
#include <vector>
#include "GL/glew.h"
#include "glm/glm.hpp"
#include "TextureManager.h"
#include "Quad.h"
#include "QuadTexCoord.h"

using namespace glm;

class Terrain : public GameObject
{
public:
	Terrain(Texture* tex, float size, float height);

private:

	vector<Quad> quads;
	vector<QuadTexCoord> texCoords;
	int size, height;
	Texture* heightMap;
	float vertexBrightness = 1.25F;
	void drawGeometry() override;
	void generateGeometry();
};