#pragma once

template<typename T>
class Vec2_
{
public:
	Vec2_::Vec2_(T x_in, T y_in)
		:
		x(x_in),
		y(y_in)
	{
	}

	template<typename S>
	explicit Vec2_(const Vec2_<S>& src)
		:
		x((T) src.x),
		y((T) src.y)
	{}

	Vec2_ Vec2_::operator+(const Vec2_& rhs) const
	{
		return Vec2_(x + rhs.x, y + rhs.y);
	}

	Vec2_& Vec2_::operator+=(const Vec2_& rhs)
	{
		return *this = *this + rhs;
	}

	Vec2_ Vec2_::operator*(T rhs) const
	{
		return Vec2_(x * rhs, y * rhs);
	}

	Vec2_& Vec2_::operator*=(T rhs)
	{
		return *this = *this * rhs;
	}

	Vec2_ Vec2_::operator-(const Vec2_& rhs) const
	{
		return Vec2_(x - rhs.x, y - rhs.y);
	}

	Vec2_& Vec2_::operator-=(const Vec2_& rhs)
	{
		return *this = *this - rhs;
	}

	T Vec2_::GetLength() const
	{
		return std::sqrt(GetLengthSq());
	}

	T Vec2_::GetLengthSq() const
	{
		return x * x + y * y;
	}

	Vec2_& Vec2_::Normalize()
	{
		return *this = GetNormalized();
	}

	Vec2_ Vec2_::GetNormalized() const
	{
		const T len = GetLength();
		if (len != (T)0)
		{
			return *this * (1.0f / len);
		}
		return *this;
	}

public:
	T x;
	T y;
};

typedef Vec2_<float> Vec2;
typedef Vec2_<int> Vei2;