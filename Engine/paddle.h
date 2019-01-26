#pragma once
#include "RecF.h"
#include "Keyboard.h"
#include "Ball.h"
class Paddle
{
public:
	Paddle() = default;
	Paddle(Vec2& in_pos,Color c);
	void update(Keyboard& kbd);
	void Draw(Graphics& gfx);
	void BallBounced(Ball& ball, Keyboard & kbd);
	void Iscontained(RecF& walls);
public:
	Vec2 pos;
	Vec2 vel = { 5.0f,0.0f };
	const float width = 50.0f;
	const float height = 25.0f;
	RecF pad ;
	Color color;
	bool stop_spam = false;
	
};