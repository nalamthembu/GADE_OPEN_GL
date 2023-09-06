#include "TextureManager.h"
#include "Texture.h"
#include <iostream>

TextureManager::TextureManager()
{
	textures.insert({ "brick", new Texture("Textures/bricks.png") });
	textures.insert({ "gold", new Texture("Textures/gold_block.png") });
}

TextureManager::~TextureManager()
{
	map<string, Texture*>::iterator it;

	for (it = textures.begin(); it != textures.end(); it++)
	{
		delete it->second;
	}
}


void TextureManager::useTexture(string textureName)
{
	if (!textures.count(textureName))
	{
		std::cout << "WARNING : texture does not exist!" << std::endl;
		return;
	}

	Texture* tex = textures[textureName];
	tex->use();
}
