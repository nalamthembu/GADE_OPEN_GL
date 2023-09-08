#include <GL/freeglut.h>
#include <math.h>

const int WIDTH = 800;
const int HEIGHT = 640;

void timer(int);
void display();
void init();

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers();
}

void init()
{
    glClearColor(0.3, 0.3, 0.3, 1);
    gluOrtho2D(0, 1024, 512, 0);
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    int windowX = (int)(glutGet(GLUT_SCREEN_WIDTH) - WIDTH) / 2;
    int windowY = (int)(glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) / 2;
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(windowX, windowY);
    glutCreateWindow("Window");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}