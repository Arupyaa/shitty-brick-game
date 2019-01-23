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
		if (ball.GetRec().right > rec.left && (ball.GetRec().bottom > rec.top && ball.GetRec().top < rec.bottom))
		{
			ball.reboundx();
			//ball.pos.x -= ball.GetRec().right - rec.right;
			smashed = true;
		}
		else if (ball.GetRec().left < rec.right && (ball.GetRec().bottom > rec.top && ball.GetRec().top < rec.bottom))
		{
			ball.reboundx();
			//ball.pos.x += rec.left - ball.GetRec().left;
			smashed = true;
		}
		if (ball.GetRec().bottom > rec.top && (ball.GetRec().right > rec.left && ball.GetRec().left < rec.right))
		{
			ball.reboundy();
			//ball.pos.y -= ball.GetRec().bottom - rec.bottom;
			smashed = true;
		}
		else if (ball.GetRec().top < rec.bottom && (ball.GetRec().right > rec.left && ball.GetRec().left < rec.right))
		{
			ball.reboundy();
			//ball.pos.y += rec.top - ball.GetRec().top;
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
