#pragma once
#include "Vec2.h"
#include "SpriteCodex.h"
#include "RecF.h"
class Ball
{
public:
	Ball(Vec2& in_pos);
	void Draw(Graphics& gfx) const;
	void update(float dt);
	void Iscontained(RecF& walls);
	
	void reboundx();
	void reboundy();
	RecF GetRec();
public:
	Vec2 pos;
	Vec2 vel = { 200.0f,200.0f };
	
	const float radius = 7.0f;
};