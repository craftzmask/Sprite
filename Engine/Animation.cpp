#include "Animation.h"
#include "SpriteEffect.h"

Animation::Animation(int x, int y, int width, int height, int count, float holdTime, const Surface& sprite, Color chorma)
	:
	sprite(sprite),
	holdTime(holdTime),
	chroma(chorma)
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
	gfx.DrawSprite(int(pos.x), int(pos.y), frames[iCurFrame], sprite, SpriteEffect::Ghost{ chroma });
}

void Animation::DrawColor(const Vec2& pos, Graphics& gfx, Color c) const
{
	gfx.DrawSprite(int(pos.x), int(pos.y), frames[iCurFrame], sprite, SpriteEffect::Substitution{ chroma, c });
}

void Animation::Advance()
{
	if (++iCurFrame >= frames.size())
	{
		iCurFrame = 0;
	}
}
