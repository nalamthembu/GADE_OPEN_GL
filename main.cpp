#include <iostream>
#include <GL/freeglut.h>
#include "components/Camera.h"
#include "components/Settings.h"
#include "components/TextureManager.h"
#include "components/Terrain.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

const int WIDTH = 800;
const int HEIGHT = 600;

void init();
void display();
void initGameObjects();
void cleanUp();
void timer(int);

TextureManager* textureManager;
Camera* camera;

//main method
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
	glutTimerFunc(0, timer, 0);

	init();

	glutMainLoop();

	cleanUp();

	return 0;

}

void init()
{
	camera = new Camera(100.0F, HEIGHT, WIDTH, 1.0, 1000.0F);

	camera->LookAt(vec3(0, 0, 5), vec3(-3,0,0));

	float c = 0.25F;

	camera->SetClearColour(vec4(c, c, c, 1));

	initGameObjects();
}


void initGameObjects()
{
	textureManager = new TextureManager();
}

void cleanUp()
{
	delete textureManager;
	delete camera;
}

float t;

void display()
{
	camera->Update();

	//What to render.

	camera->LateUpdate();
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
}