#include "Character.h"

Character::Character(const Vec2& pos, const Surface& sprite)
	:
	sprite(sprite),
	pos(pos)
{
	// Init walking animations
	for (int i = 0; i < (int)Sequence::StandingLeft; i++)
	{
		animations.emplace_back(90, 90 * i, 90, 90, (int)Sequence::StandingLeft, 0.15f, sprite);
	}

	// Init standing animations
	for (int i = (int)Sequence::StandingLeft; i < (int)Sequence::Count; i++)
	{
		animations.emplace_back(0, 90 * (i - (int)Sequence::StandingLeft), 90, 90, 1, 0.15f, sprite);
	}
}

void Character::Update(float dt)
{
	animations[(int)iCurSequence].Update(dt);
	pos += vel * dt;
}

void Character::SetDirection(const Vec2& dir)
{
	if (dir.x > 0.0f)
	{
		iCurSequence = Sequence::WalkingRight;
	}
	else if (dir.x < 0.0f)
	{
		iCurSequence = Sequence::WalkingLeft;
	}
	else if (dir.y > 0.0f)
	{
		iCurSequence = Sequence::WalkingDown;
	}
	else if (dir.y < 0.0f)
	{
		iCurSequence = Sequence::WalkingTop;
	}
	else
	{
		if (vel.x > 0.0f)
		{
			iCurSequence = Sequence::StandingRight;
		}
		else if (vel.x < 0.0f)
		{
			iCurSequence = Sequence::StandingLeft;
		}
		else if (vel.y > 0.0f)
		{
			iCurSequence = Sequence::StandingDown;
		}
		else if (vel.y < 0.0f)
		{
			iCurSequence = Sequence::StandingTop;
		}
	}

	vel = dir * speed;
}

void Character::Draw(Graphics& gfx) const
{
	animations[(int)iCurSequence].Draw(pos, gfx);
}
