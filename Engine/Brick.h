#pragma once
#include "RecF.h"
#include "Graphics.h"
class Brick
{
public:
	Brick(RecF& in_rec,Color c);
	void draw(Graphics& gfx);
	
private:
	RecF rec;
	Color color;
	
};