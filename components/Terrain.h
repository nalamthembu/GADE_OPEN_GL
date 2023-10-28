#pragma once
#include "GameObject.h"
#include <vector>
#include "GL/glew.h"
#include "glm/glm.hpp"
#include "TextureManager.h"
#include "Quad.h"
#include "QuadColour.h"

using namespace glm;

class Terrain : public GameObject
{
public:
	Terrain(Texture* tex, Texture* colourMapTexture,float size, float height);

private:

	vector<Quad> quads;
	vector<QuadColour> colours;
	int size, height;
	Texture* heightMap;
	Texture* colourMap;
	void drawGeometry() override;
	void generateGeometry();
};