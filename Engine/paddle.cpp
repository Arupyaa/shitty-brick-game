#include "paddle.h"

Paddle::Paddle(Vec2& in_pos, Color c)
	: pos(in_pos),
	color(c)
{
}

void Paddle::update(Keyboard & kbd)
{
	
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos += vel;
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos -= vel;
	}
}

void Paddle::Draw(Graphics & gfx)
{
	gfx.DrawRect(pad.left, pad.top, pad.right, pad.bottom, color);
}

void Paddle::BallBounced(Ball& ball)
{
	
		if (ball.GetRec().right >pad.left && ball.GetRec().left <pad.right && ball.GetRec().bottom >pad.top && ball.GetRec().top <pad.bottom
			&&pad.top < ball.GetRec().top&&pad.bottom>ball.GetRec().bottom)
		{
			ball.reboundx();
			
			
		}
		//else if (ball.GetRec().left < rec.right && (ball.GetRec().bottom > rec.top && ball.GetRec().top < rec.bottom))
		//{
		//	ball.reboundx();
		//	//ball.pos.x += rec.left - ball.GetRec().left;
		//	smashed = true;
		//}
		if (ball.GetRec().bottom >pad.top && ball.GetRec().top <pad.bottom &&ball.GetRec().right >pad.left && ball.GetRec().left <pad.right
			&& ball.GetRec().left>pad.left&&ball.GetRec().right <pad.right)
		{
			ball.reboundy();
			
			
		}
		//else if (ball.GetRec().top < rec.bottom && (ball.GetRec().right > rec.left && ball.GetRec().left < rec.right))
		//{
		//	ball.reboundy();
		//	//ball.pos.y += rec.top - ball.GetRec().top;
		//	smashed = true;
		//}
	
}