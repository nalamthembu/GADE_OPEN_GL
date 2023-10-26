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

	glClearColor(0, 12/225.0f, 82/225.0f, 1);
}

void initGameObjects()
{
	textureManager = new TextureManager();
	chessboard = new Chessboard(8, 8, 0.5F, 1);
	chessboard->SetPosition(vec2(0, 0));
	terrain = new Terrain(textureManager->getTexture("Heightmap"), 100, 5);
	terrain->GenerateDisplayList();

	//Place Pieces

	int boardXLength = 8;
	int boardYLength = 8;

	for (int x = 0; x < boardXLength; x++)
	{
		for (int y = 0; y < boardYLength; y++)
		{

#pragma region PLACE_WHITE_PIECES

			//Place W Rooks
			if (x == 0 && y == boardYLength - 1|| x == boardXLength - 1 && y == boardYLength - 1)
			{
				boardPieces[y][x] = new Rook(PieceColour::WHITE);

				boardPieces[y][x]->SetPosition(vec3(y, 0, x));

				continue;
			}

			//Place W Knights

			if (x == 1 && y == boardYLength - 1 || x == boardXLength - 2 && y == boardYLength - 1)
			{
				boardPieces[y][x] = new Knight(PieceColour::WHITE);

				boardPieces[y][x]->SetPosition(vec3(y, 0, x));

				boardPieces[y][x]->SetRotation(vec3(0, -90, 0));

				continue;
			}

			//Place W Bishops
			if (x == 2 && y == boardYLength - 1 || x == boardXLength - 3 && y == boardYLength - 1)
			{
				boardPieces[y][x] = new Bishop(PieceColour::WHITE);

				boardPieces[y][x]->SetPosition(vec3(y, 0, x));

				continue;
			}


			//Place W Kings
			if (x == 3 && y == boardYLength - 1)
			{
				boardPieces[y][x] = new King(PieceColour::WHITE);

				boardPieces[y][x]->SetPosition(vec3(y, 0, x));

				continue;
			}

			//Place W Queens
			if (x == 4 && y == boardYLength - 1)
			{
				boardPieces[y][x] = new Queen(PieceColour::WHITE);

				boardPieces[y][x]->SetPosition(vec3(y, 0, x));

				continue;
			}

			//Place W Pawns

			if (x > 0 && y == boardYLength - 2)
			{
				boardPieces[y][x] = new Pawn(PieceColour::WHITE);

				boardPieces[y][x]->SetPosition(vec3(y, 0, x));

				continue;
			}
#pragma endregion


#pragma region PLACE_BLACK_PIECES



			//Place B Rooks
			if (x == 0 && y == 0 || x == boardXLength - 1 && y == 0)
			{
				boardPieces[y][x] = new Rook(PieceColour::BLACK);

				boardPieces[y][x]->SetPosition(vec3(y, 0, x));

				continue;
			}

			//Place B Knights

			if (x == 1 && y == 0 || x == boardXLength - 2 && y == 0)
			{
				boardPieces[y][x] = new Knight(PieceColour::BLACK);

				boardPieces[y][x]->SetPosition(vec3(y, 0, x));

				boardPieces[y][x]->SetRotation(vec3(0, 90, 0));

				continue;
			}

			//Place B Bishops
			if (x == 2 && y == 0 || x == boardXLength - 3 && y == 0)
			{
				boardPieces[y][x] = new Bishop(PieceColour::BLACK);

				boardPieces[y][x]->SetPosition(vec3(y, 0, x));

				continue;
			}


			//Place B Kings
			if (x == 3 && y == 0)
			{
				boardPieces[y][x] = new King(PieceColour::BLACK);

				boardPieces[y][x]->SetPosition(vec3(y, 0, x));

				continue;
			}

			//Place B Queens
			if (x == 4 && y == 0)
			{
				boardPieces[y][x] = new Queen(PieceColour::BLACK);

				boardPieces[y][x]->SetPosition(vec3(y, 0, x));

				continue;
			}

			//Place B Pawns

			if (x > 0 && x < 2)
			{
				boardPieces[y][x] = new Pawn(PieceColour::BLACK);

				boardPieces[y][x]->SetPosition(vec3(x, 0, y));

				continue;
			}

#pragma endregion
		}
	}
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

	chessboard->Update(textureManager);

	glDisable(GL_TEXTURE_2D);

	terrain->draw();
	
	int boardXLength = 8;
	int boardYLength = 8;

	for (int x = 0; x < boardXLength; x++)
	{
		for (int y = 0; y < boardYLength; y++)
		{
			if (boardPieces[x][y] != NULL)
			{
				boardPieces[x][y]->update();
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