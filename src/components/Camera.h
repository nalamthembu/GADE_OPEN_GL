#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera(int screenWidth, int screenHeight)
        : position(glm::vec3(0.0f, 0.0f, 3.0f)),
        front(glm::vec3(0.0f, 0.0f, -1.0f)),
        up(glm::vec3(0.0f, 1.0f, 0.0f)),
        yaw(-90.0f), pitch(0.0f), fov(45.0f) {
        this->screenWidth = screenWidth;
        this->screenHeight = screenHeight;
    }

    glm::mat4 GetViewMatrix() {
        return glm::lookAt(position, position + front, up);
    }

    glm::mat4 GetProjectionMatrix() {
        return glm::perspective(glm::radians(fov), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
    }

    void ProcessInput(unsigned char key, int x, int y) {
        float cameraSpeed = 2.5f;
        if (key == 'w')
            position += cameraSpeed * front;
        if (key == 's')
            position -= cameraSpeed * front;
        if (key == 'a')
            position -= glm::normalize(glm::cross(front, up)) * cameraSpeed;
        if (key == 'd')
            position += glm::normalize(glm::cross(front, up)) * cameraSpeed;
    }

    void ProcessMouseMovement(int x, int y) {
        if (firstMouse) {
            lastX = x;
            lastY = y;
            firstMouse = false;
        }

        float xoffset = x - lastX;
        float yoffset = lastY - y; // Reversed since y-coordinates range from bottom to top
        lastX = x;
        lastY = y;

        xoffset *= 0.05f;
        yoffset *= 0.05f;

        yaw += xoffset;
        pitch += yoffset;

        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;

        UpdateCameraVectors();
    }

    void ProcessMouseScroll(int wheel, int direction, int x, int y) {
        fov -= direction * 2.5f;
        if (fov < 1.0f)
            fov = 1.0f;
        if (fov > 45.0f)
            fov = 45.0f;
    }
    
    void SetScreenWidthAndHeight(int width, int height)
    {
        screenWidth = width;
        screenHeight = height;
    }

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    float yaw;
    float pitch;
    float fov;

    int screenWidth;
    int screenHeight;

    float lastX = 400.0f;
    float lastY = 300.0f;
    bool firstMouse = true;

    void UpdateCameraVectors() {
        glm::vec3 newFront;
        newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        newFront.y = sin(glm::radians(pitch));
        newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        front = glm::normalize(newFront);
    }
};
