#pragma once
#include "Graphics.h"
#include "Vec2.h"

class RecF {
public:
	RecF(float in_top, float in_bottom, float in_left, float in_right);
	RecF(Vec2& top_left, float width, float height);
	RecF(Vec2& top_left, Vec2& bottom_right);
	bool IsOverlaped(RecF& other);
	static RecF rec_center(Vec2& center, float half_width, float half_height);
	void Draw(Graphics& gfx, Color c) ;
public:
	float top;
	float right;
	float left;
	float bottom;
};