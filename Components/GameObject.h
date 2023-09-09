#pragma once
#include "Transform.h"
#include "Behaviour.h"

class GameObject : public Behaviour
{
public:
	Transform* transform;
	GameObject();
	~GameObject();
	void draw();
	virtual void drawGeometry();
	virtual void OnUpdate() override;
};