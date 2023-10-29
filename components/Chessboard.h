#pragma once
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

private:
	class TextureManager* textureManager;

};