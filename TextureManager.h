#pragma once
#include <map>
#include <string>
#include "Texture.h"

using namespace std;

class TextureManager
{
	public:
		//load all textures
		TextureManager();
		//destructor
		~TextureManager();

		//specify which texture to use for what geometry 
		void useTexture(string textureName);

	private:
		//after we load them we store them here
		map<string, Texture*> textures;
};

