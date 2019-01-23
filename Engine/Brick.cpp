#include "Brick.h"

Brick::Brick(RecF& in_rec, Color c)
	: rec(in_rec),
	color(c)
{
}

void Brick::draw(Graphics& gfx)
{
	gfx.DrawRect(int(rec.left), int(rec.top), int(rec.right), int(rec.bottom), color);
}
