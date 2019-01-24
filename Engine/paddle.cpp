#include "paddle.h"

Paddle::Paddle(Vec2 & in_pos, Color  c)
	: pos(in_pos),
	color(c),
	pad( pos,width,height)
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

		if (ball.GetRec().right > pos.x && ball.GetRec().left < pos.x+width && (ball.GetRec().bottom > pos.y && ball.GetRec().top < pos.y+height)
			&& pos.y < ball.GetRec().top&& pos.y + height>ball.GetRec().bottom)
		{
			if (pos.x > ball.GetRec().left)
			{
				ball.pos.x -= ball.GetRec().right - pos.x;
				if (kbd.KeyIsPressed(VK_LEFT))
				{
					ball.pos.x -= vel.x;
					stop_spam = true;
				}
			}
			else if (ball.GetRec().right > pos.x +width)
			{
				ball.pos.x += pos.x + width - ball.GetRec().left;
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
