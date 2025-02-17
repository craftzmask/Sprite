#pragma once

#include "Surface.h"
#include "Animation.h"
#include "Vec2.h"
#include "Graphics.h"
#include <vector>

class Character
{
private:
	enum class Sequence
	{
		WalkingLeft,
		WalkingRight,
		WalkingTop,
		WalkingDown,
		StandingLeft,
		StandingRight,
		StandingTop,
		StandingDown,
		Count
	};

public:
	Character(const Vec2& pos, const Surface& sprite);
	void Update(float dt);
	void SetDirection(const Vec2& dir);
	void Draw(Graphics& gfx) const;
	void ActivateEffect();
private:
	static constexpr float effectDuration = 0.045f;
	float effectTime = 0.0f;
	bool effectActive = false;
	const Surface sprite;
	std::vector<Animation> animations;
	Vec2 pos;
	Vec2 vel = { 0.0f, 0.0f };
	float speed = 100.0f;
	Sequence iCurSequence = Sequence::StandingDown;
};