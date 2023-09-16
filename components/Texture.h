#pragma once
#include "Pixel.h"
#include "stb/stb_image.h"

class Texture
{
	public:
		//height map / texture - desired channels = 3 is RGB etc
		Texture(const char* path, int desiredChannels = 4);

		//destructor
		~Texture();

		//use this texture and what we draw after will hahve etxture on it
		void use();
		Pixel getPixelAt(int x, int y);

		//width and height of texture
		int getWidth();
		int getHeight();

	private:
		//storing image data in char array
		unsigned char* image;

		int width;
		int height;
		int channels;
		int desiredChannels;

		//tells us if the image is loaded already
		bool loaded = false;

		//loads texture into memeory
		void loadTexture(const char* path);

};

