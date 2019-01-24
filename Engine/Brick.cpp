#include "Brick.h"

Brick::Brick(RecF& in_rec, Color c)
	: rec(in_rec),
	color(c)
{
}

void Brick::BallHitten(Ball & ball)
{
	if (!smashed)
	{
		if (
			Vec2(ball.GetRec().left, ball.GetRec().top) == Vec2(rec.right, rec.bottom) ||
			Vec2(ball.GetRec().right, ball.GetRec().top) == Vec2(rec.left, rec.bottom) ||
			Vec2(ball.GetRec().right, ball.GetRec().bottom) == Vec2(rec.left, rec.top) ||
			Vec2(ball.GetRec().left, ball.GetRec().bottom) == Vec2(rec.right, rec.top)
			)
		{
			ball.reboundx();
			ball.reboundy();
			smashed = true;
		}
		if (ball.GetRec().right > rec.left && ball.GetRec().left < rec.right && (ball.GetRec().bottom > rec.top && ball.GetRec().top < rec.bottom)
			&& rec.top < ball.GetRec().top&& rec.bottom>ball.GetRec().bottom)
		{
			ball.reboundx();
			
			smashed = true;
		}
		
		if (ball.GetRec().bottom > rec.top && ball.GetRec().top < rec.bottom && (ball.GetRec().right > rec.left && ball.GetRec().left < rec.right)
			&&ball.GetRec().left>rec.left&&ball.GetRec().right<rec.right)
		{
			ball.reboundy();
			
			smashed = true;
		}
		
	}
}

void Brick::draw(Graphics& gfx)
{
	if (!smashed)
	{
		gfx.DrawRect(int(rec.left), int(rec.top), int(rec.right), int(rec.bottom), color);
	}
}
