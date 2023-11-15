#pragma region BOILER_INCLUDES
#include <GL/glew.h>
#include <iostream>

#include "PlayerInput.h"

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
void initLights();
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
Model* chessboard;
Model* skyBox;
Model* prop_cb_radio;
Model* prop_wooden_table;
Model* weapon_rifle;
Model* weapon_shotgun;
Model* prop_backpack;
Model* prop_ammobox_shotgun;

bool displayFPS = false;

//FPS COUNTER
int fps = 0;
auto lastTime = std::chrono::high_resolution_clock::now();
int frameCount = 0;
double deltaTime = 0;

// Function to update FPS and display it
void updateFPS() {
	auto currentTime = std::chrono::high_resolution_clock::now();
	deltaTime = std::chrono::duration<double, std::milli>(currentTime - lastTime).count() / 1000.0;

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
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(-0.95, 0.9); // Adjusted position to top-left corner
	std::stringstream ss;
	ss << "FPS: " << std::setw(3) << std::setfill(' ') << fps;
	std::string fpsString = ss.str();
	for (char c : fpsString) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
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

	glewInit();

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


	initLights();

	// Enable depth testing
	glEnable(GL_DEPTH_TEST);
}

void initLights()
{
	// Enable lighting
	glEnable(GL_LIGHTING);

	// Create a light
	GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };

	// Create a directional light
	GLfloat directionalLightPosition[] = { 1.0, 1.0, 1.0, 0.0 }; // Directional light from the direction (1, 1, 1)
	Light directionalLight(GL_LIGHT0, Light::DIRECTIONAL, directionalLightPosition, ambient, diffuse, specular);
	directionalLight.enable();

	// Create a spot light
	GLfloat spotLightPosition[] = { -1.0, 5.0, 1.0, 1.0 }; // Positional light at (-1, 0, 1)
	Light spotLight(GL_LIGHT2, Light::SPOT, spotLightPosition, ambient, diffuse, specular);
	spotLight.enable();
}

void initGameObjects()
{
	textureManager = new TextureManager();
	chesspieces_black = new Model("Models", "Chesspieces");
	chesspieces_white = new Model("Models", "Chesspieces");
	chessboard = new Model("Models", "chessboard");
	skyBox = new Model("Models", "Cube");
	skyBox->SetScale(vec3(1, 1, 1) * 1000.0F);

	//Generate Display Lists
	chessboard->GenerateDisplayList();
	chesspieces_white->setRotation(vec3(0, -90, 0));
	chesspieces_black->GenerateDisplayList();
	chesspieces_black->setRotation(vec3(0, 90, 0));


	//Other props

	float customModelScalar = 5.0F;

	vec3 customModelScale = vec3(1, 1, 1) * customModelScalar;

	prop_wooden_table = new Model("Models", "prop_wooden_table");
	prop_wooden_table->GenerateDisplayList();
	prop_wooden_table->SetScale(customModelScale + vec3(4, 0, 8));
	prop_wooden_table->setPosition(vec3(0, -(0.95F * customModelScalar), 0));

	prop_cb_radio = new Model("Models", "prop_cb_radio");
	prop_cb_radio->GenerateDisplayList();
	prop_cb_radio->SetScale(customModelScale);
	prop_cb_radio->setPosition(vec3(4.5F, -0.35F, 4));
	prop_cb_radio->setRotation(vec3(0, -45, 0));
	
	weapon_rifle = new Model("Models", "weapon_rifle");
	weapon_rifle->GenerateDisplayList();
	weapon_rifle->SetScale(customModelScale * 2.0F);
	weapon_rifle->setRotation(vec3(0, 45, 90));
	weapon_rifle->setPosition(vec3(6, -0.35F, -1));

	weapon_shotgun = new Model("Models", "weapon_shotgun");
	weapon_shotgun->GenerateDisplayList();
	weapon_shotgun->SetScale(customModelScale * 2.0F);
	weapon_shotgun->setRotation(vec3(0, 180, 90));
	weapon_shotgun->setPosition(vec3(-4, -0.35F, -1));

	prop_backpack = new Model("Models", "prop_backpack");
	prop_backpack->GenerateDisplayList();
	prop_backpack->SetScale(customModelScale * 2.0F);
	prop_backpack->setRotation(vec3(0, -45, 0));
	prop_backpack->setPosition(vec3(-8, -0.35F, 0));

	prop_ammobox_shotgun = new Model("Models", "prop_ammobox_shotgun");
	prop_ammobox_shotgun->GenerateDisplayList();
	prop_ammobox_shotgun->SetScale(customModelScale);
	prop_ammobox_shotgun->setRotation(vec3(0, -45, 0));
	prop_ammobox_shotgun->setPosition(vec3(-7, -0.35F, 3));
}

void DrawCustomModels()
{
	textureManager->useTexture("cb_radio");

	prop_cb_radio->draw();

	textureManager->useTexture("wooden_table");

	prop_wooden_table->draw();

	textureManager->useTexture("weapon_rifle");

	weapon_rifle->draw();

	textureManager->useTexture("weapon_shotgun");

	weapon_shotgun->draw();

	textureManager->useTexture("prop_backpack");

	prop_backpack->draw();

	textureManager->useTexture("prop_ammobox_shotgun");

	prop_ammobox_shotgun->draw();
}

void cleanUp()
{
	//Garbage Collection.
	delete textureManager;
	delete input;
	delete chesspieces_black;
	delete chesspieces_white;
	delete chessboard;
	delete skyBox;

	//Delete Custom Models
	delete prop_wooden_table;
	delete prop_cb_radio;
	delete weapon_rifle;
	delete weapon_shotgun;
	delete prop_backpack;
	delete prop_ammobox_shotgun;

}

void display() {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(glm::value_ptr(camera.GetViewMatrix()));

	camera.UpdateDeltaTime(deltaTime);
	
	glDisable(GL_LIGHTING);

	textureManager->useTexture("skybox");

	skyBox->draw();

	glEnable(GL_LIGHTING);
	
	// Draw your 3D scene here

	DrawCustomModels();

	textureManager->useTexture("white_marble");

	chesspieces_white->draw();

	textureManager->useTexture("black_marble");

	chesspieces_black->draw();

	textureManager->useTexture("chessboard");

	chessboard->draw();

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