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

void Ball::Iscontained(RecF & walls)
{
	if (GetRec().right>walls.right)
	{
		reboundx();
		pos.x -= GetRec().right - walls.right;
	} else if(GetRec().left < walls.left)
	{
		reboundx();
		pos.x += walls.left - GetRec().left;
	}
	if (GetRec().bottom > walls.bottom)
	{
		reboundy();
		pos.y -= GetRec().bottom - walls.bottom;
	}
	else if (GetRec().top < walls.top)
	{
		reboundy();
		pos.y += walls.top - GetRec().top;
	}
}

void Ball::reboundx()
{
	vel.x = -vel.x;
}

void Ball::reboundy()
{
	vel.y = -vel.y;
}

RecF Ball::GetRec()
{
	return RecF::rec_center(pos,radius,radius);
}
