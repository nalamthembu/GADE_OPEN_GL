#include <GL/freeglut.h>
#include <iostream>
#include "Settings.h"
#include "TextureManager.h"
#include <math.h>
#include "Cube.h"
#include "Camera.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

const int WIDTH = 800;
const int HEIGHT = 600;

void init();
void initGameObjects();
void cleanup();
void display();
void displayGameObjects();
void timer(int);
void Update();

TextureManager* textureManager;
Cube* cubeGO;

Camera* camera;

void init();
void display();
void timer(int);

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GL_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    int windowX = (int)(glutGet(GLUT_SCREEN_WIDTH) - WIDTH) / 2;
    int windowY = (int)(glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) / 2;

    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(windowX, windowY);

    glutCreateWindow("Main Window");

    glutDisplayFunc(display);

    glutTimerFunc(0, timer, 0);

    init();

    glutMainLoop();

    cleanup();

    return 0;
}

void init()
{
    camera = new Camera(60, WIDTH, HEIGHT, 1.0, 1000);

    camera->SetClearColour(0.2, 0.2, 0.2, 1);

    Settings::IsInDebugMode = true;

    initGameObjects();
}

float rotation = 0;
float sinTime = 0;
float ZPos = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    Update();

    glutSwapBuffers();
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
}


#pragma region RENDER_GAMEOBJECTS

void cleanup()
{
    delete textureManager;
    delete cubeGO;
    delete camera;
}

void initGameObjects()
{
    textureManager = new TextureManager;
    cubeGO = new Cube;
    cubeGO->name = "Minecraft_Brick";
    cubeGO->transform->rotation = new Vector3(30, 30, 0);
    std::cout << cubeGO->name;
    camera->transform->position = new Vector3(0, 0, 10);
}


void displayGameObjects()
{
    textureManager->useTexture("brick");
    cubeGO->draw();
    camera->Update();
}

void Update()
{
    displayGameObjects();

    camera->Update();
}

#pragma endregion