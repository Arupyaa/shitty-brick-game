#pragma once
#include "RecF.h"
#include "Graphics.h"
#include "Ball.h"
class Brick
{
public:
	Brick(RecF& in_rec,Color c);
	void BallHitten(Ball& ball);
	void draw(Graphics& gfx);
	
private:
	RecF rec;
	Color color;
	bool smashed = false;
	
};