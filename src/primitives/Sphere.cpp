#include "Sphere.h"

void Sphere::draw()
{
    glPushMatrix();

    float M_PI = 3.15F;

    // Draw the sphere using quad strips
    for (int i = 0; i < stacks; i++) {
        float latitude1 = M_PI * (static_cast<float>(i) / stacks - 0.5);
        float latitude2 = M_PI * (static_cast<float>(i + 1) / stacks - 0.5);
        float sinLat1 = sin(latitude1);
        float cosLat1 = cos(latitude1);
        float sinLat2 = sin(latitude2);
        float cosLat2 = cos(latitude2);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= slices; j++) {
            float longitude = 2.0 * M_PI * (static_cast<float>(j) / slices);
            float sinLong = sin(longitude);
            float cosLong = cos(longitude);

            float x1 = cosLong * cosLat1;
            float y1 = sinLong * cosLat1;
            float z1 = sinLat1;

            float x2 = cosLong * cosLat2;
            float y2 = sinLong * cosLat2;
            float z2 = sinLat2;

            glVertex3f(radius * x1, radius * y1, radius * z1);
            glVertex3f(radius * x2, radius * y2, radius * z2);
        }
        glEnd();
    }

    glPopMatrix();
}