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
	
		gfx.DrawRect(pos.x, pos.y, pos.x + width, pos.y + height, color);
	
}

void Paddle::BallBounced(Ball & ball)
{
	
		if (ball.GetRec().right > pos.x && ball.GetRec().left < pos.x+width && (ball.GetRec().bottom > pos.y && ball.GetRec().top < pos.y+height)
			&& pos.y < ball.GetRec().top&& pos.y + height>ball.GetRec().bottom)
		{
			ball.reboundx();
			
			
		}
		
		if (ball.GetRec().bottom > pos.y && ball.GetRec().top < pos.y + height && (ball.GetRec().right > pos.x && ball.GetRec().left < pos.x + width)
			&& ball.GetRec().left>pos.x&&ball.GetRec().right < pos.x + width)
		{
			ball.reboundy();
			
			
		}
		
}
