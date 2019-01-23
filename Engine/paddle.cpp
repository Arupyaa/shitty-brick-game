#include "paddle.h"

Paddle::Paddle(Vec2 & in_pos, Color  c)
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
	gfx.DrawRect(pos.x, pos.y, pos.x + width, pos.y + height, color);
}
