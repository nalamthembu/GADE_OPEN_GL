#pragma once
#include "Transform.h"
#include <string.h>
#include <iostream>

class GameObject
{
private :
	float originSize = 1.0F;
	virtual void drawGeometry();
	void drawOrigin();

public:
	Transform* transform;
	std::string name;
	void draw();
	GameObject(std::string name);
	GameObject();
	~GameObject();
};