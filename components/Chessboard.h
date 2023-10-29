#pragma once
#include "TextureCube.h"
#include "TextureManager.h"
#include <GL/freeglut.h>
#include <iostream>
#include <math.h>

class Chessboard
{
public:
	Chessboard(TextureManager* textureManager);
	~Chessboard();
	void draw();
	vec3 getBoardTile(int x, int y);

private:
	class TextureManager* textureManager;
	TextureCube* textureCube[10][10];
};