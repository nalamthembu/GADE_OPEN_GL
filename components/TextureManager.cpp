#include "TextureManager.h"
#include <iostream>

using namespace std;

//use game obejct class - extend it to create terrain game object and in there load heigthmap texture 

//add more textures here for applying to 3D models
TextureManager::TextureManager()
{
	textures.insert({ "brick", new Texture("Textures/bricks.png") });
	textures.insert({ "dirt_seamless", new Texture("Textures/dirt_seamless.png") });

	textures.insert({ "planks", new Texture("Textures/spruce_planks.png") });

	textures.insert({ "mossy_bricks", new Texture("Textures/mossy_stone_bricks.png") });

	textures.insert({ "cladding", new Texture("Textures/cladding.png") });

	textures.insert({ "tuff_grass", new Texture("Textures/tough_grass.png") });
	
	textures.insert({ "dirt", new Texture("Textures/dirt.png") });


	textures.insert({ "gold", new Texture("Textures/gold_block.png") });
	textures.insert({ "Heightmap", new Texture("Textures/height_map_top_deck.png",3) });

	textures.insert({ "Heightmap_GTA5", new Texture("Textures/gta5_heightmap.png") });
	textures.insert({ "Colourmap_GTA5", new Texture("Textures/gta5_colourmap.png") });

	textures.insert({ "black_block", new Texture("Textures/black_block.png") });
	textures.insert({ "white_block", new Texture("Textures/white_block.png") });

	textures.insert({ "white_marble", new Texture("Textures/white_marble.png") });
	textures.insert({ "black_marble", new Texture("Textures/black_marble.png") });

	textures.insert({ "chessboard", new Texture("Textures/Chessboard_Texture.png") });


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
	if (!textures.count(textureName))
	{
		cout << "WARNING: Texture does not exist!" << endl;
		return nullptr;
	}

	return textures[textureName];
}
