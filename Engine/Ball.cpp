#include "Ball.h"

Ball::Ball(Vec2 & in_pos)
	:
	pos(in_pos)
{
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::update(float dt)
{
	pos += vel* dt;
}
