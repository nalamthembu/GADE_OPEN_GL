#pragma once
#include "TextureManager.h"
#include "TextureCube.h"
#include "glm/glm.hpp"

using namespace glm;

class Chessboard
{
	TextureCube* pCubes[100][100];
	vec2 position = vec2(0, 0);
	int sizeX, sizeY;
	float randomY = 0;
public:
	Chessboard(int sizeX, int sizeY);
	Chessboard(int sizeX, int sizeY, float minRan, float maxRan);
	void SetPosition(vec2 position);
	vec2 GetPosition();
	~Chessboard();
	void Update(TextureManager* texManager);
};