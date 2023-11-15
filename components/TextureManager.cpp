#include "TextureManager.h"
#include <iostream>

using namespace std;

//use game obejct class - extend it to create terrain game object and in there load heigthmap texture 

//add more textures here for applying to 3D models
TextureManager::TextureManager()
{
	textures.insert({ "brick", new Texture("Textures/bricks.png") });

	textures.insert({ "cladding", new Texture("Textures/cladding.png") });

	textures.insert({ "gold", new Texture("Textures/gold_block.png") });
	
	textures.insert({ "Heightmap", new Texture("Textures/height_map_top_deck.png",3) });


	textures.insert({ "white_marble", new Texture("Textures/white_marble.png") });
	textures.insert({ "black_marble", new Texture("Textures/black_marble.png") });

	textures.insert({ "chessboard", new Texture("Textures/Chessboard_Texture.png") });

	textures.insert({ "skybox", new Texture("Textures/cubemap-cross.jpg") });

	textures.insert({ "cb_radio", new Texture("Textures/cb_radio.png") });

	textures.insert({ "wooden_table", new Texture("Textures/wooden_table.jpg") });

	textures.insert({ "weapon_rifle", new Texture("Textures/weapon_rifle.png") });

	textures.insert({ "weapon_shotgun", new Texture("Textures/shot_gun.png") });

	textures.insert({ "prop_backpack", new Texture("Textures/tex_backpack.png") });

	textures.insert({ "prop_ammobox_shotgun", new Texture("Textures/ammo_box_shotgun.png") });
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
