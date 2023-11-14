#pragma region BOILER_INCLUDES
#include <iostream>

#include "PlayerInput.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <sstream>
#include <iomanip>
#include <chrono>

#pragma endregion

#include "components/Camera.h"
#include "components/TextureManager.h"
#include "Light.h"
#include "Model.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include <tinyobjloader/tiny_obj_loader.h>

const int WIDTH = 854;
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

Camera camera(854, 480);
PlayerInput* input;

Model* chesspieces_white;
Model* chesspieces_black;
Model* terrain;
Model* chessboard;

bool displayFPS = false;

//FPS COUNTER
int fps = 0;
auto lastTime = std::chrono::high_resolution_clock::now();
int frameCount = 0;

// Function to update FPS and display it
void updateFPS() {
	auto currentTime = std::chrono::high_resolution_clock::now();
	double deltaTime = std::chrono::duration<double, std::milli>(currentTime - lastTime).count() / 1000.0;

	frameCount++;

	if (deltaTime >= 1.0) {
		fps = static_cast<int>(frameCount / deltaTime);
		frameCount = 0;
		lastTime = currentTime;
	}

	glutPostRedisplay();
}

void drawFPSCounter()
{
	//Disable Lighting for the FPS Counter
	glDisable(GL_LIGHTING);

	// Save the current projection matrix
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

	// Save the current modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	// Draw FPS counter
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(-0.95, 0.9); // Adjusted position to top-left corner
	std::stringstream ss;
	ss << "FPS: " << std::setw(3) << std::setfill(' ') << fps;
	std::string fpsString = ss.str();
	for (char c : fpsString) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
	}

	// Restore the modelview matrix
	glPopMatrix();

	// Restore the projection matrix
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
}

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
	glutIdleFunc(updateFPS);

	glEnable(GL_DEPTH_TEST);

	glutTimerFunc(0, timer, 0);

	init();

	glutMainLoop();

	cleanUp();

	return 0;

}

void init()
{
	//TITLE CONSOLE
	system("title Console");

	//Colour Console
	system("color a");

	//Creation of gameObjects.
	initGameObjects();

	glClearColor(101 / 225.0F, 196 / 255.0F, 244 / 255.0F, 1);

	// Enable lighting
	glEnable(GL_LIGHTING);

	// Create a light
	GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat diffuse_red[] = { 1.0, 0.0, 0.0, 1.0 };

	// Create a directional light
	GLfloat directionalLightPosition[] = { 1.0, 1.0, 1.0, 0.0 }; // Directional light from the direction (1, 1, 1)
	Light directionalLight(GL_LIGHT0, Light::DIRECTIONAL, directionalLightPosition, ambient, diffuse, specular);
	directionalLight.enable();

	// Create a spot light
	GLfloat spotLightPosition[] = { -1.0, 0.0, 1.0, 1.0 }; // Positional light at (-1, 0, 1)
	Light spotLight(GL_LIGHT2, Light::SPOT, spotLightPosition, ambient, diffuse_red, specular);
	spotLight.enable();

	// Enable depth testing
	glEnable(GL_DEPTH_TEST);
}

void initGameObjects()
{
	textureManager = new TextureManager();
	chesspieces_black = new Model("Models", "Chesspieces");
	chesspieces_white = new Model("Models", "Chesspieces");
	chessboard = new Model("Models", "chessboard");
	terrain = new Model("Models", "Terrain");

	//Generate Display Lists
	chessboard->GenerateDisplayList();
	terrain->GenerateDisplayList();
	chesspieces_white->GenerateDisplayList();
	chesspieces_black->GenerateDisplayList();
	chesspieces_black->setRotation(vec3(0, 180, 0));
}

void cleanUp()
{
	//Garbage Collection.
	delete textureManager;
	delete input;
	delete chesspieces_black;
	delete chesspieces_white;
	delete chessboard;
	delete terrain;
}

void display() {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(glm::value_ptr(camera.GetViewMatrix()));

	//Lighting

	glEnable(GL_LIGHTING);
	
	// Draw your 3D scene here

	textureManager->useTexture("white_marble");

	chesspieces_white->draw();

	textureManager->useTexture("black_marble");

	chesspieces_black->draw();

	textureManager->useTexture("chessboard");

	chessboard->draw();

	//textureManager->useTexture("cladding");

	//terrain->draw();

	if (displayFPS)
		drawFPSCounter();

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

void keyboard(unsigned char key, int x, int y) 
{

	camera.ProcessInput(key, x, y);

	if (key == 27)
		displayFPS = !displayFPS;

	cout << key;

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