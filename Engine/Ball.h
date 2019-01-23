#pragma once
#include "Vec2.h"
#include "SpriteCodex.h"
class Ball
{
public:
	Ball(Vec2& in_pos);
	void Draw(Graphics& gfx) const;
	void update(float dt);
private:
	Vec2 pos;
	Vec2 vel = { 100.0f,100.0f };
	const float radius = 7.0f;
};