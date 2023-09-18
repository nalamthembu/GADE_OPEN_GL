#pragma once
#include <vector>
#include "GL/glew.h"
#include "glm/glm.hpp"
#include "stb/stb_image.h"
#include "Texture.h"
using namespace glm;

class Terrain
{
	int width, height, nChannels;
	unsigned char* data;
    std::vector<glm::vec3> vertices;
    std::vector<int> triangles;
    glm::vec3 position = vec3(0,0,0);
    std::vector<vec3> colours;
    
public:
    
    void SetPosition(glm::vec3 pos)
    {
        this->position = pos;
    }

    Terrain(const char* path)
    {
        data = stbi_load(path, &width, &height, &nChannels, 0);

        position = vec3(0, 0, 0);

        std::cout << "Terrain Width : " << width << "\nTerrain Height : " << height << std::endl;

        //Vertex Generation
        float yScale = 64.0f / 256.0f, yShift = 16.0f;  // apply a scale+shift to the height data
        for (unsigned int i = 0; i < height; i++)
        {
            for (unsigned int j = 0; j < width; j++)
            {
                // retrieve texel for (i,j) tex coord
                unsigned char* texel = data + (j + width * i) * nChannels;
                // raw height at coordinate
                unsigned char y = texel[0];

                // vertex
                float x = (-height / 2.0f + i);        // v.x
                float _y = ((int)y * yScale - yShift); // v.y
                float z = (-width / 2.0f + j);        // v.z

                vec3 vert = vec3(x, _y, z);

                vertices.push_back(vert);

                colours.push_back(vec3(0,vert.y * 25,0));
            }
        }

        stbi_image_free(data);
    }

    void Update()
    {
        glPointSize(2);

        glBegin(GL_POINTS); {

            for (int i = 0; i < vertices.size(); i++)
            {
                float x = vertices.at(i).x + position.x;
                float y = vertices.at(i).y + position.y;
                float z = vertices.at(i).z + position.z;

                float c = colours.at(i).y / 255;

                glColor3f(c, c, c);
                glVertex3f(x, y, z);
            }
        }
        glEnd();

        glBegin(GL_POINTS); {

            for (int i = 0; i < vertices.size(); i++)
            {
                float x = vertices.at(i).x + position.x;
                float y = vertices.at(i).y + position.y;
                float z = vertices.at(i).z + position.z;

                glColor3f(1, 0, 0);
                glVertex3f(x, y, z);
            }
        }
        glEnd();
    }
};