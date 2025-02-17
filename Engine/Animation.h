#pragma once

#include "Graphics.h"
#include "Surface.h"
#include "RectI.h"
#include "Vec2.h"
#include <vector>

class Animation
{
public:
	Animation(int x, int y, int width, int height, int count, float holdTime, const Surface& sprite, Color chorma = Colors::Magenta);
	void Update(float dt);
	void Draw(const Vec2& pos, Graphics& gfx) const;
	void DrawColor(const Vec2& pos, Graphics& gfx, Color c) const;

private:
	void Advance();

private:
	Color chroma;
	const Surface& sprite;
	std::vector<RectI> frames;
	float holdTime;
	int iCurFrame = 0;
	float curFrameTime = 0.0f;
};