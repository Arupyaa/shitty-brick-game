#include "paddle.h"

Paddle::Paddle(Vec2 & in_pos, Color  c)
	: pos(in_pos),
	color(c),
	pad( pos,width,height)
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
	if (!test) {
		gfx.DrawRect(pos.x, pos.y, pos.x + width, pos.y + height, color);
	}
}

void Paddle::BallBounced(Ball & ball)
{
	
		if (ball.GetRec().right > pad.left && ball.GetRec().left < pad.right && (ball.GetRec().bottom > pad.top && ball.GetRec().top < pad.bottom)
			&& pad.top < ball.GetRec().top&& pad.bottom>ball.GetRec().bottom)
		{
			ball.reboundx();
			test = true;
			
		}
		
		if (ball.GetRec().bottom > pad.top && ball.GetRec().top < pad.bottom && (ball.GetRec().right > pad.left && ball.GetRec().left < pad.right)
			&& ball.GetRec().left>pad.left&&ball.GetRec().right < pad.right)
		{
			ball.reboundy();
			test = true;
			
		}
		
}
