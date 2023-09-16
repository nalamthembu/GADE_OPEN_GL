#include <iostream>
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "components/Plane.h"
#include "components/Camera.h"
#include "components/Terrain.h"
#include "components/Settings.h"
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
void CameraCycle();
void specialKeyInput(int key, int x, int y);

TextureManager* textureManager;
Chessboard* chessboard;
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

	camera->SetClearColour(vec4(c, c, c, 1));

	//Creation of gameObjects.
	initGameObjects();
}


void initGameObjects()
{
	textureManager = new TextureManager();
	chessboard = new Chessboard(8, 8, 0.25F, 1.5F);
}

void cleanUp()
{
	//Garbage Collection.
	delete textureManager;
	delete camera;
	delete chessboard;
}

float t;

void display()
{
	camera->Update();

	#pragma region RENDER_OBJECTS

	chessboard->Update(textureManager);

	//DONT_RENDER_OBJECTS_PAST_THIS_POINT

#pragma endregion

	camera->LateUpdate();
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
}

void CameraCycle() 
{
	//Where the camera is in 3D space. (world)
	vec3 cameraPosition = vec3(0, 10, -10);

	//The target that the camera is looking at. (Looking at the chessboard)
	vec3 cameraTarget = vec3(0, 0, 0);

	camera->LookAt(cameraPosition, cameraTarget);

	float c = 0.25F;

	camera->SetClearColour(vec4(c, c, c, 1));

	display();

}

void specialKeyInput(int key, int x, int y)
{

	if (key == GLUT_KEY_UP) std::cout << "UpKey" << std::endl;
	if (key == GLUT_KEY_DOWN) std::cout << "DownKey" << std::endl;
	if (key == GLUT_KEY_LEFT) std::cout << "LeftKey" << std::endl;
	if (key == GLUT_KEY_RIGHT) std::cout << "RightKey" << std::endl;

	glutPostRedisplay();
}