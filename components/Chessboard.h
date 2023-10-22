#pragma once
#include "TextureManager.h"
#include "TextureCube.h"
#include "glm/glm.hpp"

using namespace glm;

class Chessboard
{
	TextureCube* pCubes[100][100];
	TextureCube* border[10][10];
	vec2 position = vec2(0, 0);
	int sizeX, sizeY;
	float randomY = 0;
public:
	Chessboard(int sizeX, int sizeY);
	Chessboard(int sizeX, int sizeY, float minRan, float maxRan);
	void SetPosition(vec2 position);
	vec2 GetPosition();
	vec2 GetSize();
	~Chessboard();
	float GetRandomNumber(float min, float max);
	void Update(TextureManager* texManager);
};