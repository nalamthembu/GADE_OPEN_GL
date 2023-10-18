#pragma once
#include "components/GameObject.h"

class Chesspiece : public GameObject
{
private:
	PIECE_COLOUR colour;

public: 
	virtual void Animate();
	Chesspiece(PIECE_COLOUR colour);
};

enum PIECE_COLOUR
{
	BLACK,
	WHITE
};