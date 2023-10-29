#include "Chessboard.h"

Chessboard::Chessboard(TextureManager *textureManager) {
	this->textureManager = textureManager;
}

Chessboard::~Chessboard() {
	delete textureManager;
}

void Chessboard::draw()
{
	for (int x = 0; x < 10; x++) //Increase the size of the board to 10x10 to include the border
	{
		for (int y = 0; y < 10; y++) //Increase the size of the board to 10x10 to include the border
		{
			//Adjust for the board size and border
			//Center the board with the border
			float xPos = x - 4.5;
			float yPos = 1;

			//Center the board with the border
			float zPos = y - 4.5;

			// Check if it's within the border, if not, create a border cube
			if (x < 0 || x > 9 || y < 0 || y > 9)
			{
				//Creating a border cube
				textureCube[x][y] = new TextureCube();
				textureCube[x][y]->setPosition(vec3(xPos, yPos, zPos));

				//Set the scale to 1 (no height change)
				textureCube[x][y]->SetScale(vec3(1, 0.5, 1));
			}
			else
			{
				if (x == 0 || x == 9 || y == 0 || y == 9)
				{
					textureManager->useTexture("mossy_bricks");
				}

				//setting all even numbers to be black and odd to be white
				else if ((x + y) % 2 == 0)
				{
					textureManager->useTexture("black_block");
				}
				else
				{
					textureManager->useTexture("white_block");
				}
				//Creating the inner chessboard cube
				textureCube[x][y] = new TextureCube();
				textureCube[x][y]->setPosition(vec3(xPos, yPos, zPos));
				textureCube[x][y]->draw();

			}
		}
	}
}

vec3 Chessboard::getBoardTile(int x, int y)
{
	return textureCube[x][y]->getPosition();
}
