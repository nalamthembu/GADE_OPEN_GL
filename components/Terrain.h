#pragma once
#include <vector>
#include "GL/glew.h"
#include "stb/stb_image.h"


using namespace glm;

class Terrain
{
	int width, height, nChannels;
	unsigned char* data;

public:
    
	Terrain(const char * path)
	{
		data = stbi_load(path, &width, &height, &nChannels, 0);

        std::cout << "Terrain Width : " << width << "\nTerrain Height : " << height << std::endl;

        std::vector<float> vertices;
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
                vertices.push_back(-height / 2.0f + i);        // v.x
                vertices.push_back((int)y * yScale - yShift); // v.y
                vertices.push_back(-width / 2.0f + j);        // v.z
            }
        }

        stbi_image_free(data);

        // index generation
        std::vector<unsigned int> indices;
        for (unsigned int i = 0; i < height - 1; i++)       // for each row a.k.a. each strip
        {
            for (unsigned int j = 0; j < width; j++)      // for each column
            {
                for (unsigned int k = 0; k < 2; k++)      // for each side of the strip
                {
                    indices.push_back(j + width * (i + k));
                }
            }
        }

        const unsigned int NUM_STRIPS = height - 1;
        const unsigned int NUM_VERTS_PER_STRIP = width * 2;
	}
};