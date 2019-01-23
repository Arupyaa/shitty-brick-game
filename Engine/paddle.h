#pragma once
#include "RecF.h"
#include "Keyboard.h"
class Paddle
{
public:
	Paddle(Vec2& in_pos,Color c);
	void update(Keyboard& kbd);
	void Draw(Graphics& gfx);
private:
	Vec2 pos;
	Vec2 vel = { 5.0f,0.0f };
	const float width = 50.0f;
	const float height = 25.0f;
	RecF rec = { pos,width,height };
	Color color;
};