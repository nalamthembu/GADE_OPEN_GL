#include "Chessboard.h"
#include "TextureCube.h"
#include "TextureManager.h"
#include <random>

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
			this->randomY = GetRandomNumber(minRan, maxRan);

			this->pCubes[x][y] = new TextureCube();
			this->pCubes[x][y]->SetScale(vec3(1, 0, 1));
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

vec2 Chessboard::GetSize()
{
	return vec2(sizeX, sizeY);
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

float Chessboard::GetRandomNumber(float min, float max)
{
	std::random_device randomDev;
	std::uniform_int_distribution<int> unifInt_Dis(min, max);

	return unifInt_Dis(randomDev);
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

			float xPos = x - 3.5;
			float yPos = 0.1;
			float zPos = y - 3.5;

			pCubes[x][y]->setPosition(vec3(xPos, yPos, zPos));

			pCubes[x][y]->draw();
		}
	}
}