#include "TextureCube.h"
#include <GL/freeglut.h>
#include "glm/glm.hpp";

using namespace glm;

void TextureCube::drawGeometry() 
{
    float s = 0.5F;

    glBegin(GL_QUADS); 
    {
        //front face
        glColor3f(1, 1, 1);
        glTexCoord2f(0, 0);
        glVertex3f(-0.5, -0.5, 0.5);

        glTexCoord2f(1, 0);
        glVertex3f(0.5, -0.5, 0.5);

        glTexCoord2f(1, 1);
        glVertex3f(0.5, 0.5, 0.5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.5, 0.5, 0.5);

        //back face
        glTexCoord2f(0, 0);
        glVertex3f(0.5, -0.5, -0.5);

        glTexCoord2f(1, 0);
        glVertex3f(-0.5, -0.5, -0.5);

        glTexCoord2f(1, 1);
        glVertex3f(-0.5, 0.5, -0.5);

        glTexCoord2f(0, 1);
        glVertex3f(0.5, 0.5, -0.5);

        //left face
        glTexCoord2f(0, 0);
        glVertex3f(-0.5, -0.5, -0.5);

        glTexCoord2f(1, 0);
        glVertex3f(-0.5, -0.5, 0.5);

        glTexCoord2f(1, 1);
        glVertex3f(-0.5, 0.5, 0.5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.5, 0.5, -0.5);

        //right face
        glTexCoord2f(0, 0);
        glVertex3f(0.5, -0.5, 0.5);

        glTexCoord2f(1, 0);
        glVertex3f(0.5, -0.5, -0.5);

        glTexCoord2f(1, 1);
        glVertex3f(0.5, 0.5, -0.5);

        glTexCoord2f(0, 1);
        glVertex3f(0.5, 0.5, 0.5);

        //top face
        glTexCoord2f(0, 0);
        glVertex3f(-0.5, 0.5, 0.5);

        glTexCoord2f(1, 0);
        glVertex3f(0.5, 0.5, 0.5);

        glTexCoord2f(1, 1);
        glVertex3f(0.5, 0.5, -0.5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.5, 0.5, -0.5);

        //bottom face
        glTexCoord2f(0, 0);
        glVertex3f(-0.5, -0.5, -0.5);

        glTexCoord2f(1, 0);
        glVertex3f(0.5, -0.5, -0.5);

        glTexCoord2f(1, 1);
        glVertex3f(0.5, -0.5, 0.5);

        glTexCoord2f(0, 1);
        glVertex3f(-0.5, -0.5, 0.5);
    }
    glEnd();
}
