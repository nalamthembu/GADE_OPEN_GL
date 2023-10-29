#pragma region BOILER_INCLUDES

#include <iostream>
#include "PlayerInput.h"
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "components/Terrain.h"
#include "components/Camera.h"
#include "components/Terrain.h"
#include "components/Chessboard.h"
#include "components/TextureManager.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define TINYOBJLOADER_IMPLEMENTATION
#include <tinyobjloader/tiny_obj_loader.h>

#pragma endregion

//CHESS_PIECES
#include "Chesspiece.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"

const int WIDTH = 640;
const int HEIGHT = 480;

void init();
void display();
void initGameObjects();
void cleanUp();
void keyboard(unsigned char key, int x, int y);
void timer(int);

//camera stuff
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void motion(int x, int y);
void mouseWheel(int wheel, int direction, int x, int y);



TextureManager* textureManager;
Chessboard* chessboard;

Terrain* terrain;
Camera camera(800, 600);
PlayerInput* input;
Chesspiece* boardPieces[8][8];

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	int windowX = (int)(glutGet(GLUT_SCREEN_WIDTH) - WIDTH) / 2;
	int windowY = (int)(glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) / 2;

	glutInitWindowPosition(windowX, windowY);
	glutInitWindowSize(WIDTH, HEIGHT);

	glutCreateWindow("OpenGL Chess");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutPassiveMotionFunc(motion);
	glutMouseWheelFunc(mouseWheel);

	glEnable(GL_DEPTH_TEST);

	glutTimerFunc(0, timer, 0);

	init();

	glutMainLoop();

	cleanUp();

	return 0;

}

void init()
{
	//Where the camera is in 3D space. (world)
	vec3 cameraPosition = vec3(0, 10, -8);

	//The target that the camera is looking at.
	vec3 cameraTarget = vec3(0, 0, 0);

	//Creation of gameObjects.
	initGameObjects();

	glClearColor(101 / 225.0F, 196 / 255.0F, 244 / 255.0F, 1);
}

void initGameObjects()
{
	textureManager = new TextureManager();
	chessboard = new Chessboard(textureManager);
	terrain = new Terrain(textureManager->getTexture("Heightmap"), 100, 10);
	terrain->GenerateDisplayList();

	//Place Pieces

	int maxX = 8;
	int maxY = 8;

	for (int x = 0; x < maxX; x++)
	{
		for (int y = 0; y < maxY; y++)
		{
			float xPos = x - 3.5F;
			float yPos = y - 3.5F;
			float height = 1.80F;

			//WHITE_ROOKS
			if (x == 0 && y == 0 || x == maxX - 1 && y == 0)
			{
				boardPieces[x][y] = new Rook(PieceColour::WHITE);

				boardPieces[x][y]->SetPosition(vec3(xPos, height, yPos));
			}

			//BLACK_ROOKS
			if (x == 0 && y == maxY - 1 || x == maxX - 1 && y == maxY - 1)
			{
				boardPieces[x][y] = new Rook(PieceColour::BLACK);

				boardPieces[x][y]->SetPosition(vec3(xPos, height, yPos));
			}

			//WHITE_KNIGHTS
			if (x == 1 && y == 0 || x == maxX - 2 && y == 0)
			{
				boardPieces[x][y] = new Knight(PieceColour::WHITE);

				boardPieces[x][y]->SetPosition(vec3(xPos, height, yPos));
			}

			//BLACK_KNIGHT
			if (x == 1 && y == maxY - 1 || x == maxX - 2 && y == maxY - 1)
			{
				boardPieces[x][y] = new Knight(PieceColour::BLACK);

				boardPieces[x][y]->SetPosition(vec3(xPos, height, yPos));

				boardPieces[x][y]->SetRotation(vec3(0, 180, 0));
			}

			//WHITE_BISHOPS 
			if (x == 2 && y == 0 || x == maxX - 3 && y == 0)
			{
				boardPieces[x][y] = new Bishop(PieceColour::WHITE);

				boardPieces[x][y]->SetPosition(vec3(xPos, height, yPos));
			}

			//BLACK_BISHOP 
			if (x == 2 && y == maxY - 1 || x == maxX - 3 && y == maxY - 1)
			{
				boardPieces[x][y] = new Bishop(PieceColour::BLACK);

				boardPieces[x][y]->SetPosition(vec3(xPos, height, yPos));
			}

			//WHITE_QUEEN
			if (x == 3 && y == 0)
			{
				boardPieces[x][y] = new Queen(PieceColour::WHITE);

				boardPieces[x][y]->SetPosition(vec3(xPos, height, yPos));
			}

			//BLACK_QUEEN
			if (x == 3 && y == maxY - 1)
			{
				boardPieces[x][y] = new Queen(PieceColour::BLACK);

				boardPieces[x][y]->SetPosition(vec3(xPos, height, yPos));
			}

			//BLACK_KING
			if (x == 4 && y == maxY - 1)
			{
				boardPieces[x][y] = new King(PieceColour::BLACK);

				boardPieces[x][y]->SetPosition(vec3(xPos, height, yPos));
			}

			//WHITE_KING
			if (x == 4 && y == 0)
			{
				boardPieces[x][y] = new King(PieceColour::WHITE);

				boardPieces[x][y]->SetPosition(vec3(xPos, height, yPos));
			}
		}
	}

	terrain->setPosition(vec3(0, 3.0F, 0));
}

void cleanUp()
{
	//Garbage Collection.
	delete textureManager;
	delete chessboard;
	delete terrain;
	delete input;
	delete boardPieces;
}

float t; 

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(glm::value_ptr(camera.GetViewMatrix()));

	// Draw your 3D scene here

	chessboard->draw();

	glDisable(GL_TEXTURE_2D);

	textureManager->useTexture("cladding");

	terrain->draw();
	
	int boardXLength = 8;
	int boardYLength = 8;

	glDisable(GL_TEXTURE_2D);

	for (int x = 0; x < boardXLength; x++)
	{
		for (int y = 0; y < boardYLength; y++)
		{
			if (boardPieces[x][y] != NULL)
			{
				if (boardPieces[x][y]->GetColour() == PieceColour::BLACK) {
					textureManager->useTexture("black_marble");
					boardPieces[x][y]->update();
					continue;
				}

				if (boardPieces[x][y]->GetColour() == PieceColour::WHITE) {
					textureManager->useTexture("white_marble");
					boardPieces[x][y]->update();
					continue;
				}
			}
		}
	}

	glutSwapBuffers();
}

#pragma region WINDOW_AND_CONTROLS

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 120, timer, 0);
}

void reshape(int width, int height) 
{
	glViewport(0, 0, width, height);
	camera.ScreenWidth = width;
	camera.ScreenHeight = height;
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(camera.GetProjectionMatrix()));
}

void keyboard(unsigned char key, int x, int y) {
	camera.ProcessInput(key, x, y);
	glutPostRedisplay();
}

void motion(int x, int y) {
	camera.ProcessMouseMovement(x, y);
	glutPostRedisplay();
}

void mouseWheel(int wheel, int direction, int x, int y) {
	camera.ProcessMouseScroll(wheel, direction, x, y);
	glutPostRedisplay();
}

#pragma endregion