#include "Chessboard.h"
#include "TextureCube.h"
#include "TextureManager.h"
#include <random>
#include "GL/freeglut.h"

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

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			//Position & centre the Border
			float xPos = x - 4.5;
			float yPos = -0.5;
			float zPos = y - 4.5;

			if (x < 1 || x > 8 || y < 1 || y > 8)
			{
				//Creating a border cube
				border[x][y] = new TextureCube();
				border[x][y]->setPosition(vec3(xPos, yPos, zPos));
				border[x][y]->SetScale(vec3(1., 0.25, 1));
			}
			else
			{
				border[x][y] = new TextureCube();
				border[x][y]->setPosition(vec3(xPos, yPos, zPos));
			}
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

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			delete this->border[x][y];
		}
	}

	delete border;
	
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
	glPushMatrix();
	{
		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 10; y++)
			{
				texManager->useTexture("gold");
				border[x][y]->draw();
			}
		}

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
	glPopMatrix();

	glDisable(GL_TEXTURE);
}