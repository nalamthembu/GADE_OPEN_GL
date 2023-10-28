#include "Terrain.h"
#include "GL/freeglut.h"

Terrain::Terrain(Texture* heightMapTexture, Texture* colourMapTexture, float size, float height)
{
    heightMap = heightMapTexture;
    colourMap = colourMapTexture;
    this->size = size;
    this->height = height;

    generateGeometry();
}

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

            Pixel p1_c = colourMap->getPixelAt(x, y);
            Pixel p2_c = colourMap->getPixelAt(x + 1, y);
            Pixel p3_c = colourMap->getPixelAt(x + 1, y + 1);
            Pixel p4_c = colourMap->getPixelAt(x, y + 1);

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

            QuadColour colour;

            colour = QuadColour(p1_c * p1.r, p2_c * p2.r, p3_c * p3.r, p4_c * p4.r);

            single_quad.vert1 = Vertex(vx1, vy1, vz1);
            single_quad.vert2 = Vertex(vx2, vy2, vz2);
            single_quad.vert3 = Vertex(vx3, vy3, vz3);
            single_quad.vert4 = Vertex(vx4, vy4, vz4);

            //Save it to the quad vector
            quads.push_back(single_quad);

            //Save it to the colour vector
            colours.push_back(colour);
        }
    }
}


void Terrain::drawGeometry()
{
    glTranslatef(-size / 2.0f, 0, -height / 2.0f);

    for (int i = 0; i < quads.size() - 1; i++)
    {
        glBegin(GL_QUADS);
        {
            glColor3f(colours[i].p1.r, colours[i].p1.g, colours[i].p1.b);
            glVertex3f(quads[i].vert1.x, quads[i].vert1.y, quads[i].vert1.z);

            glColor3f(colours[i].p2.r, colours[i].p2.g, colours[i].p2.b);
            glVertex3f(quads[i].vert2.x, quads[i].vert2.y, quads[i].vert2.z);

            glColor3f(colours[i].p3.r, colours[i].p3.g, colours[i].p3.b);
            glVertex3f(quads[i].vert3.x, quads[i].vert3.y, quads[i].vert3.z);

            glColor3f(colours[i].p4.r, colours[i].p4.g, colours[i].p4.b);
            glVertex3f(quads[i].vert4.x, quads[i].vert4.y, quads[i].vert4.z);
        }
        glEnd();
    }
}


/*
void Terrain::drawGeometry()
{
    float w = heightMap->getWidth();
    float h = heightMap->getHeight();

    glTranslatef(-size / 2.0f, 0, -height / 2.0f);

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

            //COLOURMAP_USAGE

            glBegin(GL_QUADS);
            {
                glVertex3f(vx1, vy1, vz1);

                glVertex3f(vx2, vy2, vz2);

                glVertex3f(vx3, vy3, vz3);

                glVertex3f(vx4, vy4, vz4);

            }
            glEnd();

        }
    }
}
*/