#include <GL/freeglut.h>
#include <iostream>
#include "GameObject.h"
#include "SphereGameObject.h"
#include "Settings.h"
#include "TextureManager.h"
#include "TextureCube.h"
#include "Plane.h"
#include "Camera.h"

//STB
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

//size of window
const int WIDTH = 800;
const int HEIGHT = 600;

//declaring 2 methods - defining methods
void init();
void display();
void initGameObjects();
void cleanUp();
void timer(int);

TextureManager* textureManager;


GameObject* gameobject;
SphereGameObject* sphere;
TextureCube* textureCube;
Plane* plane;
Camera* camera;

//main method
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	//display red, green , blue, pixels
	//glut double = double buffering = gonna use double buffering with window
	//glut depth = depth testing, if something is close to camera it wont cut off - enabling depth testing
	glutInitDisplayMode(GL_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	//sizes of window - to pop up in middle of screen (/2)  
	int windowX = (int)(glutGet(GLUT_SCREEN_WIDTH) - WIDTH) / 2;
	int windowY = (int)(glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) / 2;

	//take 2 variables and set windows to position
	glutInitWindowPosition(windowX, windowY);

	//setting windows size
	glutInitWindowSize(WIDTH, HEIGHT);

	//creating window
	glutCreateWindow("Top Deck Chess");

	//display function on the screen
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

	camera->LookAt(vec3(0, 0, 15), vec3(0, 0, 0));

	initGameObjects();
}


void initGameObjects()
{
	textureManager = new TextureManager();

	gameobject = new GameObject();
	gameobject->setPosition(1, 0, 0);

	sphere = new SphereGameObject();
	sphere->setPosition(-1, 0, 0);

	textureCube = new TextureCube();

	plane = new Plane();
}

void cleanUp()
{
	delete textureManager;
	delete gameobject;
	delete sphere;
	delete textureCube;
	delete plane;
	delete camera;
}

void display()
{
	glPushMatrix();
	{
		//glRotatef(45, 1, 1, 0);
		textureManager->useTexture("gold");
		textureCube->draw();

	}
	glPopMatrix();

	glPushMatrix();
	{
		//glRotatef(45, 1, 1, 0);
		glTranslatef(3, 0, 0);
		textureManager->useTexture("brick");
		textureCube->draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		//glRotatef(45, 1, 1, 0);
		glTranslatef(-3, 0, 0);
		textureManager->useTexture("dirt");
		textureCube->draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		//glRotatef(45, 1, 1, 0);
		glTranslatef(-6, 0, 0);
		textureManager->useTexture("ice");
		textureCube->draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		//setupSecondCamera();
		//glRotatef(45, 1, 1, 0);
		glTranslatef(-9, 0, 0);
		textureManager->useTexture("Heightmap");
		plane->draw();
	}
	glPopMatrix();


	camera->LateUpdate();
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
}