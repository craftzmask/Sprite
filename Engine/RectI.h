#pragma once

#include "Vec2.h"

template<typename T>
class RectI_
{
public:
#include "RectI.h"

	RectI_::RectI_(T left_in, T right_in, T top_in, T bottom_in)
		:
		left(left_in),
		right(right_in),
		top(top_in),
		bottom(bottom_in)
	{
	}

	RectI_::RectI_(const Vei2& topLeft, const Vei2& bottomRight)
		:
		RectI(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
	{
	}

	RectI_::RectI_(const Vei2& topLeft, T width, T height)
		:
		RectI(topLeft, topLeft + Vei2(width, height))
	{
	}

	bool RectI_::IsOverlappingWith(const RectI_& other) const
	{
		return right > other.left && left < other.right
			&& bottom > other.top && top < other.bottom;
	}

	bool RectI_::IsContainedBy(const RectI_& other) const
	{
		return left >= other.left && right <= other.right &&
			top >= other.top && bottom <= other.bottom;
	}

	bool RectI_::Contains(const Vei2& poT) const
	{
		return poT.x >= left && poT.x < right && poT.y >= top && poT.y < bottom;
	}

	RectI_ RectI_::FromCenter(const Vei2& center, T halfWidth, T halfHeight)
	{
		const Vei2 half(halfWidth, halfHeight);
		return RectI(center - half, center + half);
	}

	RectI_ RectI_::GetExpanded(T offset) const
	{
		return RectI(left - offset, right + offset, top - offset, bottom + offset);
	}

	Vei2 RectI_::GetCenter() const
	{
		return Vei2((left + right) / 2, (top + bottom) / 2);
	}

	T RectI_::GetWidth() const
	{
		return right - left;
	}

	T RectI_::GetHeight() const
	{
		return bottom - top;
	}

public:
	T left;
	T right;
	T top;
	T bottom;
};

typedef RectI_<int> RectI;