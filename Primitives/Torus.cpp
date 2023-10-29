#include "Torus.h"

void Torus::draw()
{
    glPushMatrix();

    for (int i = 0; i < rings; i++) {
        float theta0 = 2.0 * M_PI * (static_cast<float>(i) / rings);
        float theta1 = 2.0 * M_PI * (static_cast<float>(i + 1) / rings);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= sides; j++) {
            float phi = 2.0 * M_PI * (static_cast<float>(j) / sides);
            float cosPhi = cos(phi);
            float sinPhi = sin(phi);
            float cosTheta0 = cos(theta0);
            float sinTheta0 = sin(theta0);
            float cosTheta1 = cos(theta1);
            float sinTheta1 = sin(theta1);

            float x0 = (majorRadius + minorRadius * cosPhi) * cosTheta0;
            float y0 = (majorRadius + minorRadius * cosPhi) * sinTheta0;
            float z0 = minorRadius * sinPhi;

            float x1 = (majorRadius + minorRadius * cosPhi) * cosTheta1;
            float y1 = (majorRadius + minorRadius * cosPhi) * sinTheta1;
            float z1 = minorRadius * sinPhi;

            // Calculate texture coordinates
            float s0 = static_cast<float>(j) / sides;
            float s1 = static_cast<float>(j) / sides;
            float t0 = static_cast<float>(i) / rings;
            float t1 = static_cast<float>(i + 1) / rings;

            glTexCoord2f(s0, t0);
            glVertex3f(x0, y0, z0);

            glTexCoord2f(s1, t0);
            glVertex3f(x1, y1, z1);
        }
        glEnd();
    }

    glPopMatrix();
}
