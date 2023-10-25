#include "Cube.h"

void Cube::draw()
{
    glPushMatrix();

    // Define vertices for the cube
    GLfloat vertices[][3] = {
        {0.0, 0.0, 0.0},
        {sideLength, 0.0, 0.0},
        {sideLength, sideLength, 0.0},
        {0.0, sideLength, 0.0},
        {0.0, 0.0, sideLength},
        {sideLength, 0.0, sideLength},
        {sideLength, sideLength, sideLength},
        {0.0, sideLength, sideLength}
    };

    // Define texture coordinates
    GLfloat texCoords[][2] = {
        {0.0, 0.0},
        {1.0, 0.0},
        {1.0, 1.0},
        {0.0, 1.0}
    };

    // Define vertex indices for the cube's faces
    int faces[][4] = {
        {0, 1, 2, 3}, // Bottom face
        {4, 5, 6, 7}, // Top face
        {0, 1, 5, 4}, // Front face
        {2, 3, 7, 6}, // Back face
        {1, 2, 6, 5}, // Right face
        {0, 3, 7, 4}  // Left face
    };

    for (int i = 0; i < 6; i++) {
        glBegin(GL_QUADS);
        for (int j = 0; j < 4; j++) {
            int vertexIndex = faces[i][j];
            int texCoordIndex = j;

            glTexCoord2fv(texCoords[texCoordIndex]);
            glVertex3fv(vertices[vertexIndex]);
        }
        glEnd();
    }

    glPopMatrix();
};
