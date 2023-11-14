#include <GL/glew.h>
#include <GL/freeglut.h>
#include "stb/stb_image.h"

class Skybox {
public:
    Skybox();
    ~Skybox();
    void loadTexture(const char* filename);
    void draw();

private:
    GLuint skyboxTexture;
};

Skybox::Skybox() {
    glGenTextures(1, &skyboxTexture);
}

Skybox::~Skybox() {
    glDeleteTextures(1, &skyboxTexture);
}

void Skybox::loadTexture(const char* filename) {
    glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxTexture);

    int width, height, channels;
    unsigned char* image = stbi_load(filename, &width, &height, &channels, 3);

    if (!image) {
        std::cerr << "Error loading texture: " << filename << std::endl;
        return;
    }

    // Assuming the cube map layout is arranged in the order: right, left, top, bottom, front, back
    int faceWidth = width / 4;
    int faceHeight = height / 3;

    for (int i = 0; i < 6; ++i) {
        int xOffset = (i % 4) * faceWidth;
        int yOffset = (i / 4) * faceHeight;

        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, faceWidth, faceHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image + (yOffset * width + xOffset) * channels);
    }

    stbi_image_free(image);

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

void Skybox::draw() {
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxTexture);
    glEnable(GL_TEXTURE_CUBE_MAP);

    glBegin(GL_QUADS);

    // Right face
    glTexCoord3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glTexCoord3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glTexCoord3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glTexCoord3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    // Left face
    // Repeat the pattern for the other faces (top, bottom, front, back)

    glEnd();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
}