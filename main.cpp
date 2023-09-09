#include <iostream>
#include <GL/freeglut.h>
#include "Components/Camera.h"
#include "Components/Cube.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

int TARGET_FPS = 60;

Camera* camera;
Cube* cube;

float t;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cube->OnUpdate();

	cube->transform->scale = new Vector3(5, 5, 5);

	cube->transform->rotation = new Vector3(30, t, 0);

	t += 1;

	glutSwapBuffers();
}

void init()
{
	camera = new Camera(70, WINDOW_WIDTH, WINDOW_HEIGHT, 0.1F, 1000.0F);
	std::cout << "TARGET FPS : " << TARGET_FPS << std::endl;
	cube = new Cube();
	cube->OnAwake();
	cube->OnStart();
}

void freeMemory()
{
	delete camera;
	delete cube;
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / TARGET_FPS, timer, 0);
}

int main(int argc, char* argv[])
{
	#pragma region INIT_GLUT
	
	//Initialise GLUT and display mode.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	#pragma endregion

	#pragma region WINDOW

	//Initialise Window and place it in the centre of the screen.
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	SCREEN_WIDTH = glutGet(GLUT_SCREEN_WIDTH);
	SCREEN_HEIGHT = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition
	(
		(SCREEN_WIDTH - WINDOW_WIDTH) / 2,
		(SCREEN_HEIGHT - WINDOW_HEIGHT) / 2
	);

	#pragma endregion
		
	#pragma region OTHER_INIT

	//Create the window and run other initialisations.
	glutCreateWindow("TopDeck");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	
	glutMainLoop();

	#pragma endregion

}