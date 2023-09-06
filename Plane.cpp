#include "Plane.h"


void Plane::drawGeometry()
{
    glBegin(GL_QUADS); {
        //bottom face
        glTexCoord2f(0, 0);
        glVertex3f(-1, -1, -1);

        glTexCoord2f(1, 0);
        glVertex3f(1, -1, -1);

        glTexCoord2f(1, 1);
        glVertex3f(1, -1, 1);

        glTexCoord2f(0, 1);
        glVertex3f(-1, -1, 1);
    }
    glEnd();
}