#include "TextureManager.h"
#include <iostream>

using namespace std;

//use game obejct class - extend it to create terrain game object and in there load heigthmap texture 

//add more textures here for applying to 3D models
TextureManager::TextureManager()
{
	textures.insert({ "brick", new Texture("Textures/bricks.png") });
	textures.insert({ "dirt", new Texture("Textures/dirt.png") });
	textures.insert({ "gold", new Texture("Textures/gold_block.png") });
	textures.insert({ "ice", new Texture("Textures/frosted_ice.png") });
	textures.insert({ "Heightmap", new Texture("Textures/Heightmap.png") });
}

TextureManager::~TextureManager()
{	
	//freeing up memeory to avoid memory leaks
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
		cout << "WARNING: Texture does not exist!" << endl;
		return;
	}

	Texture* tex = textures[textureName];
	tex->use();
}

Texture* TextureManager::getTexture(string textureName)
{
	return textures[textureName];
}
