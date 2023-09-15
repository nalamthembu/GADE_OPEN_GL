#pragma once
#include <glm/glm.hpp>

//to access vec3 etc.
using namespace glm;

class GameObject
{

	float originSize = 1.0f;

	private:
		vec3 position;
		//method we going to override in sub classes - will chnage what the game object reoresents
		virtual void drawGeometry();
		void drawOrigin();

	public:
		//method for setting position
		void setPosition(float x, float y, float z);
		vec3 getPosition();
		vec3 normalised();
		void draw();
			


};

