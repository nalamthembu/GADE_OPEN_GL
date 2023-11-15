#pragma once
#include <glm/glm.hpp>

using namespace glm;

class GameObject
{

	float originSize = 1.0f;

	private:
		vec3 position;
		vec3 rotation;
		vec3 scale = vec3(1,1,1);
		virtual void drawGeometry();
		void drawOrigin();
		

protected:
	bool displayListGenerated = false;
	uint32_t displayListId;

	public:
		void GenerateDisplayList();
		void setPosition(vec3 position);
		void setRotation(vec3 rotation);
		void SetScale(vec3 scale);
		vec3 getPosition();
		vec3 normalised();
		void draw();
};

