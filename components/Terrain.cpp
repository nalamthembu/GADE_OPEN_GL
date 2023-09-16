#include "Terrain.h"
#include "Texture.h"
#include "TextureManager.h"
#include "GL/freeglut.h"
#include "GLFW/glfw3.h"
#include <vector>

void Terrain::drawGeometry()
{
	std::vector<float> vertices;

	for (int i = 0; i < this->size.y; i++)
	{
		for (int j = 0; j < this->size.x; j++)
		{

		}
	}
}

void Terrain::SetHeightMap(Texture* texture)
{
	this->texture = texture;
}

void Terrain::SetTerrainSize(vec2 size)
{
	this->size = size;
}
