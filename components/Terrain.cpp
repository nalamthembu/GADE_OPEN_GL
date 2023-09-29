#include "Terrain.h"
#include "GL/freeglut.h"

Terrain::Terrain(Texture* heightMapTexture, float size, float height)
{
    heightMap = heightMapTexture;
    this->size = size;
    this->height = height;
}

void Terrain::drawGeometry()
{
    float w = heightMap->getWidth();
    float h = heightMap->getHeight();

    glTranslatef(-size / 2.0f, 0, -height / 2.0f);
    for (int y = 0; y < h - 1; y++)
    {
        for (int x = 0; x < w - 1; x++)
        {
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

            glBegin(GL_QUADS);
            {
                glColor3f(p1.r, p1.r, p1.r);
                glVertex3f(vx1, vy1, vz1);

                glColor3f(p2.r, p2.r, p2.r);
                glVertex3f(vx2, vy2, vz2);

                glColor3f(p3.r, p3.r, p3.r);
                glVertex3f(vx3, vy3, vz3);

                glColor3f(p4.r, p4.r, p4.r);
                glVertex3f(vx4, vy4, vz4);

            }
            glEnd();

        }
    }


}