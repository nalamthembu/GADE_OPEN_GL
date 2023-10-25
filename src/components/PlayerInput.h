#pragma once
class PlayerInput
{
public:
	float inputXY[2];
	void Update();
	void ReadInput(int key, int x, int y);

};