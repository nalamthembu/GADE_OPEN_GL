#pragma once
#include "TextureManager.h"
#include "TextureCube.h"

class Chessboard
{
	TextureCube* pCubes[100][100];
	int sizeX, sizeY;
public:
	Chessboard(int sizeX, int sizeY);
	Chessboard(int sizeX, int sizeY, int minRan, int maxRan);
	~Chessboard();
	void Update(TextureManager* texManager);
};