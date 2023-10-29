#include "Terrain.h"
#include "GL/freeglut.h"
#include <iostream>

Terrain::Terrain(Texture* heightMapTexture, float size, float height)
{
    heightMap = heightMapTexture;
    this->size = size;
    this->height = height;

    generateGeometry();
}

//THIS METHOD NOW GENERATES AND COLOURS THE TERRAIN
void Terrain::generateGeometry()
{
    float w = heightMap->getWidth();
    float h = heightMap->getHeight();

    for (int y = 0; y < h - 1; y++)
    {
        for (int x = 0; x < w - 1; x++)
        {
            //HEIGHT_MAP_USAGE
            Pixel p1 = heightMap->getPixelAt(x, y);
            Pixel p2 = heightMap->getPixelAt(x + 1, y);
            Pixel p3 = heightMap->getPixelAt(x + 1, y + 1);
            Pixel p4 = heightMap->getPixelAt(x, y + 1);

            float vx1 = static_cast<float>(x) / w * size;
            float vy1 = p1.r * height;
            float vz1 = static_cast<float>(y) / h * size;

            float vx2 = static_cast<float>(x + 1) / w * size;
            float vy2 = p2.r * height;
            float vz2 = static_cast<float>(y) / h * size;

            float vx3 = static_cast<float>(x + 1) / w * size;
            float vy3 = p3.r * height;
            float vz3 = static_cast<float>(y + 1) / h * size;

            float vx4 = static_cast<float>(x) / w * size;
            float vy4 = p4.r * height;
            float vz4 = static_cast<float>(y + 1) / h * size;

            //Make a quad
            Quad single_quad;

            single_quad.vert1 = Vertex(vx1, vy1, vz1);
            single_quad.vert2 = Vertex(vx2, vy2, vz2);
            single_quad.vert3 = Vertex(vx3, vy3, vz3);
            single_quad.vert4 = Vertex(vx4, vy4, vz4);

            QuadTexCoord texCoord = QuadTexCoord
            (
                vx1 / size,
                vz1 / size,
                vx2 / size,
                vz2 / size,
                vx3 / size,
                vz3 / size,
                vx4 / size,
                vz4 / size
            );

            //Save it to the quad vector
            quads.push_back(single_quad);

            //Save it to the texCoord vector
            texCoords.push_back(texCoord);

        }
    }
}

void Terrain::drawGeometry()
{
    glTranslatef(-size /2, -height, -size / 2);

    for (int i = 0; i < quads.size() - 1; i++)
    {
        glBegin(GL_QUADS);
        {
            glTexCoord2f(texCoords[i].x1, texCoords[i].y1);
            glVertex3f(quads[i].vert1.x, quads[i].vert1.y, quads[i].vert1.z);

            glTexCoord2f(texCoords[i].x2, texCoords[i].y2);
            glVertex3f(quads[i].vert2.x, quads[i].vert2.y, quads[i].vert2.z);

            glTexCoord2f(texCoords[i].x3, texCoords[i].y3);
            glVertex3f(quads[i].vert3.x, quads[i].vert3.y, quads[i].vert3.z);

            glTexCoord2f(texCoords[i].x4, texCoords[i].y4);
            glVertex3f(quads[i].vert4.x, quads[i].vert4.y, quads[i].vert4.z);
        }
        glEnd();
    }
}