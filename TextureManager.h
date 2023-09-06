#include "Texture.h"
#include <map>
#include <string>
#include <stdlib.h>

#pragma once

using namespace std;

class TextureManager
{
public:
	TextureManager();
	~TextureManager();
	void useTexture(string textureName);
private:
	map<string, Texture*> textures;
};