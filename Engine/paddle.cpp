#include "paddle.h"

Paddle::Paddle(Vec2 & in_pos, Color  c)
	: pos(in_pos),
	color(c)
	
{
	
}

void Paddle::update(Keyboard & kbd)
{
	if (!stop_spam)
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
	stop_spam = false;
	pad = RecF(pos, width, height);
}

void Paddle::Draw(Graphics & gfx)
{
	
		gfx.DrawRect(pos.x, pos.y, pos.x + width, pos.y + height, color);
	
}

void Paddle::BallBounced(Ball & ball, Keyboard & kbd)
{
	
		if (
			Vec2(ball.GetRec().left, ball.GetRec().top) == Vec2(pos.x + width, pos.y + height) ||
			Vec2(ball.GetRec().right, ball.GetRec().top) == Vec2(pos.x, pos.y + height) ||
			Vec2(ball.GetRec().right, ball.GetRec().bottom) == Vec2(pos.x, pos.y) ||
			Vec2(ball.GetRec().left, ball.GetRec().bottom) == Vec2(pos.x + width, pos.y)
			)
		{
			ball.reboundx();
			ball.reboundy();
		}

		if (ball.GetRec().right > pad.left && ball.GetRec().left < pad.right && (ball.GetRec().bottom > pad.top && ball.GetRec().top < pad.bottom)
			&& pad.top < ball.GetRec().top&& pad.bottom>ball.GetRec().bottom)
		{
			if (pad.left > ball.GetRec().left)
			{
				ball.pos.x -= ball.GetRec().right - pad.left;
				if (kbd.KeyIsPressed(VK_LEFT))
				{
					ball.pos.x -= vel.x;
					stop_spam = true;
				}
			}
			else if (ball.GetRec().right > pad.right)
			{
				ball.pos.x +=  pad.right - ball.GetRec().left;
				if (kbd.KeyIsPressed(VK_RIGHT))
				{
					ball.pos.x += vel.x;
					stop_spam = true;
				}
			}
			
			ball.reboundx();
			
			
		}
		
		if (ball.GetRec().bottom > pos.y && ball.GetRec().top < pos.y + height && (ball.GetRec().right > pos.x && ball.GetRec().left < pos.x + width)
			&& ball.GetRec().left>pos.x&&ball.GetRec().right < pos.x + width)
		{
			if (pos.y > ball.GetRec().top)
			{
				ball.pos.y -= ball.GetRec().bottom - pos.y;
			}
			else if (ball.GetRec().bottom >pos.y+height)
			{
				ball.pos.y += pos.y + height - ball.GetRec().top;
			}
			ball.reboundy();
			
			
		}
		
}

void Paddle::Iscontained(RecF & walls)
{
	if (pad.right > walls.right)
	{
		
		pos.x += pad.right - walls.right;
	}
	else if (pad.left < walls.left)
	{
		
		pos.x -= walls.left - pad.left;
	}
}
