#include <iostream>
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "components/Terrain.h"
#include "components/Camera.h"
#include "components/Terrain.h"
#include "components/Chessboard.h"
#include "components/TextureManager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

const int WIDTH = 800;
const int HEIGHT = 600;

void init();
void display();
void initGameObjects();
void cleanUp();
void timer(int);
void CameraCycle(vec3 camPosition);
void specialKeyInput(int key, int x, int y);

vec3 camPositions[3]
{
	vec3(0, 400, -600),
	vec3(50, 50, 5),
	vec3(0, 50, 5),
};


TextureManager* textureManager;
Chessboard* chessboard;
Terrain* terrain;
TextureCube* border[10][10];
Camera* camera;


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GL_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	int windowX = (int)(glutGet(GLUT_SCREEN_WIDTH) - WIDTH) / 2;
	int windowY = (int)(glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) / 2;

	glutInitWindowPosition(windowX, windowY);
	glutInitWindowSize(WIDTH, HEIGHT);

	glutCreateWindow("OpenGL Chess");

	glutDisplayFunc(display);
	glutSpecialFunc(specialKeyInput);
	glutTimerFunc(0, timer, 0);

	init();

	glutMainLoop();

	cleanUp();

	return 0;

}

void init()
{

	//Create camera
	camera = new Camera(60, HEIGHT, WIDTH, 1.0, 1000.0F);

	//Where the camera is in 3D space. (world)
	vec3 cameraPosition = vec3(0, 10, -8);

	//The target that the camera is looking at.
	vec3 cameraTarget = vec3(0, 0, 0);
	

	camera->LookAt(cameraPosition, cameraTarget);

	float c = 0.25F;

	camera->SetClearColour(vec4(0, 208.0F/255, 1, 1));

	//Creation of gameObjects.
	initGameObjects();
}

void initGameObjects()
{
	textureManager = new TextureManager();
	chessboard = new Chessboard(8, 8, 0.5F, 1);
	chessboard->SetPosition(vec2(0,0));
	terrain = new Terrain("Textures/height_map_top_deck.png");
	terrain->SetPosition(vec3(0, -40, 0));
	
	for (int x = 0; x < 10; x++) 
	{

		for (int y = 0; y < 10; y++)
		{
			//Position & centre the Border
			float xPos = x - 4.5;
			float yPos = -0.5;
			float zPos = y - 4.5;

			if (x < 1  || x > 8 ||  y < 1 || y > 8)
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

void cleanUp()
{
	//Garbage Collection.
	delete textureManager;
	delete camera;
	delete chessboard;
	delete terrain;
}

float t; 

void display()
{
	camera->Update();

	#pragma region RENDER_OBJECTS

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++) //Increase the size of the board to 10x10 to include the border
		{
			textureManager->useTexture("gold");
			border[x][y]->draw();

			chessboard->Update(textureManager);
		}
	}

	terrain->Update();

    

	//DONT_RENDER_OBJECTS_PAST_THIS_POINT

	#pragma endregion

	camera->LateUpdate();
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
}

void CameraCycle(vec3 camPosition)
{
	//Create a new camera
	camera = new Camera(60, HEIGHT, WIDTH, 1.0, 1000.0F);

	//Where the camera is in 3D space. (world)
	vec3 cameraPosition = camPosition;

	//The target that the camera is looking at.
	vec3 cameraTarget = vec3(0, 0, 0);

	camera->LookAt(cameraPosition, cameraTarget);
}

int currentPos;

void specialKeyInput(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		currentPos--;
		break;

	case GLUT_KEY_RIGHT:
		currentPos++;
		break;

	}

	if (currentPos > 3)
	{
		currentPos = 0;
	}
	else if (currentPos < 0)
	{
		currentPos = 3;
	}

	CameraCycle(camPositions[currentPos]);

	camera->Update();

	glutPostRedisplay();
}