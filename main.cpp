#include <iostream>
#include <GL/freeglut.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

void init()
{
	glClearColor(0.3, 0.3, 0.3, 0);
	gluOrtho2D(0, 1024, 512, 0);
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
	glutMainLoop();

	#pragma endregion

}