#include "Animation.h"

Animation::Animation(int x, int y, int width, int height, int count, float holdTime, const Surface& sprite, Color chorma)
	:
	sprite(sprite),
	holdTime(holdTime),
	chroma(chroma)
{
	for (int i = 0; i < count; i++)
	{
		frames.emplace_back(x + i * width, x + (i + 1) * width, y, y + height);
	}
}

void Animation::Update(float dt)
{
	curFrameTime += dt;
	while (curFrameTime >= holdTime)
	{
		Advance();
		curFrameTime -= holdTime;
	}
}

void Animation::Draw(const Vec2& pos, Graphics& gfx) const
{
	gfx.DrawSprite(int(pos.x), int(pos.y), frames[iCurFrame], sprite);
}

void Animation::Advance()
{
	if (++iCurFrame >= frames.size())
	{
		iCurFrame = 0;
	}
}
