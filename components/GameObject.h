#pragma once
#include <glm/glm.hpp>

//to access vec3 etc.
using namespace glm;

class GameObject
{

	float originSize = 1.0f;

	private:
		vec3 position;
		vec3 rotation;
		vec3 scale;
		virtual void drawGeometry();
		void drawOrigin();

	public:
		//method for setting position
		void setPosition(vec3 position);
		void setRotation(vec3 rotation);
		vec3 getPosition();
		vec3 normalised();
		void draw();
			


};

