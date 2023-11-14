#include <GL/freeglut.h>

class Light {
public:
    enum LightType { DIRECTIONAL, POINT, SPOT };

    Light(GLenum lightNum, LightType lightType, const GLfloat* position, const GLfloat* ambient, const GLfloat* diffuse, const GLfloat* specular);
    void enable();
    void disable();

private:
    GLenum lightNum;
    LightType lightType;
    GLfloat position[4];
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
};

Light::Light(GLenum lightNum, LightType lightType, const GLfloat* position, const GLfloat* ambient, const GLfloat* diffuse, const GLfloat* specular) {
    this->lightNum = lightNum;
    this->lightType = lightType;

    // Set light properties
    for (int i = 0; i < 4; ++i) {
        this->position[i] = position[i];
        this->ambient[i] = ambient[i];
        this->diffuse[i] = diffuse[i];
        this->specular[i] = specular[i];
    }
}

void Light::enable() {
    glEnable(lightNum);
    glLightfv(lightNum, GL_POSITION, position);
    glLightfv(lightNum, GL_AMBIENT, ambient);
    glLightfv(lightNum, GL_DIFFUSE, diffuse);
    glLightfv(lightNum, GL_SPECULAR, specular);

    switch (lightType) {
    case DIRECTIONAL:
        glLightf(lightNum, GL_SPOT_CUTOFF, 360.0); // Set the cutoff angle for directional light
        break;
    case POINT:
        glLightf(lightNum, GL_SPOT_CUTOFF, 180.0); // Set the cutoff angle for point light
        break;
    case SPOT:
        glLightf(lightNum, GL_SPOT_CUTOFF, 45.0); // Set the cutoff angle for spot light
        break;
    }
}

void Light::disable() {
    glDisable(lightNum);
}