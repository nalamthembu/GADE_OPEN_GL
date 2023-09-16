#include "Chessboard.h"
#include "TextureCube.h"
#include "TextureManager.h"

Chessboard::Chessboard(int sizeX, int sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	for (int x = 0; x < this->sizeX; x++)
	{
		for (int y = 0; y < this->sizeY; y++)
		{
			this->pCubes[x][y] = new TextureCube();
			this->pCubes[x][y]->SetScale(vec3(1, 0.15, 1));
			this->pCubes[x][y]->setPosition(vec3(x, 0, y));
		}
	}
}

Chessboard::Chessboard(int sizeX, int sizeY, float minRan, float maxRan)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	for (int x = 0; x < this->sizeX; x++)
	{
		for (int y = 0; y < this->sizeY; y++)
		{
			this->randomY = (rand() % (int)maxRan) + minRan;

			this->pCubes[x][y] = new TextureCube();
			this->pCubes[x][y]->SetScale(vec3(1, randomY, 1));
			this->pCubes[x][y]->setPosition(vec3(x, 0, y));
		}
	}
}

void Chessboard::SetPosition(vec2 position)
{
	this->position = position;
}

vec2 Chessboard::GetPosition()
{
	return this->position;
}

Chessboard::~Chessboard()
{
	for (int x = 0; x < this->sizeX; x++)
	{
		for (int y = 0; y < this->sizeY; y++)
		{
			delete this->pCubes[x][y];
		}
	}
	
	delete pCubes;
}

void Chessboard::Update(TextureManager* texManager)
{
	for (int x = 0; x < this->sizeX; x++)
	{
		for (int y = 0; y < this->sizeY; y++)
		{
			if ((x + y) % 2 == 0)
				texManager->useTexture("black_block");
			else
				texManager->useTexture("white_block");

			pCubes[x][y]->setPosition(vec3(x + position.x, randomY, y + position.y));

			pCubes[x][y]->draw();
		}
	}
}