#pragma once

#include "Colors.h"
#include "Graphics.h"
#include "Surface.h"

namespace SpriteEffect
{
	class Chroma
	{
	public:
		Chroma(Color chroma)
			:
			chroma(chroma)
		{}
		void operator()(Color cSrc, int xDest, int yDest, Graphics& gfx)
		{
			if (cSrc != chroma)
			{
				gfx.PutPixel(xDest, yDest, cSrc);
			}
		}
	private:
		Color chroma;
	};

	class Substitution
	{
	public:
		Substitution(Color chroma, Color subs)
			:
			chroma(chroma),
			subs(subs)
		{
		}
		void operator()(Color src, int xDest, int yDest, Graphics& gfx)
		{
			if (src != chroma)
			{
				gfx.PutPixel(xDest, yDest, subs);
			}
		}
	private:
		Color chroma;
		Color subs;
	};

	class Ghost
	{
	public:
		Ghost(Color chroma)
			:
			chroma(chroma)
		{}
		void operator()(Color src, int xDest, int yDest, Graphics& gfx)
		{
			Color cDest = gfx.GetPixel(xDest, yDest);

			if (src != chroma)
			{
				const Color blendedPixel = {
					unsigned char((cDest.GetR() + src.GetR()) / 2),
					unsigned char((cDest.GetG() + src.GetG()) / 2),
					unsigned char((cDest.GetB() + src.GetB()) / 2)
				};

				gfx.PutPixel(xDest, yDest, blendedPixel);
			}
		}
	private:
		Color chroma;
	};

	class Copy
	{
	public:
		void operator()(Color cSrc, int xDest, int yDest, Graphics& gfx)
		{
			gfx.PutPixel(xDest, yDest, cSrc);
		}
	};
};