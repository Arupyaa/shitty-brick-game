#include "RecF.h"

RecF::RecF(float in_top, float in_bottom, float in_left, float in_right)
	:
	top(in_top),
	bottom(in_bottom),
	left(in_left),
	right(in_right)
{
}

RecF::RecF(Vec2 & top_left, float width, float height)
	:
	RecF(top_left.y, top_left.y + height, top_left.x, top_left.x + width)
{
	
}

RecF::RecF(Vec2 & top_left, Vec2 & bottom_right)
	:RecF(top_left, bottom_right.x - top_left.x, bottom_right.y - top_left.y)
{
	
}

bool RecF::IsOverlaped(RecF & other)
{
	return bottom >other.top&&
		top<other.bottom&&
		right>other.left&&
		left<other.right;
}

RecF RecF::rec_center(Vec2 & center, float half_width, float half_height)
{
	return RecF(center-Vec2(half_width,half_height), center + Vec2(half_width, half_height));
}

void RecF::Draw(Graphics& gfx,Color c) 
{
	gfx.DrawRect(int (left), int(top), int(right), int(bottom), c);
}
