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

TextureManager* textureManager;
Chessboard* chessboard;
Terrain* terrain;
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

	camera->SetClearColour(vec4(.25, .25, .25, 1));

	//Creation of gameObjects.
	initGameObjects();
}

void initGameObjects()
{
	textureManager = new TextureManager();
	chessboard = new Chessboard(8, 8);
	chessboard->SetPosition(vec2(-chessboard->GetSize().x * 0.5F, -chessboard->GetSize().y/ 2.7F));
	terrain = new Terrain("Textures/height_map_top_deck.png");
	terrain->SetPosition(vec3(0, -40, 0));
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

    chessboard->Update(textureManager);

	terrain->draw();

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

void specialKeyInput(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		CameraCycle(vec3(0, 400, -600));
		std::cout << "UpKey" << std::endl;
		break;

	case GLUT_KEY_DOWN:
		CameraCycle(vec3(0, 50, 10));
		std::cout << "DownKey" << std::endl;
		break;

	case GLUT_KEY_LEFT:
		CameraCycle(vec3(-10, 5, -10));
		std::cout << "LeftKey" << std::endl;
		break;

	case GLUT_KEY_RIGHT:
		CameraCycle(vec3(5, 1, -10));
		std::cout << "RightKey" << std::endl;
		break;

	}

	camera->Update();

	glutPostRedisplay();
}